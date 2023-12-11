#include "firewalld-config.h"
#include "firewalld-config_p.h"
#include "firewalld-internal.h"
#include "firewalld_config_interface.h"
#include "firewalld_dbus.h"

firewalld::config::ConfigPrivate::ConfigPrivate(Config *q)
    : configIface_(firewalld::dbus::kFirewallDDBusService,
                   firewalld::dbus::kFirewallDDBusConfigPath,
                   QDBusConnection::systemBus()),
      q_ptr(q) {
  qDBusRegisterMetaType<FWStringMap>();
  qDBusRegisterMetaType<FWIcmpTypeSettings>();
  qDBusRegisterMetaType<FWIPSetSettings>();
}

void firewalld::config::ConfigPrivate::init() {
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::HelperAdded,
                   this, &ConfigPrivate::configHelperAdded);
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::IPSetAdded, this,
                   &ConfigPrivate::configIPSetAdded);
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::IcmpTypeAdded,
                   this, &ConfigPrivate::configIcmpTypeAdded);
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::PolicyAdded,
                   this, &ConfigPrivate::configPolicyAdded);
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::ServiceAdded,
                   this, &ConfigPrivate::configServiceAdded);
  QObject::connect(&configIface_,
                   &OrgFedoraprojectFirewallD1ConfigInterface::ZoneAdded, this,
                   &ConfigPrivate::configZoneAdded);

  QDBusConnection::systemBus().connect(
      firewalld::dbus::kFirewallDDBusService, dbus::kFirewallDDBusConfigPath,
      firewalld::dbus::kDBusPropertiesIface, "PropertiesChanged", this,
      SLOT(dbusPropertiesChanged(QString, QVariantMap, QStringList)));

  QVariantMap initialProps = firewalld::retrieveInitialProperties(
      configIface_.staticInterfaceName(), dbus::kFirewallDDBusConfigPath);

  if (initialProps.empty()) {
    return;
  }

  for (auto it = initialProps.cbegin(); it != initialProps.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }

  if (!configIface_.isValid()) {
    return;
  }
  auto zonesReply = configIface_.listZones();
  zonesReply.waitForFinished();

  if (zonesReply.isError()) {
    return;
  }

  for (const auto &zonePath : zonesReply.value()) {
    const QString &path = zonePath.path();
    zoneMap_.insert(path, QSharedPointer<Zone>::create(path));
  }
}

void firewalld::config::ConfigPrivate::propertyChanged(const QString &property,
                                                       const QVariant &value) {
  Q_Q(Config);

  if (property == "DefaultZone") {
    defaultZone = value.toString();
    emit q->defaultZoneChanged(defaultZone);
  } else if (property == "CleanupOnExit") {
    cleanupOnExit = value.toString();
    emit q->cleanupOnExitChanged(cleanupOnExit);
  } else if (property == "CleanupModulesOnExit") {
    cleanupModulesOnExit = value.toString();
    emit q->cleanupModulesOnExitChanged(cleanupModulesOnExit);
  } else if (property == "Lockdown") {
    lockdown = value.toString();
    emit q->lockdownChanged(lockdown);
  } else if (property == "IPv6_rpfilter") {
    iPv6_rpfilter = value.toString();
    emit q->iPv6_rpfilterChanged(iPv6_rpfilter);
  } else if (property == "IndividualCalls") {
    individualCalls = value.toString();
    emit q->individualCallsChanged(individualCalls);
  } else if (property == "LogDenied") {
    logDenied = value.toString();
    emit q->logDeniedChanged(logDenied);
  } else if (property == "FirewallBackend") {
    firewallBackend = value.toString();
    emit q->firewallBackendChanged(firewallBackend);
  } else if (property == "FlushAllOnReload") {
    flushAllOnReload = value.toString();
    emit q->flushAllOnReloadChanged(flushAllOnReload);
  } else if (property == "RFC3964_IPv4") {
    rFC3964_IPv4 = value.toString();
    emit q->rFC3964_IPv4Changed(rFC3964_IPv4);
  } else if (property == "NftablesFlowtable") {
    nftablesFlowtable = value.toString();
    emit q->nftablesFlowtableChanged(nftablesFlowtable);
  } else if (property == "NftablesCounters") {
    nftablesCounters = value.toString();
    emit q->nftablesCountersChanged(nftablesCounters);
  }
}
void firewalld::config::ConfigPrivate::dbusPropertiesChanged(
    const QString &interfaceName, const QVariantMap &properties,
    const QStringList &invalidatedProperties) {
  Q_UNUSED(invalidatedProperties);
  if (!interfaceName.contains(configIface_.staticInterfaceName())) {
    return;
  }

  for (auto it = properties.cbegin(); it != properties.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }
}

void firewalld::config::ConfigPrivate::configHelperAdded(
    const QString &helper) {
  Q_Q(Config);
  emit q->helperAdded(helper);
}
void firewalld::config::ConfigPrivate::configIPSetAdded(const QString &ipset) {
  Q_Q(Config);
  emit q->ipSetAdded(ipset);
}
void firewalld::config::ConfigPrivate::configIcmpTypeAdded(
    const QString &icmptype) {
  Q_Q(Config);
  emit q->icmpTypeAdded(icmptype);
}
void firewalld::config::ConfigPrivate::configPolicyAdded(
    const QString &policy) {
  Q_Q(Config);
  emit q->policyAdded(policy);
}
void firewalld::config::ConfigPrivate::configServiceAdded(
    const QString &service) {
  Q_Q(Config);
  emit q->serviceAdded(service);
}
void firewalld::config::ConfigPrivate::configZoneAdded(const QString &zone) {
  Q_Q(Config);
  emit q->zoneAdded(zone);
}

