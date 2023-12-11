#include "firewalld-config-service.h"
#include "firewalld-config-service_p.h"
#include "firewalld-internal.h"
#include "firewalld_dbus.h"
#include "generictypes.h"
#include <qdbusmetatype.h>

firewalld::config::ServicePrivate::ServicePrivate(const QString &path,
                                                  Service *q)
    : uni(path), serviceIface_(firewalld::dbus::kFirewallDDBusService, path,
                               QDBusConnection::systemBus()),
      q_ptr(q) {
  qDBusRegisterMetaType<FWPort>();
  qDBusRegisterMetaType<FWPortList>();
  qDBusRegisterMetaType<FWStringMap>();
}

firewalld::config::ServicePrivate::~ServicePrivate() {}

void firewalld::config::ServicePrivate::init() {
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Removed,
                   this, &ServicePrivate::serviceRemoved);
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Renamed,
                   this, &ServicePrivate::serviceRenamed);
  QObject::connect(&serviceIface_,
                   &OrgFedoraprojectFirewallD1ConfigServiceInterface::Updated,
                   this, &ServicePrivate::serviceUpdated);
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

void firewalld::config::ServicePrivate::serviceRemoved(const QString &name) {
  Q_Q(Service);
  emit q->removed(name);
}
void firewalld::config::ServicePrivate::serviceRenamed(const QString &name) {
  Q_Q(Service);
  emit q->renamed(name);
}
void firewalld::config::ServicePrivate::serviceUpdated(const QString &name) {
  Q_Q(Service);
  emit q->updated(name);
}

