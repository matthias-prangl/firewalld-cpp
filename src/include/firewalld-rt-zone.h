#pragma once

#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::runtime {
class ZoneRtPrivate;

class ZoneRt : public QObject {
  Q_OBJECT
public:
  explicit ZoneRt(QObject *parent = nullptr);
  ~ZoneRt() override;
  QDBusPendingReply<QString> addForwardPort(const QString &zone,
                                            const QString &port,
                                            const QString &protocol,
                                            const QString &toport,
                                            const QString &toaddr, int timeout);
  QDBusPendingReply<QString> addIcmpBlock(const QString &zone,
                                          const QString &icmp, int timeout);
  QDBusPendingReply<QString> addIcmpBlockInversion(const QString &zone);
  QDBusPendingReply<QString> addInterface(const QString &zone,
                                          const QString &interface);
  QDBusPendingReply<QString> addMasquerade(const QString &zone, int timeout);
  QDBusPendingReply<QString> addPort(const QString &zone, const QString &port,
                                     const QString &protocol, int timeout);
  QDBusPendingReply<QString> addProtocol(const QString &zone,
                                         const QString &protocol, int timeout);
  QDBusPendingReply<QString> addRichRule(const QString &zone,
                                         const QString &rule, int timeout);
  QDBusPendingReply<QString> addService(const QString &zone,
                                        const QString &service, int timeout);
  QDBusPendingReply<QString> addSource(const QString &zone,
                                       const QString &source);
  QDBusPendingReply<QString> addSourcePort(const QString &zone,
                                           const QString &port,
                                           const QString &protocol,
                                           int timeout);
  QDBusPendingReply<QString> changeZoneOfInterface(const QString &zone,
                                                   const QString &interface);
  QDBusPendingReply<QString> changeZoneOfSource(const QString &zone,
                                                const QString &source);
  QDBusPendingReply<FWActiveZoneMap> getActiveZones();
  QDBusPendingReply<FWPortArray> getForwardPorts(const QString &zone);
  QDBusPendingReply<QStringList> getIcmpBlocks(const QString &zone);
  QDBusPendingReply<QStringList> getInterfaces(const QString &zone);
  QDBusPendingReply<FWPortArray> getPorts(const QString &zone);
  QDBusPendingReply<QStringList> getProtocols(const QString &zone);
  QDBusPendingReply<QStringList> getRichRules(const QString &zone);
  QDBusPendingReply<QStringList> getServices(const QString &zone);
  QDBusPendingReply<FWPortArray> getSourcePorts(const QString &zone);
  QDBusPendingReply<QStringList> getSources(const QString &zone);
  QDBusPendingReply<QString> getZoneOfInterface(const QString &interface);
  QDBusPendingReply<QString> getZoneOfSource(const QString &source);
  QDBusPendingReply<QVariantMap> getZoneSettings2(const QString &zone);
  QDBusPendingReply<QStringList> getZones();
  QDBusPendingReply<bool> queryForwardPort(const QString &zone,
                                           const QString &port,
                                           const QString &protocol,
                                           const QString &toport,
                                           const QString &toaddr);
  QDBusPendingReply<bool> queryIcmpBlock(const QString &zone,
                                         const QString &icmp);
  QDBusPendingReply<bool> queryIcmpBlockInversion(const QString &zone);
  QDBusPendingReply<bool> queryInterface(const QString &zone,
                                         const QString &interface);
  QDBusPendingReply<bool> queryMasquerade(const QString &zone);
  QDBusPendingReply<bool> queryPort(const QString &zone, const QString &port,
                                    const QString &protocol);
  QDBusPendingReply<bool> queryProtocol(const QString &zone,
                                        const QString &protocol);
  QDBusPendingReply<bool> queryRichRule(const QString &zone,
                                        const QString &rule);
  QDBusPendingReply<bool> queryService(const QString &zone,
                                       const QString &service);
  QDBusPendingReply<bool> querySource(const QString &zone,
                                      const QString &source);
  QDBusPendingReply<bool> querySourcePort(const QString &zone,
                                          const QString &port,
                                          const QString &protocol);
  QDBusPendingReply<QString> removeForwardPort(const QString &zone,
                                               const QString &port,
                                               const QString &protocol,
                                               const QString &toport,
                                               const QString &toaddr);
  QDBusPendingReply<QString> removeIcmpBlock(const QString &zone,
                                             const QString &icmp);
  QDBusPendingReply<QString> removeIcmpBlockInversion(const QString &zone);
  QDBusPendingReply<QString> removeInterface(const QString &zone,
                                             const QString &interface);
  QDBusPendingReply<QString> removeMasquerade(const QString &zone);
  QDBusPendingReply<QString>
  removePort(const QString &zone, const QString &port, const QString &protocol);
  QDBusPendingReply<QString> removeProtocol(const QString &zone,
                                            const QString &protocol);
  QDBusPendingReply<QString> removeRichRule(const QString &zone,
                                            const QString &rule);
  QDBusPendingReply<QString> removeService(const QString &zone,
                                           const QString &service);
  QDBusPendingReply<QString> removeSource(const QString &zone,
                                          const QString &source);
  QDBusPendingReply<QString> removeSourcePort(const QString &zone,
                                              const QString &port,
                                              const QString &protocol);
  QDBusPendingReply<> setZoneSettings2(const QString &zone,
                                       const QVariantMap &settings);

signals:
  void forwardPortAdded(const QString &zone, const QString &port,
                        const QString &protocol, const QString &toport,
                        const QString &toaddr, int timeout);
  void forwardPortRemoved(const QString &zone, const QString &port,
                          const QString &protocol, const QString &toport,
                          const QString &toaddr);
  void icmpBlockAdded(const QString &zone, const QString &icmp, int timeout);
  void icmpBlockInversionAdded(const QString &zone);
  void icmpBlockInversionRemoved(const QString &zone);
  void icmpBlockRemoved(const QString &zone, const QString &icmp);
  void interfaceAdded(const QString &zone, const QString &interface);
  void interfaceRemoved(const QString &zone, const QString &interface);
  void masqueradeAdded(const QString &zone, int timeout);
  void masqueradeRemoved(const QString &zone);
  void portAdded(const QString &zone, const QString &port,
                 const QString &protocol, int timeout);
  void portRemoved(const QString &zone, const QString &port,
                   const QString &protocol);
  void protocolAdded(const QString &zone, const QString &protocol, int timeout);
  void protocolRemoved(const QString &zone, const QString &protocol);
  void richRuleAdded(const QString &zone, const QString &rule, int timeout);
  void richRuleRemoved(const QString &zone, const QString &rule);
  void serviceAdded(const QString &zone, const QString &service, int timeout);
  void serviceRemoved(const QString &zone, const QString &service);
  void sourceAdded(const QString &zone, const QString &source);
  void sourcePortAdded(const QString &zone, const QString &port,
                       const QString &protocol, int timeout);
  void sourcePortRemoved(const QString &zone, const QString &port,
                         const QString &protocol);
  void sourceRemoved(const QString &zone, const QString &source);
  void zoneOfInterfaceChanged(const QString &zone, const QString &interface);
  void zoneOfSourceChanged(const QString &zone, const QString &source);
  void zoneUpdated(const QString &zone, const QVariantMap &settings);

protected:
  ZoneRtPrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(ZoneRt)
};
} // namespace firewalld::runtime