firewalld::config::ConfigPrivate::~ConfigPrivate() {}

firewalld::config::Config::Config(QObject *parent)
    : QObject(parent), d_ptr(new ConfigPrivate(this)) {
  Q_D(Config);
  d->init();
}

firewalld::config::Config::~Config() {
  Q_D(Config);
  delete d;
}

const QString firewalld::config::Config::defaultZone() {
  Q_D(const Config);
  return d->defaultZone;
}

const QString firewalld::config::Config::cleanupOnExit() {
  Q_D(const Config);
  return d->cleanupOnExit;
}

const QString firewalld::config::Config::cleanupModulesOnExit() {
  Q_D(const Config);
  return d->cleanupModulesOnExit;
}

const QString firewalld::config::Config::lockdown() {
  Q_D(const Config);
  return d->lockdown;
}

const QString firewalld::config::Config::iPv6_rpfilter() {
  Q_D(const Config);
  return d->iPv6_rpfilter;
}

const QString firewalld::config::Config::individualCalls() {
  Q_D(const Config);
  return d->individualCalls;
}

const QString firewalld::config::Config::logDenied() {
  Q_D(const Config);
  return d->logDenied;
}

const QString firewalld::config::Config::firewallBackend() {
  Q_D(const Config);
  return d->firewallBackend;
}

const QString firewalld::config::Config::flushAllOnReload() {
  Q_D(const Config);
  return d->flushAllOnReload;
}

const QString firewalld::config::Config::rFC3964_IPv4() {
  Q_D(const Config);
  return d->rFC3964_IPv4;
}

const QString firewalld::config::Config::nftablesFlowtable() {
  Q_D(const Config);
  return d->nftablesFlowtable;
}

const QString firewalld::config::Config::nftablesCounters() {
  Q_D(const Config);
  return d->nftablesCounters;
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::addIcmpType(const QString &icmptype,
                                       FWIcmpTypeSettings settings) {
  Q_D(Config);
  return d->configIface_.addIcmpType(icmptype, settings);
}
QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::addIPSet(const QString &ipset,
                                    FWIPSetSettings settings) {
  Q_D(Config);
  return d->configIface_.addIPSet(ipset, settings);
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::addPolicy(const QString &policy,
                                     const QVariantMap &settings) {
  Q_D(Config);
  return d->configIface_.addPolicy(policy, settings);
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::addService2(const QString &service,
                                       const QVariantMap &settings) {
  Q_D(Config);
  return d->configIface_.addService2(service, settings);
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::addZone2(const QString &zone,
                                    const QVariantMap &settings) {
  Q_D(Config);
  return d->configIface_.addZone2(zone, settings);
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getHelperByName(const QString &helper) {
  Q_D(Config);
  return d->configIface_.getHelperByName(helper);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getHelperNames() {
  Q_D(Config);
  return d->configIface_.getHelperNames();
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getIcmpTypeByName(const QString &icmptype) {
  Q_D(Config);
  return d->configIface_.getIcmpTypeByName(icmptype);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getIcmpTypeNames() {
  Q_D(Config);
  return d->configIface_.getIcmpTypeNames();
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getIPSetByName(const QString &ipset) {
  Q_D(Config);
  return d->configIface_.getIPSetByName(ipset);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getIPSetNames() {
  Q_D(Config);
  return d->configIface_.getIPSetNames();
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getPolicyByName(const QString &policy) {
  Q_D(Config);
  return d->configIface_.getPolicyByName(policy);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getPolicyNames() {
  Q_D(Config);
  return d->configIface_.getPolicyNames();
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getServiceByName(const QString &service) {
  Q_D(Config);
  return d->configIface_.getServiceByName(service);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getServiceNames() {
  Q_D(Config);
  return d->configIface_.getServiceNames();
}

QDBusPendingReply<QDBusObjectPath>
firewalld::config::Config::getZoneByName(const QString &zone) {
  Q_D(Config);
  return d->configIface_.getZoneByName(zone);
}

QDBusPendingReply<QStringList> firewalld::config::Config::getZoneNames() {
  Q_D(Config);
  return d->configIface_.getZoneNames();
}

QDBusPendingReply<QString>
firewalld::config::Config::getZoneOfInterface(const QString &iface) {
  Q_D(Config);
  return d->configIface_.getZoneOfInterface(iface);
}

QDBusPendingReply<QString>
firewalld::config::Config::getZoneOfSource(const QString &source) {
  Q_D(Config);
  return d->configIface_.getZoneOfSource(source);
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listHelpers() {
  Q_D(Config);
  return d->configIface_.listHelpers();
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listIcmpTypes() {
  Q_D(Config);
  return d->configIface_.listIcmpTypes();
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listIPSets() {
  Q_D(Config);
  return d->configIface_.listIPSets();
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listPolicies() {
  Q_D(Config);
  return d->configIface_.listPolicies();
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listServices() {
  Q_D(Config);
  return d->configIface_.listServices();
}

QDBusPendingReply<QList<QDBusObjectPath>>
firewalld::config::Config::listZones() {
  Q_D(Config);
  return d->configIface_.listZones();
}
