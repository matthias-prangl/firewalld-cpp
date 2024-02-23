#include "firewalld-config-service.h"
#include "firewalld-config-service_p.h"
#include "firewalld-internal.h"
#include "firewalld_dbus.h"
#include "generictypes.h"
#include <qdbusmetatype.h>

firewalld::config::ServiceDBusPrivate::ServiceDBusPrivate(const QString &path,
                                                  ServiceDBus *q)
    : uni(path), serviceIface_(firewalld::dbus::kFirewallDDBusService, path,
                               QDBusConnection::systemBus()),
      q_ptr(q) {
  qDBusRegisterMetaType<FWPort>();
  qDBusRegisterMetaType<FWPortList>();
  qDBusRegisterMetaType<FWStringMap>();
}

firewalld::config::ServiceDBusPrivate::~ServiceDBusPrivate() {}

void firewalld::config::ServiceDBusPrivate::init() {
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Removed,
                   this, &ServiceDBusPrivate::serviceRemoved);
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Renamed,
                   this, &ServiceDBusPrivate::serviceRenamed);
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Updated,
                   this, &ServiceDBusPrivate::serviceUpdated);
  QDBusConnection::systemBus().connect(
      firewalld::dbus::kFirewallDDBusService, uni,
      firewalld::dbus::kDBusPropertiesIface, "PropertiesChanged", this,
      SLOT(dbusPropertiesChanged(QString, QVariantMap, QStringList)));

  QVariantMap initialProps = firewalld::retrieveInitialProperties(
      serviceIface_.staticInterfaceName(), uni);

  if (initialProps.empty()) {
    return;
  }

  for (auto it = initialProps.cbegin(); it != initialProps.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }
}

void firewalld::config::ServiceDBusPrivate::serviceRemoved(const QString &name) {
  Q_Q(ServiceDBus);
  emit q->removed(name);
}
void firewalld::config::ServiceDBusPrivate::serviceRenamed(const QString &name) {
  Q_Q(ServiceDBus);
  emit q->renamed(name);
}
void firewalld::config::ServiceDBusPrivate::serviceUpdated(const QString &name) {
  Q_Q(ServiceDBus);
  emit q->updated(name);
}

void firewalld::config::ServiceDBusPrivate::propertyChanged(const QString &property,
                                                     const QVariant &value) {
  Q_Q(ServiceDBus);

  if (property == "builtin") {
    builtin = value.toBool();
    emit q->builtinChanged(builtin);
  } else if (property == "default") {
    isDefault = value.toBool();
    emit q->isDefaultChanged(isDefault);
  } else if (property == "filename") {
    filename = value.toString();
    emit q->filenameChanged(filename);
  } else if (property == "name") {
    name = value.toString();
    emit q->nameChanged(name);
  } else if (property == "path") {
    path = value.toString();
    emit q->pathChanged(path);
  }
}
void firewalld::config::ServiceDBusPrivate::dbusPropertiesChanged(
    const QString &interfaceName, const QVariantMap &properties,
    const QStringList &invalidatedProperties) {
  Q_UNUSED(invalidatedProperties);
  if (!interfaceName.contains(serviceIface_.staticInterfaceName())) {
    return;
  }

  for (auto it = properties.cbegin(); it != properties.cend(); ++it) {
    propertyChanged(it.key(), it.value());
  }
}

firewalld::config::ServiceDBus::ServiceDBus(const QString &path, QObject *parent)
    : QObject(parent), d_ptr(new ServiceDBusPrivate(path, this)) {
  Q_D(ServiceDBus);
  d->init();
}

firewalld::config::ServiceDBus::~ServiceDBus() {
  Q_D(ServiceDBus);
  delete d;
}

bool firewalld::config::ServiceDBus::builtin() {
  Q_D(const ServiceDBus);
  return d->builtin;
}

bool firewalld::config::ServiceDBus::isDefault() {
  Q_D(const ServiceDBus);
  return d->isDefault;
}

QString firewalld::config::ServiceDBus::filename() {
  Q_D(const ServiceDBus);
  return d->filename;
}

QString firewalld::config::ServiceDBus::name() {
  Q_D(const ServiceDBus);
  return d->name;
}

