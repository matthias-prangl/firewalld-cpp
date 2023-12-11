#include "firewalld-rt-zone.h"
#include "firewalld-rt-zone_p.h"
#include "firewalld-rt.h"
#include "firewalld_dbus.h"
#include "firewalld_interface.h"

firewalld::runtime::ZoneRtPrivate::ZoneRtPrivate(ZoneRt *q)
    : zoneRtIface_(firewalld::dbus::kFirewallDDBusService,
                   dbus::kFirewallDDBusBasePath, QDBusConnection::systemBus()),
      q_ptr(q) {

  qDBusRegisterMetaType<FWActiveZoneMap>();
  qDBusRegisterMetaType<FWPortArray>();
}

firewalld::runtime::ZoneRtPrivate::~ZoneRtPrivate() {}

void firewalld::runtime::ZoneRtPrivate::init() {
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ForwardPortAdded,
                   this, &ZoneRtPrivate::zoneRtForwardPortAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ForwardPortRemoved,
                   this, &ZoneRtPrivate::zoneRtForwardPortRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::IcmpBlockAdded,
                   this, &ZoneRtPrivate::zoneRtIcmpBlockAdded);
  QObject::connect(
      &zoneRtIface_,
      &OrgFedoraprojectFirewallD1ZoneInterface::IcmpBlockInversionAdded, this,
      &ZoneRtPrivate::zoneRtIcmpBlockInversionAdded);
  QObject::connect(
      &zoneRtIface_,
      &OrgFedoraprojectFirewallD1ZoneInterface::IcmpBlockInversionRemoved, this,
      &ZoneRtPrivate::zoneRtIcmpBlockInversionRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::IcmpBlockRemoved,
                   this, &ZoneRtPrivate::zoneRtIcmpBlockRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::InterfaceAdded,
                   this, &ZoneRtPrivate::zoneRtInterfaceAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::InterfaceRemoved,
                   this, &ZoneRtPrivate::zoneRtInterfaceRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::MasqueradeAdded,
                   this, &ZoneRtPrivate::zoneRtMasqueradeAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::MasqueradeRemoved,
                   this, &ZoneRtPrivate::zoneRtMasqueradeRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::PortAdded, this,
                   &ZoneRtPrivate::zoneRtPortAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::PortRemoved, this,
                   &ZoneRtPrivate::zoneRtPortRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ProtocolAdded,
                   this, &ZoneRtPrivate::zoneRtProtocolAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ProtocolRemoved,
                   this, &ZoneRtPrivate::zoneRtProtocolRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::RichRuleAdded,
                   this, &ZoneRtPrivate::zoneRtRichRuleAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::RichRuleRemoved,
                   this, &ZoneRtPrivate::zoneRtRichRuleRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ServiceAdded, this,
                   &ZoneRtPrivate::zoneRtServiceAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ServiceRemoved,
                   this, &ZoneRtPrivate::zoneRtServiceRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::SourceAdded, this,
                   &ZoneRtPrivate::zoneRtSourceAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::SourcePortAdded,
                   this, &ZoneRtPrivate::zoneRtSourcePortAdded);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::SourcePortRemoved,
                   this, &ZoneRtPrivate::zoneRtSourcePortRemoved);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::SourceRemoved,
                   this, &ZoneRtPrivate::zoneRtSourceRemoved);
  QObject::connect(
      &zoneRtIface_,
      &OrgFedoraprojectFirewallD1ZoneInterface::ZoneOfInterfaceChanged, this,
      &ZoneRtPrivate::zoneRtZoneOfInterfaceChanged);
  QObject::connect(
      &zoneRtIface_,
      &OrgFedoraprojectFirewallD1ZoneInterface::ZoneOfSourceChanged, this,
      &ZoneRtPrivate::zoneRtZoneOfSourceChanged);
  QObject::connect(&zoneRtIface_,
                   &OrgFedoraprojectFirewallD1ZoneInterface::ZoneUpdated, this,
                   &ZoneRtPrivate::zoneRtZoneUpdated);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtForwardPortAdded(
    const QString &zone, const QString &port, const QString &protocol,
    const QString &toport, const QString &toaddr, int timeout) {
  Q_Q(ZoneRt);
  emit q->forwardPortAdded(zone, port, protocol, toport, toaddr, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtForwardPortRemoved(
    const QString &zone, const QString &port, const QString &protocol,
    const QString &toport, const QString &toaddr) {
  Q_Q(ZoneRt);
  emit q->forwardPortRemoved(zone, port, protocol, toport, toaddr);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtIcmpBlockAdded(
    const QString &zone, const QString &icmp, int timeout) {
  Q_Q(ZoneRt);
  emit q->icmpBlockAdded(zone, icmp, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtIcmpBlockInversionAdded(
    const QString &zone) {
  Q_Q(ZoneRt);
  emit q->icmpBlockInversionAdded(zone);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtIcmpBlockInversionRemoved(
    const QString &zone) {
  Q_Q(ZoneRt);
  emit q->icmpBlockInversionRemoved(zone);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtIcmpBlockRemoved(
    const QString &zone, const QString &icmp) {
  Q_Q(ZoneRt);
  emit q->icmpBlockRemoved(zone, icmp);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtInterfaceAdded(
    const QString &zone, const QString &interface) {
  Q_Q(ZoneRt);
  emit q->interfaceAdded(zone, interface);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtInterfaceRemoved(
    const QString &zone, const QString &interface) {
  Q_Q(ZoneRt);
  emit q->interfaceRemoved(zone, interface);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtMasqueradeAdded(
    const QString &zone, int timeout) {
  Q_Q(ZoneRt);
  emit q->masqueradeAdded(zone, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtMasqueradeRemoved(
    const QString &zone) {
  Q_Q(ZoneRt);
  emit q->masqueradeRemoved(zone);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtPortAdded(const QString &zone,
                                                        const QString &port,
                                                        const QString &protocol,
                                                        int timeout) {
  Q_Q(ZoneRt);
  emit q->portAdded(zone, port, protocol, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtPortRemoved(
    const QString &zone, const QString &port, const QString &protocol) {
  Q_Q(ZoneRt);
  emit q->portRemoved(zone, port, protocol);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtProtocolAdded(
    const QString &zone, const QString &protocol, int timeout) {
  Q_Q(ZoneRt);
  emit q->protocolAdded(zone, protocol, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtProtocolRemoved(
    const QString &zone, const QString &protocol) {
  Q_Q(ZoneRt);
  emit q->protocolRemoved(zone, protocol);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtRichRuleAdded(const QString &zone,
                                                            const QString &rule,
                                                            int timeout) {
  Q_Q(ZoneRt);
  emit q->richRuleAdded(zone, rule, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtRichRuleRemoved(
    const QString &zone, const QString &rule) {
  Q_Q(ZoneRt);
  emit q->richRuleRemoved(zone, rule);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtServiceAdded(
    const QString &zone, const QString &service, int timeout) {
  Q_Q(ZoneRt);
  emit q->serviceAdded(zone, service, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtServiceRemoved(
    const QString &zone, const QString &service) {
  Q_Q(ZoneRt);
  emit q->serviceRemoved(zone, service);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtSourceAdded(
    const QString &zone, const QString &source) {
  Q_Q(ZoneRt);
  emit q->sourceAdded(zone, source);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtSourcePortAdded(
    const QString &zone, const QString &port, const QString &protocol,
    int timeout) {
  Q_Q(ZoneRt);
  emit q->sourcePortAdded(zone, port, protocol, timeout);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtSourcePortRemoved(
    const QString &zone, const QString &port, const QString &protocol) {
  Q_Q(ZoneRt);
  emit q->sourcePortRemoved(zone, port, protocol);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtSourceRemoved(
    const QString &zone, const QString &source) {
  Q_Q(ZoneRt);
  emit q->sourceRemoved(zone, source);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtZoneOfInterfaceChanged(
    const QString &zone, const QString &interface) {
  Q_Q(ZoneRt);
  emit q->zoneOfInterfaceChanged(zone, interface);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtZoneOfSourceChanged(
    const QString &zone, const QString &source) {
  Q_Q(ZoneRt);
  emit q->zoneOfSourceChanged(zone, source);
}

void firewalld::runtime::ZoneRtPrivate::zoneRtZoneUpdated(
    const QString &zone, const QVariantMap &settings) {
  Q_Q(ZoneRt);
  emit q->zoneUpdated(zone, settings);
}

firewalld::runtime::ZoneRt::ZoneRt(QObject *parent)
    : QObject(parent), d_ptr(new ZoneRtPrivate(this)) {
  Q_D(ZoneRt);
  d->init();
}

firewalld::runtime::ZoneRt::~ZoneRt() {
  Q_D(ZoneRt);
  delete d;
}

QDBusPendingReply<QString> firewalld::runtime::ZoneRt::addForwardPort(
    const QString &zone, const QString &port, const QString &protocol,
    const QString &toport, const QString &toaddr, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addForwardPort(zone, port, protocol, toport, toaddr,
                                        timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addIcmpBlock(const QString &zone,
                                         const QString &icmp, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addIcmpBlock(zone, icmp, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addIcmpBlockInversion(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addIcmpBlockInversion(zone);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addInterface(const QString &zone,
                                         const QString &interface) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addInterface(zone, interface);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addMasquerade(const QString &zone, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addMasquerade(zone, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addPort(const QString &zone, const QString &port,
                                    const QString &protocol, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addPort(zone, port, protocol, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addProtocol(const QString &zone,
                                        const QString &protocol, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addProtocol(zone, protocol, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addRichRule(const QString &zone,
                                        const QString &rule, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addRichRule(zone, rule, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addService(const QString &zone,
                                       const QString &service, int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addService(zone, service, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::addSource(const QString &zone,
                                      const QString &source) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addSource(zone, source);
}

QDBusPendingReply<QString> firewalld::runtime::ZoneRt::addSourcePort(
    const QString &zone, const QString &port, const QString &protocol,
    int timeout) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.addSourcePort(zone, port, protocol, timeout);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::changeZoneOfInterface(const QString &zone,
                                                  const QString &interface) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.changeZoneOfInterface(zone, interface);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::changeZoneOfSource(const QString &zone,
                                               const QString &source) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.changeZoneOfSource(zone, source);
}

QDBusPendingReply<FWActiveZoneMap>
firewalld::runtime::ZoneRt::getActiveZones() {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getActiveZones();
}

QDBusPendingReply<FWPortArray>
firewalld::runtime::ZoneRt::getForwardPorts(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getForwardPorts(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getIcmpBlocks(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getIcmpBlocks(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getInterfaces(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getInterfaces(zone);
}

QDBusPendingReply<FWPortArray>
firewalld::runtime::ZoneRt::getPorts(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getPorts(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getProtocols(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getProtocols(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getRichRules(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getRichRules(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getServices(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getServices(zone);
}

QDBusPendingReply<FWPortArray>
firewalld::runtime::ZoneRt::getSourcePorts(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getSourcePorts(zone);
}

QDBusPendingReply<QStringList>
firewalld::runtime::ZoneRt::getSources(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getSources(zone);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::getZoneOfInterface(const QString &interface) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getZoneOfInterface(interface);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::getZoneOfSource(const QString &source) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getZoneOfSource(source);
}

QDBusPendingReply<QVariantMap>
firewalld::runtime::ZoneRt::getZoneSettings2(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getZoneSettings2(zone);
}

QDBusPendingReply<QStringList> firewalld::runtime::ZoneRt::getZones() {
  Q_D(ZoneRt);
  return d->zoneRtIface_.getZones();
}

QDBusPendingReply<bool> firewalld::runtime::ZoneRt::queryForwardPort(
    const QString &zone, const QString &port, const QString &protocol,
    const QString &toport, const QString &toaddr) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryForwardPort(zone, port, protocol, toport, toaddr);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryIcmpBlock(const QString &zone,
                                           const QString &icmp) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryIcmpBlock(zone, icmp);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryIcmpBlockInversion(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryIcmpBlockInversion(zone);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryInterface(const QString &zone,
                                           const QString &interface) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryInterface(zone, interface);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryMasquerade(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryMasquerade(zone);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryPort(const QString &zone, const QString &port,
                                      const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryPort(zone, port, protocol);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryProtocol(const QString &zone,
                                          const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryProtocol(zone, protocol);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryRichRule(const QString &zone,
                                          const QString &rule) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryRichRule(zone, rule);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::queryService(const QString &zone,
                                         const QString &service) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.queryService(zone, service);
}

QDBusPendingReply<bool>
firewalld::runtime::ZoneRt::querySource(const QString &zone,
                                        const QString &source) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.querySource(zone, source);
}

QDBusPendingReply<bool> firewalld::runtime::ZoneRt::querySourcePort(
    const QString &zone, const QString &port, const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.querySourcePort(zone, port, protocol);
}

QDBusPendingReply<QString> firewalld::runtime::ZoneRt::removeForwardPort(
    const QString &zone, const QString &port, const QString &protocol,
    const QString &toport, const QString &toaddr) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeForwardPort(zone, port, protocol, toport,
                                           toaddr);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeIcmpBlock(const QString &zone,
                                            const QString &icmp) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeIcmpBlock(zone, icmp);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeIcmpBlockInversion(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeIcmpBlockInversion(zone);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeInterface(const QString &zone,
                                            const QString &interface) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeInterface(zone, interface);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeMasquerade(const QString &zone) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeMasquerade(zone);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removePort(const QString &zone, const QString &port,
                                       const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removePort(zone, port, protocol);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeProtocol(const QString &zone,
                                           const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeProtocol(zone, protocol);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeRichRule(const QString &zone,
                                           const QString &rule) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeRichRule(zone, rule);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeService(const QString &zone,
                                          const QString &service) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeService(zone, service);
}

QDBusPendingReply<QString>
firewalld::runtime::ZoneRt::removeSource(const QString &zone,
                                         const QString &source) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeSource(zone, source);
}

QDBusPendingReply<QString> firewalld::runtime::ZoneRt::removeSourcePort(
    const QString &zone, const QString &port, const QString &protocol) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.removeSourcePort(zone, port, protocol);
}

QDBusPendingReply<>
firewalld::runtime::ZoneRt::setZoneSettings2(const QString &zone,
                                             const QVariantMap &settings) {
  Q_D(ZoneRt);
  return d->zoneRtIface_.setZoneSettings2(zone, settings);
}