void firewalld::config::ServicePrivate::propertyChanged(const QString &property,
                                                     const QVariant &value) {
  Q_Q(Service);

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
void firewalld::config::ServicePrivate::dbusPropertiesChanged(
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

firewalld::config::Service::Service(const QString &path, QObject *parent)
    : QObject(parent), d_ptr(new ServicePrivate(path, this)) {
  Q_D(Service);
  d->init();
}

firewalld::config::Service::~Service() {
  Q_D(Service);
  delete d;
}

bool firewalld::config::Service::builtin() {
  Q_D(const Service);
  return d->builtin;
}

bool firewalld::config::Service::isDefault() {
  Q_D(const Service);
  return d->isDefault;
}

QString firewalld::config::Service::filename() {
  Q_D(const Service);
  return d->filename;
}

QString firewalld::config::Service::name() {
  Q_D(const Service);
  return d->name;
}

QString firewalld::config::Service::path() {
  Q_D(const Service);
  return d->path;
}

QDBusPendingReply<>
firewalld::config::Service::addInclude(const QString &include) {
  Q_D(Service);
  return d->serviceIface_.addInclude(include);
}

QDBusPendingReply<>
firewalld::config::Service::addPort(const QString &port,
                                    const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.addPort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::Service::addProtocol(const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.addProtocol(protocol);
}

QDBusPendingReply<>
firewalld::config::Service::addSourcePort(const QString &port,
                                          const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.addSourcePort(port, protocol);
}

QDBusPendingReply<QString> firewalld::config::Service::getDescription() {
  Q_D(Service);
  return d->serviceIface_.getDescription();
}

QDBusPendingReply<QString>
firewalld::config::Service::getDestination(const QString &family) {
  Q_D(Service);
  return d->serviceIface_.getDestination(family);
}

QDBusPendingReply<FWStringMap> firewalld::config::Service::getDestinations() {
  Q_D(Service);
  return d->serviceIface_.getDestinations();
}

QDBusPendingReply<QStringList> firewalld::config::Service::getIncludes() {
  Q_D(Service);
  return d->serviceIface_.getIncludes();
}

QDBusPendingReply<FWPortList> firewalld::config::Service::getPorts() {
  Q_D(Service);
  return d->serviceIface_.getPorts();
}

QDBusPendingReply<QStringList> firewalld::config::Service::getProtocols() {
  Q_D(Service);
  return d->serviceIface_.getProtocols();
}

QDBusPendingReply<QVariantMap> firewalld::config::Service::getSettings2() {
  Q_D(Service);
  return d->serviceIface_.getSettings2();
}

QDBusPendingReply<QString> firewalld::config::Service::getShort() {
  Q_D(Service);
  return d->serviceIface_.getShort();
}

QDBusPendingReply<FWPortList> firewalld::config::Service::getSourcePorts() {
  Q_D(Service);
  return d->serviceIface_.getSourcePorts();
}

QDBusPendingReply<QString> firewalld::config::Service::getVersion() {
  Q_D(Service);
  return d->serviceIface_.getVersion();
}

QDBusPendingReply<> firewalld::config::Service::loadDefaults() {
  Q_D(Service);
  return d->serviceIface_.loadDefaults();
}

QDBusPendingReply<bool>
firewalld::config::Service::queryDestination(const QString &family,
                                             const QString &address) {
  Q_D(Service);
  return d->serviceIface_.queryDestination(family, address);
}

QDBusPendingReply<bool>
firewalld::config::Service::queryInclude(const QString &include) {
  Q_D(Service);
  return d->serviceIface_.queryInclude(include);
}

QDBusPendingReply<bool>
firewalld::config::Service::queryPort(const QString &port,
                                      const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.queryPort(port, protocol);
}

QDBusPendingReply<bool>
firewalld::config::Service::queryProtocol(const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.queryProtocol(protocol);
}

QDBusPendingReply<bool>
firewalld::config::Service::querySourcePort(const QString &port,
                                            const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.querySourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::Service::remove() {
  Q_D(Service);
  return d->serviceIface_.remove();
}

QDBusPendingReply<>
firewalld::config::Service::removeDestination(const QString &family) {
  Q_D(Service);
  return d->serviceIface_.removeDestination(family);
}

QDBusPendingReply<>
firewalld::config::Service::removeInclude(const QString &include) {
  Q_D(Service);
  return d->serviceIface_.removeInclude(include);
}

QDBusPendingReply<>
firewalld::config::Service::removePort(const QString &port,
                                       const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.removePort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::Service::removeProtocol(const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.removeProtocol(protocol);
}

QDBusPendingReply<>
firewalld::config::Service::removeSourcePort(const QString &port,
                                             const QString &protocol) {
  Q_D(Service);
  return d->serviceIface_.removeSourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::Service::rename(const QString &name) {
  Q_D(Service);
  return d->serviceIface_.rename(name);
}

QDBusPendingReply<>
firewalld::config::Service::setDescription(const QString &description) {
  Q_D(Service);
  return d->serviceIface_.setDescription(description);
}

QDBusPendingReply<>
firewalld::config::Service::setDestination(const QString &family,
                                           const QString &address) {
  Q_D(Service);
  return d->serviceIface_.setDestination(family, address);
}

QDBusPendingReply<>
firewalld::config::Service::setDestinations(FWStringMap destinations) {
  Q_D(Service);
  return d->serviceIface_.setDestinations(destinations);
}

QDBusPendingReply<>
firewalld::config::Service::setIncludes(const QStringList &includes) {
  Q_D(Service);
  return d->serviceIface_.setIncludes(includes);
}

QDBusPendingReply<> firewalld::config::Service::setPorts(FWPortList ports) {
  Q_D(Service);
  return d->serviceIface_.setPorts(ports);
}

QDBusPendingReply<>
firewalld::config::Service::setProtocols(const QStringList &protocols) {
  Q_D(Service);
  return d->serviceIface_.setProtocols(protocols);
}

QDBusPendingReply<>
firewalld::config::Service::setShort(const QString &shortName) {
  Q_D(Service);
  return d->serviceIface_.setShort(shortName);
}

QDBusPendingReply<>
firewalld::config::Service::setSourcePorts(FWPortList ports) {
  Q_D(Service);
  return d->serviceIface_.setSourcePorts(ports);
}

QDBusPendingReply<>
firewalld::config::Service::setVersion(const QString &version) {
  Q_D(Service);
  return d->serviceIface_.setVersion(version);
}

QDBusPendingReply<>
firewalld::config::Service::update2(const QVariantMap &settings) {
  Q_D(Service);
  return d->serviceIface_.update2(settings);
}
