#include "firewalld-config-zone.h"
#include "firewalld-config-zone_p.h"
#include "firewalld_config_zone_interface.h"
#include "firewalld_dbus.h"
#include <qdbusconnection.h>
#include <qobject.h>

firewalld::config::ZonePrivate::ZonePrivate(const QString &path, Zone *q)
    : zoneIface_(firewalld::dbus::kFirewallDDBusService, path,
                 QDBusConnection::systemBus()),
      q_ptr(q) {
  qWarning() << zoneIface_.isValid();
  qWarning() << zoneIface_.lastError();
}

firewalld::config::Zone::Zone(const QString &path, QObject *parent)
    : QObject(parent), d_ptr(new ZonePrivate(path, this)) {
  Q_D(Zone);
  d->init();
}

void firewalld::config::ZonePrivate::init() {}

firewalld::config::Zone::~Zone() {
  Q_D(Zone);
  delete d;
}

firewalld::config::ZonePrivate::~ZonePrivate() {}

QDBusPendingReply<QString> firewalld::config::Zone::getDescription() {
  Q_D(Zone);
  return d->zoneIface_.getDescription();
}

QDBusPendingReply<QVariantList> firewalld::config::Zone::getForwardPorts() {
  Q_D(Zone);
  return d->zoneIface_.getForwardPorts();
}