QString firewalld::config::ServiceDBus::path() {
  Q_D(const ServiceDBus);
  return d->path;
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::addInclude(const QString &include) {
  Q_D(ServiceDBus);
  return d->serviceIface_.addInclude(include);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::addPort(const QString &port,
                                    const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.addPort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::addProtocol(const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.addProtocol(protocol);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::addSourcePort(const QString &port,
                                          const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.addSourcePort(port, protocol);
}

QDBusPendingReply<QString> firewalld::config::ServiceDBus::getDescription() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getDescription();
}

QDBusPendingReply<QString>
firewalld::config::ServiceDBus::getDestination(const QString &family) {
  Q_D(ServiceDBus);
  return d->serviceIface_.getDestination(family);
}

QDBusPendingReply<FWStringMap> firewalld::config::ServiceDBus::getDestinations() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getDestinations();
}

QDBusPendingReply<QStringList> firewalld::config::ServiceDBus::getIncludes() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getIncludes();
}

QDBusPendingReply<FWPortList> firewalld::config::ServiceDBus::getPorts() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getPorts();
}

QDBusPendingReply<QStringList> firewalld::config::ServiceDBus::getProtocols() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getProtocols();
}

QDBusPendingReply<QVariantMap> firewalld::config::ServiceDBus::getSettings2() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getSettings2();
}

QDBusPendingReply<QString> firewalld::config::ServiceDBus::getShort() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getShort();
}

QDBusPendingReply<FWPortList> firewalld::config::ServiceDBus::getSourcePorts() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getSourcePorts();
}

QDBusPendingReply<QString> firewalld::config::ServiceDBus::getVersion() {
  Q_D(ServiceDBus);
  return d->serviceIface_.getVersion();
}

QDBusPendingReply<> firewalld::config::ServiceDBus::loadDefaults() {
  Q_D(ServiceDBus);
  return d->serviceIface_.loadDefaults();
}

QDBusPendingReply<bool>
firewalld::config::ServiceDBus::queryDestination(const QString &family,
                                             const QString &address) {
  Q_D(ServiceDBus);
  return d->serviceIface_.queryDestination(family, address);
}

QDBusPendingReply<bool>
firewalld::config::ServiceDBus::queryInclude(const QString &include) {
  Q_D(ServiceDBus);
  return d->serviceIface_.queryInclude(include);
}

QDBusPendingReply<bool>
firewalld::config::ServiceDBus::queryPort(const QString &port,
                                      const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.queryPort(port, protocol);
}

QDBusPendingReply<bool>
firewalld::config::ServiceDBus::queryProtocol(const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.queryProtocol(protocol);
}

QDBusPendingReply<bool>
firewalld::config::ServiceDBus::querySourcePort(const QString &port,
                                            const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.querySourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::ServiceDBus::remove() {
  Q_D(ServiceDBus);
  return d->serviceIface_.remove();
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::removeDestination(const QString &family) {
  Q_D(ServiceDBus);
  return d->serviceIface_.removeDestination(family);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::removeInclude(const QString &include) {
  Q_D(ServiceDBus);
  return d->serviceIface_.removeInclude(include);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::removePort(const QString &port,
                                       const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.removePort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::removeProtocol(const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.removeProtocol(protocol);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::removeSourcePort(const QString &port,
                                             const QString &protocol) {
  Q_D(ServiceDBus);
  return d->serviceIface_.removeSourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::ServiceDBus::rename(const QString &name) {
  Q_D(ServiceDBus);
  return d->serviceIface_.rename(name);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setDescription(const QString &description) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setDescription(description);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setDestination(const QString &family,
                                           const QString &address) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setDestination(family, address);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setDestinations(FWStringMap destinations) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setDestinations(destinations);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setIncludes(const QStringList &includes) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setIncludes(includes);
}

QDBusPendingReply<> firewalld::config::ServiceDBus::setPorts(FWPortList ports) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setPorts(ports);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setProtocols(const QStringList &protocols) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setProtocols(protocols);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setShort(const QString &shortName) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setShort(shortName);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setSourcePorts(FWPortList ports) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setSourcePorts(ports);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::setVersion(const QString &version) {
  Q_D(ServiceDBus);
  return d->serviceIface_.setVersion(version);
}

QDBusPendingReply<>
firewalld::config::ServiceDBus::update2(const QVariantMap &settings) {
  Q_D(ServiceDBus);
  return d->serviceIface_.update2(settings);
}
