#pragma once

#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::config {

class ConfigPrivate;

class Config : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString DefaultZone READ defaultZone)
  Q_PROPERTY(QString CleanupOnExit READ cleanupOnExit)
  Q_PROPERTY(QString CleanupModulesOnExit READ cleanupModulesOnExit)
  Q_PROPERTY(QString Lockdown READ lockdown)
  Q_PROPERTY(QString IPv6_rpfilter READ iPv6_rpfilter)
  Q_PROPERTY(QString IndividualCalls READ individualCalls)
  Q_PROPERTY(QString LogDenied READ logDenied)
  Q_PROPERTY(QString FirewallBackend READ firewallBackend)
  Q_PROPERTY(QString FlushAllOnReload READ flushAllOnReload)
  Q_PROPERTY(QString RFC3964_IPv4 READ rFC3964_IPv4)
  Q_PROPERTY(QString NftablesFlowtable READ nftablesFlowtable)
  Q_PROPERTY(QString NftablesCounters READ nftablesCounters)

public:
  explicit Config(QObject *parent = nullptr);
  ~Config() override;

  const QString defaultZone();
  const QString cleanupOnExit();
  const QString cleanupModulesOnExit();
  const QString lockdown();
  const QString iPv6_rpfilter();
  const QString individualCalls();
  const QString logDenied();
  const QString firewallBackend();
  const QString flushAllOnReload();
  const QString rFC3964_IPv4();
  const QString nftablesFlowtable();
  const QString nftablesCounters();

  QDBusPendingReply<QDBusObjectPath> addIcmpType(const QString &icmptype,
                                                 FWIcmpTypeSettings settings);
  QDBusPendingReply<QDBusObjectPath> addIPSet(const QString &ipset,
                                              FWIPSetSettings settings);
  QDBusPendingReply<QDBusObjectPath> addPolicy(const QString &policy,
                                               const QVariantMap &settings);
  QDBusPendingReply<QDBusObjectPath> addService2(const QString &service,
                                                 const QVariantMap &settings);
  QDBusPendingReply<QDBusObjectPath> addZone2(const QString &zone,
                                              const QVariantMap &settings);
  QDBusPendingReply<QDBusObjectPath> getHelperByName(const QString &helper);
  QDBusPendingReply<QStringList> getHelperNames();
  QDBusPendingReply<QDBusObjectPath> getIcmpTypeByName(const QString &icmptype);
  QDBusPendingReply<QStringList> getIcmpTypeNames();
  QDBusPendingReply<QDBusObjectPath> getIPSetByName(const QString &ipset);
  QDBusPendingReply<QStringList> getIPSetNames();
  QDBusPendingReply<QDBusObjectPath> getPolicyByName(const QString &policy);
  QDBusPendingReply<QStringList> getPolicyNames();
  QDBusPendingReply<QDBusObjectPath> getServiceByName(const QString &service);
  QDBusPendingReply<QStringList> getServiceNames();
  QDBusPendingReply<QDBusObjectPath> getZoneByName(const QString &zone);
  QDBusPendingReply<QStringList> getZoneNames();
  QDBusPendingReply<QString> getZoneOfInterface(const QString &iface);
  QDBusPendingReply<QString> getZoneOfSource(const QString &source);
  QDBusPendingReply<QList<QDBusObjectPath>> listHelpers();
  QDBusPendingReply<QList<QDBusObjectPath>> listIcmpTypes();
  QDBusPendingReply<QList<QDBusObjectPath>> listIPSets();
  QDBusPendingReply<QList<QDBusObjectPath>> listPolicies();
  QDBusPendingReply<QList<QDBusObjectPath>> listServices();
  QDBusPendingReply<QList<QDBusObjectPath>> listZones();

signals:
  void helperAdded(const QString &helper);
  void ipSetAdded(const QString &ipset);
  void icmpTypeAdded(const QString &icmptype);
  void policyAdded(const QString &policy);
  void serviceAdded(const QString &service);
  void zoneAdded(const QString &zone);

protected:
  ConfigPrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(Config)
};
} // namespace firewalld::config