QDBusPendingReply<bool> firewalld::config::Zone::getIcmpBlockInversion() {
  Q_D(Zone);
  return d->zoneIface_.getIcmpBlockInversion();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getIcmpBlocks() {
  Q_D(Zone);
  return d->zoneIface_.getIcmpBlocks();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getInterfaces() {
  Q_D(Zone);
  return d->zoneIface_.getInterfaces();
}

QDBusPendingReply<bool> firewalld::config::Zone::getMasquerade() {
  Q_D(Zone);
  return d->zoneIface_.getMasquerade();
}

QDBusPendingReply<FWPortList> firewalld::config::Zone::getPorts() {
  Q_D(Zone);
  return d->zoneIface_.getPorts();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getProtocols() {
  Q_D(Zone);
  return d->zoneIface_.getProtocols();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getRichRules() {
  Q_D(Zone);
  return d->zoneIface_.getRichRules();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getServices() {
  Q_D(Zone);
  return d->zoneIface_.getServices();
}

QDBusPendingReply<QVariantMap> firewalld::config::Zone::getSettings2() {
  Q_D(Zone);
  return d->zoneIface_.getSettings2();
}

QDBusPendingReply<QString> firewalld::config::Zone::getShort() {
  Q_D(Zone);
  return d->zoneIface_.getShort();
}

QDBusPendingReply<QVariantList> firewalld::config::Zone::getSourcePorts() {
  Q_D(Zone);
  return d->zoneIface_.getSourcePorts();
}

QDBusPendingReply<QStringList> firewalld::config::Zone::getSources() {
  Q_D(Zone);
  return d->zoneIface_.getSources();
}

QDBusPendingReply<QString> firewalld::config::Zone::getTarget() {
  Q_D(Zone);
  return d->zoneIface_.getTarget();
}

QDBusPendingReply<QString> firewalld::config::Zone::getVersion() {
  Q_D(Zone);
  return d->zoneIface_.getVersion();
}

QDBusPendingReply<> firewalld::config::Zone::addForwardPort(
    const QString &port, const QString &protocol, const QString &toport,
    const QString &toaddr) {
  Q_D(Zone);
  return d->zoneIface_.addForwardPort(port, protocol, toport, toaddr);
}

QDBusPendingReply<>
firewalld::config::Zone::addIcmpBlock(const QString &icmptype) {
  Q_D(Zone);
  return d->zoneIface_.addIcmpBlock(icmptype);
}

QDBusPendingReply<> firewalld::config::Zone::addIcmpBlockInversion() {
  Q_D(Zone);
  return d->zoneIface_.addIcmpBlockInversion();
}

QDBusPendingReply<>
firewalld::config::Zone::addInterface(const QString &interface) {
  Q_D(Zone);
  return d->zoneIface_.addInterface(interface);
}

QDBusPendingReply<> firewalld::config::Zone::addMasquerade() {
  Q_D(Zone);
  return d->zoneIface_.addMasquerade();
}

QDBusPendingReply<> firewalld::config::Zone::addPort(const QString &port,
                                                     const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.addPort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::Zone::addProtocol(const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.addProtocol(protocol);
}

QDBusPendingReply<> firewalld::config::Zone::addRichRule(const QString &rule) {
  Q_D(Zone);
  return d->zoneIface_.addRichRule(rule);
}

QDBusPendingReply<>
firewalld::config::Zone::addService(const QString &service) {
  Q_D(Zone);
  return d->zoneIface_.addService(service);
}

QDBusPendingReply<> firewalld::config::Zone::addSource(const QString &source) {
  Q_D(Zone);
  return d->zoneIface_.addSource(source);
}

QDBusPendingReply<>
firewalld::config::Zone::addSourcePort(const QString &port,
                                       const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.addSourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::Zone::loadDefaults() {
  Q_D(Zone);
  return d->zoneIface_.loadDefaults();
}

QDBusPendingReply<bool> firewalld::config::Zone::queryForwardPort(
    const QString &port, const QString &protocol, const QString &toport,
    const QString &toaddr) {
  Q_D(Zone);
  return d->zoneIface_.queryForwardPort(port, protocol, toport, toaddr);
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryIcmpBlock(const QString &icmptype) {
  Q_D(Zone);
  return d->zoneIface_.addIcmpBlock(icmptype);
}

QDBusPendingReply<bool> firewalld::config::Zone::queryIcmpBlockInversion() {
  Q_D(Zone);
  return d->zoneIface_.queryIcmpBlockInversion();
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryInterface(const QString &interface) {
  Q_D(Zone);
  return d->zoneIface_.queryInterface(interface);
}

QDBusPendingReply<bool> firewalld::config::Zone::queryMasquerade() {
  Q_D(Zone);
  return d->zoneIface_.queryMasquerade();
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryPort(const QString &port,
                                   const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.queryPort(port, protocol);
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryProtocol(const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.queryProtocol(protocol);
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryRichRule(const QString &rule) {
  Q_D(Zone);
  return d->zoneIface_.queryRichRule(rule);
}

QDBusPendingReply<bool>
firewalld::config::Zone::queryService(const QString &service) {
  Q_D(Zone);
  return d->zoneIface_.queryService(service);
}

QDBusPendingReply<bool>
firewalld::config::Zone::querySource(const QString &source) {
  Q_D(Zone);
  return d->zoneIface_.querySource(source);
}

QDBusPendingReply<bool>
firewalld::config::Zone::querySourcePort(const QString &port,
                                         const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.querySourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::Zone::remove() {
  Q_D(Zone);
  return d->zoneIface_.remove();
}

QDBusPendingReply<> firewalld::config::Zone::removeForwardPort(
    const QString &port, const QString &protocol, const QString &toport,
    const QString &toaddr) {
  Q_D(Zone);
  return d->zoneIface_.removeForwardPort(port, protocol, toport, toaddr);
}

QDBusPendingReply<>
firewalld::config::Zone::removeIcmpBlock(const QString &icmptype) {
  Q_D(Zone);
  return d->zoneIface_.removeIcmpBlock(icmptype);
}

QDBusPendingReply<> firewalld::config::Zone::removeIcmpBlockInversion() {
  Q_D(Zone);
  return d->zoneIface_.removeIcmpBlockInversion();
}

QDBusPendingReply<>
firewalld::config::Zone::removeInterface(const QString &interface) {
  Q_D(Zone);
  return d->zoneIface_.removeInterface(interface);
}

QDBusPendingReply<> firewalld::config::Zone::removeMasquerade() {
  Q_D(Zone);
  return d->zoneIface_.removeMasquerade();
}

QDBusPendingReply<>
firewalld::config::Zone::removePort(const QString &port,
                                    const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.removePort(port, protocol);
}

QDBusPendingReply<>
firewalld::config::Zone::removeProtocol(const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.removeProtocol(protocol);
}

QDBusPendingReply<>
firewalld::config::Zone::removeRichRule(const QString &rule) {
  Q_D(Zone);
  return d->zoneIface_.removeRichRule(rule);
}

QDBusPendingReply<>
firewalld::config::Zone::removeService(const QString &service) {
  Q_D(Zone);
  return d->zoneIface_.removeService(service);
}

QDBusPendingReply<>
firewalld::config::Zone::removeSource(const QString &source) {
  Q_D(Zone);
  return d->zoneIface_.removeSource(source);
}

QDBusPendingReply<>
firewalld::config::Zone::removeSourcePort(const QString &port,
                                          const QString &protocol) {
  Q_D(Zone);
  return d->zoneIface_.removeSourcePort(port, protocol);
}

QDBusPendingReply<> firewalld::config::Zone::rename(const QString &name) {
  Q_D(Zone);
  return d->zoneIface_.rename(name);
}

QDBusPendingReply<>
firewalld::config::Zone::setDescription(const QString &description) {
  Q_D(Zone);
  return d->zoneIface_.setDescription(description);
}

QDBusPendingReply<>
firewalld::config::Zone::setForwardPorts(const QVariantList &ports) {
  Q_D(Zone);
  return d->zoneIface_.setForwardPorts(ports);
}

QDBusPendingReply<> firewalld::config::Zone::setIcmpBlockInversion(bool flag) {
  Q_D(Zone);
  return d->zoneIface_.setIcmpBlockInversion(flag);
}

QDBusPendingReply<>
firewalld::config::Zone::setIcmpBlocks(const QStringList &icmptypes) {
  Q_D(Zone);
  return d->zoneIface_.setIcmpBlocks(icmptypes);
}

QDBusPendingReply<>
firewalld::config::Zone::setInterfaces(const QStringList &interfaces) {
  Q_D(Zone);
  return d->zoneIface_.setInterfaces(interfaces);
}

QDBusPendingReply<> firewalld::config::Zone::setMasquerade(bool masquerade) {
  Q_D(Zone);
  return d->zoneIface_.setMasquerade(masquerade);
}

QDBusPendingReply<> firewalld::config::Zone::setPorts(FWPortList ports) {
  Q_D(Zone);
  return d->zoneIface_.setPorts(ports);
}

QDBusPendingReply<>
firewalld::config::Zone::setProtocols(const QStringList &protocols) {
  Q_D(Zone);
  return d->zoneIface_.setProtocols(protocols);
}

QDBusPendingReply<>
firewalld::config::Zone::setRichRules(const QStringList &rules) {
  Q_D(Zone);
  return d->zoneIface_.setRichRules(rules);
}

QDBusPendingReply<>
firewalld::config::Zone::setServices(const QStringList &services) {
  Q_D(Zone);
  return d->zoneIface_.setServices(services);
}

QDBusPendingReply<>
firewalld::config::Zone::setShort(const QString &shortName) {
  Q_D(Zone);
  return d->zoneIface_.setShort(shortName);
}

QDBusPendingReply<>
firewalld::config::Zone::setSourcePorts(const QVariantList &ports) {
  Q_D(Zone);
  return d->zoneIface_.setSourcePorts(ports);
}

QDBusPendingReply<>
firewalld::config::Zone::setSources(const QStringList &sources) {
  Q_D(Zone);
  return d->zoneIface_.setSources(sources);
}

QDBusPendingReply<> firewalld::config::Zone::setTarget(const QString &target) {
  Q_D(Zone);
  return d->zoneIface_.setTarget(target);
}

QDBusPendingReply<>
firewalld::config::Zone::setVersion(const QString &version) {
  Q_D(Zone);
  return d->zoneIface_.setVersion(version);
}

QDBusPendingReply<>
firewalld::config::Zone::update2(const QVariantMap &settings) {
  Q_D(Zone);
  return d->zoneIface_.update2(settings);
}
