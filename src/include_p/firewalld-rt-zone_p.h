#pragma once

#include "firewalld_interface.h"

namespace firewalld::runtime {
class ZoneRt;

class ZoneRtPrivate : public QObject {
  Q_OBJECT
public:
  explicit ZoneRtPrivate(ZoneRt *q);
  ~ZoneRtPrivate() override;
  void init();

  OrgFedoraprojectFirewallD1ZoneInterface zoneRtIface_;
  ZoneRt *q_ptr;
  Q_DECLARE_PUBLIC(ZoneRt)

public slots:
  void zoneRtForwardPortAdded(const QString &zone, const QString &port,
                              const QString &protocol, const QString &toport,
                              const QString &toaddr, int timeout);
  void zoneRtForwardPortRemoved(const QString &zone, const QString &port,
                                const QString &protocol, const QString &toport,
                                const QString &toaddr);
  void zoneRtIcmpBlockAdded(const QString &zone, const QString &icmp,
                            int timeout);
  void zoneRtIcmpBlockInversionAdded(const QString &zone);
  void zoneRtIcmpBlockInversionRemoved(const QString &zone);
  void zoneRtIcmpBlockRemoved(const QString &zone, const QString &icmp);
  void zoneRtInterfaceAdded(const QString &zone, const QString &interface);
  void zoneRtInterfaceRemoved(const QString &zone, const QString &interface);
  void zoneRtMasqueradeAdded(const QString &zone, int timeout);
  void zoneRtMasqueradeRemoved(const QString &zone);
  void zoneRtPortAdded(const QString &zone, const QString &port,
                       const QString &protocol, int timeout);
  void zoneRtPortRemoved(const QString &zone, const QString &port,
                         const QString &protocol);
  void zoneRtProtocolAdded(const QString &zone, const QString &protocol,
                           int timeout);
  void zoneRtProtocolRemoved(const QString &zone, const QString &protocol);
  void zoneRtRichRuleAdded(const QString &zone, const QString &rule,
                           int timeout);
  void zoneRtRichRuleRemoved(const QString &zone, const QString &rule);
  void zoneRtServiceAdded(const QString &zone, const QString &service,
                          int timeout);
  void zoneRtServiceRemoved(const QString &zone, const QString &service);
  void zoneRtSourceAdded(const QString &zone, const QString &source);
  void zoneRtSourcePortAdded(const QString &zone, const QString &port,
                             const QString &protocol, int timeout);
  void zoneRtSourcePortRemoved(const QString &zone, const QString &port,
                               const QString &protocol);
  void zoneRtSourceRemoved(const QString &zone, const QString &source);
  void zoneRtZoneOfInterfaceChanged(const QString &zone,
                                    const QString &interface);
  void zoneRtZoneOfSourceChanged(const QString &zone, const QString &source);
  void zoneRtZoneUpdated(const QString &zone, const QVariantMap &settings);
};
} // namespace firewalld::runtime
