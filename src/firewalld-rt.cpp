#include "firewalld-rt.h"
#include "firewalld-internal.h"
#include "firewalld-rt_p.h"
#include "firewalld_dbus.h"
#include "firewalld_interface.h"

firewalld::runtime::FirewallDPrivate::FirewallDPrivate(FirewallD *q)
    : firewalldIface_(firewalld::dbus::kFirewallDDBusService,
                      firewalld::dbus::kFirewallDDBusBasePath,
                      QDBusConnection::systemBus()),
      q_ptr(q) {
  qDBusRegisterMetaType<FWPort>();
  qDBusRegisterMetaType<FWPortList>();
  qDBusRegisterMetaType<FWHelperSettings>();
  qDBusRegisterMetaType<FWIcmpTypeSettings>();
}

firewalld::runtime::FirewallDPrivate::~FirewallDPrivate() {}

void firewalld::runtime::FirewallDPrivate::init() {
  QObject::connect(
      &firewalldIface_,
      &OrgFedoraprojectFirewallD1Interface::AutomaticHelpersChanged, this,
      &FirewallDPrivate::firewalldAutomaticHelpersChanged);

  QObject::connect(&firewalldIface_,
                   &OrgFedoraprojectFirewallD1Interface::DefaultZoneChanged,
                   this, &FirewallDPrivate::firewalldDefaultZoneChanged);
  QObject::connect(&firewalldIface_,
                   &OrgFedoraprojectFirewallD1Interface::LogDeniedChanged, this,
                   &FirewallDPrivate::firewalldLogDeniedChanged);
  QObject::connect(&firewalldIface_,
                   &OrgFedoraprojectFirewallD1Interface::PanicModeDisabled,
                   this, &FirewallDPrivate::firewalldPanicModeDisabled);
  QObject::connect(&firewalldIface_,
                   &OrgFedoraprojectFirewallD1Interface::PanicModeEnabled, this,
                   &FirewallDPrivate::firewalldPanicModeEnabled);
  QObject::connect(&firewalldIface_,
                   &OrgFedoraprojectFirewallD1Interface::Reloaded, this,
                   &FirewallDPrivate::firewalldReloaded);

  QDBusConnection::systemBus().connect(
      firewalld::dbus::kFirewallDDBusService, dbus::kFirewallDDBusBasePath,
      firewalld::dbus::kDBusPropertiesIface, "PropertiesChanged", this,
      SLOT(dbusPropertiesChanged(QString, QVariantMap, QStringList)));

  QVariantMap initialProps = firewalld::retrieveInitialProperties(
      firewalldIface_.staticInterfaceName(), dbus::kFirewallDDBusBasePath);

  if (initialProps.empty()) {
    return;
  }

  for (auto it = initialProps.cbegin(); it != initialProps.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }
}

void firewalld::runtime::FirewallDPrivate::firewalldAutomaticHelpersChanged(
    const QString &value) {
  Q_Q(FirewallD);
  emit q->automaticHelpersChanged(value);
}

void firewalld::runtime::FirewallDPrivate::firewalldDefaultZoneChanged(
    const QString &zone) {
  Q_Q(FirewallD);
  emit q->defaultZoneChanged(zone);
}

void firewalld::runtime::FirewallDPrivate::firewalldLogDeniedChanged(
    const QString &value) {
  Q_Q(FirewallD);
  emit q->logDeniedChanged(value);
}

void firewalld::runtime::FirewallDPrivate::firewalldPanicModeDisabled() {
  Q_Q(FirewallD);
  emit q->panicModeDisabled();
}

void firewalld::runtime::FirewallDPrivate::firewalldPanicModeEnabled() {
  Q_Q(FirewallD);
  emit q->panicModeEnabled();
}

void firewalld::runtime::FirewallDPrivate::firewalldReloaded() {
  Q_Q(FirewallD);
  emit q->reloaded();
}

void firewalld::runtime::FirewallDPrivate::propertyChanged(
    const QString &property, const QVariant &value) {
  Q_Q(FirewallD);

  if (property == "BRIDGE") {
    bridge = value.toBool();
    emit q->bridgeChanged(bridge);
  } else if (property == "interface_version") {
    ipSet = value.toBool();
    emit q->ipSetChanged(ipSet);
  } else if (property == "IPSet") {
    ipSetTypes = value.toStringList();
    emit q->ipSetTypesChanged(ipSetTypes);
  } else if (property == "IPSetTypes") {
    ipv4 = value.toBool();
    emit q->ipv4Changed(ipv4);
  } else if (property == "IPv4") {
    ipv4ICMPTypes = value.toStringList();
    emit q->ipv4ICMPTypesChanged(ipv4ICMPTypes);
  } else if (property == "IPv4ICMPTypes") {
    ipv6 = value.toBool();
    emit q->ipv6Changed(ipv6);
  } else if (property == "IPv6") {
    ipv6ICMPTypes = value.toStringList();
    emit q->ipv6ICMPTypesChanged(ipv6ICMPTypes);
  } else if (property == "IPv6ICMPTypes") {
    ipv6_rpfilter = value.toBool();
    emit q->ipv6_rpfilterChanged(ipv6_rpfilter);
  } else if (property == "IPv6_rpfilter") {
    interface_version = value.toString();
    emit q->interface_versionChanged(interface_version);
  } else if (property == "state") {
    state = value.toString();
    emit q->stateChanged(state);
  } else if (property == "version") {
    version = value.toString();
    emit q->versionChanged(version);
  }
}

void firewalld::runtime::FirewallDPrivate::dbusPropertiesChanged(
    const QString &interfaceName, const QVariantMap &properties,
    const QStringList &invalidatedProperties) {
  Q_UNUSED(invalidatedProperties);
  if (!interfaceName.contains(firewalldIface_.staticInterfaceName())) {
    return;
  }

  for (auto it = properties.cbegin(); it != properties.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }
}

firewalld::runtime::FirewallD::FirewallD(QObject *parent)
    : QObject(parent), d_ptr(new FirewallDPrivate(this)) {
  Q_D(FirewallD);
  d->init();
}

firewalld::runtime::FirewallD::~FirewallD() {
  Q_D(FirewallD);
  delete d;
}

bool firewalld::runtime::FirewallD::bridge() {
  Q_D(const FirewallD);
  return d->bridge;
}

bool firewalld::runtime::FirewallD::ipSet() {
  Q_D(const FirewallD);
  return d->ipSet;
}

const QStringList firewalld::runtime::FirewallD::ipSetTypes() {
  Q_D(const FirewallD);
  return d->ipSetTypes;
}

bool firewalld::runtime::FirewallD::ipv4() {
  Q_D(const FirewallD);
  return d->ipv4;
}

const QStringList firewalld::runtime::FirewallD::ipv4ICMPTypes() {
  Q_D(const FirewallD);
  return d->ipv4ICMPTypes;
}

bool firewalld::runtime::FirewallD::ipv6() {
  Q_D(const FirewallD);
  return d->ipv6;
}

const QStringList firewalld::runtime::FirewallD::ipv6ICMPTypes() {
  Q_D(const FirewallD);
  return d->ipv6ICMPTypes;
}

bool firewalld::runtime::FirewallD::ipv6_rpfilter() {
  Q_D(const FirewallD);
  return d->ipv6_rpfilter;
}

const QString firewalld::runtime::FirewallD::interface_version() {
  Q_D(const FirewallD);
  return d->interface_version;
}

const QString firewalld::runtime::FirewallD::state() {
  Q_D(const FirewallD);
  return d->state;
}

const QString firewalld::runtime::FirewallD::version() {
  Q_D(const FirewallD);
  return d->version;
}

QDBusPendingReply<> firewalld::runtime::FirewallD::authorizeAll() {
  Q_D(FirewallD);
  return d->firewalldIface_.authorizeAll();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::checkPermanentConfig() {
  Q_D(FirewallD);
  return d->firewalldIface_.checkPermanentConfig();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::completeReload() {
  Q_D(FirewallD);
  return d->firewalldIface_.completeReload();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::disablePanicMode() {
  Q_D(FirewallD);
  return d->firewalldIface_.disablePanicMode();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::enablePanicMode() {
  Q_D(FirewallD);
  return d->firewalldIface_.enablePanicMode();
}

QDBusPendingReply<QString> firewalld::runtime::FirewallD::getDefaultZone() {
  Q_D(FirewallD);
  return d->firewalldIface_.getDefaultZone();
}

QDBusPendingReply<FWHelperSettings>
firewalld::runtime::FirewallD::getHelperSettings(const QString &helper) {
  Q_D(FirewallD);
  return d->firewalldIface_.getHelperSettings(helper);
}

QDBusPendingReply<QStringList> firewalld::runtime::FirewallD::getHelpers() {
  Q_D(FirewallD);
  return d->firewalldIface_.getHelpers();
}

QDBusPendingReply<FWIcmpTypeSettings>
firewalld::runtime::FirewallD::getIcmpTypeSettings(const QString &icmptype) {
  Q_D(FirewallD);
  return d->firewalldIface_.getIcmpTypeSettings(icmptype);
}

QDBusPendingReply<QString> firewalld::runtime::FirewallD::getLogDenied() {
  Q_D(FirewallD);
  return d->firewalldIface_.getLogDenied();
}

QDBusPendingReply<QVariantMap>
firewalld::runtime::FirewallD::getServiceSettings2(const QString &service) {
  Q_D(FirewallD);
  return d->firewalldIface_.getServiceSettings2(service);
}

QDBusPendingReply<QStringList> firewalld::runtime::FirewallD::listIcmpTypes() {
  Q_D(FirewallD);
  return d->firewalldIface_.listIcmpTypes();
}

QDBusPendingReply<QStringList> firewalld::runtime::FirewallD::listServices() {
  Q_D(FirewallD);
  return d->firewalldIface_.listServices();
}

QDBusPendingReply<bool> firewalld::runtime::FirewallD::queryPanicMode() {
  Q_D(FirewallD);
  return d->firewalldIface_.queryPanicMode();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::reload() {
  Q_D(FirewallD);
  return d->firewalldIface_.reload();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::resetToDefaults() {
  Q_D(FirewallD);
  return d->firewalldIface_.resetToDefaults();
}

QDBusPendingReply<> firewalld::runtime::FirewallD::runtimeToPermanent() {
  Q_D(FirewallD);
  return d->firewalldIface_.runtimeToPermanent();
}

QDBusPendingReply<>
firewalld::runtime::FirewallD::setAutomaticHelpers(const QString &value) {
  Q_D(FirewallD);
  return d->firewalldIface_.setAutomaticHelpers(value);
}

QDBusPendingReply<>
firewalld::runtime::FirewallD::setDefaultZone(const QString &zone) {
  Q_D(FirewallD);
  return d->firewalldIface_.setDefaultZone(zone);
}

QDBusPendingReply<>
firewalld::runtime::FirewallD::setLogDenied(const QString &value) {
  Q_D(FirewallD);
  return d->firewalldIface_.setLogDenied(value);
}
