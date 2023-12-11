#pragma once

#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::runtime {

class FirewallDPrivate;

class FirewallD : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool bridge READ bridge)
  Q_PROPERTY(bool ipSet READ ipSet)
  Q_PROPERTY(QStringList ipSetTypes READ ipSetTypes)
  Q_PROPERTY(bool ipv4 READ ipv4)
  Q_PROPERTY(QStringList ipv4ICMPTypes READ ipv4ICMPTypes)
  Q_PROPERTY(bool ipv6 READ ipv6)
  Q_PROPERTY(QStringList ipv6ICMPTypes READ ipv6ICMPTypes)
  Q_PROPERTY(bool ipv6_rpfilter READ ipv6_rpfilter)
  Q_PROPERTY(QString interface_version READ interface_version)
  Q_PROPERTY(QString state READ state)
  Q_PROPERTY(QString version READ version)

public:
  explicit FirewallD(QObject *parent = nullptr);
  ~FirewallD() override;

  bool bridge();
  bool ipSet();
  const QStringList ipSetTypes();
  bool ipv4();
  const QStringList ipv4ICMPTypes();
  bool ipv6();
  const QStringList ipv6ICMPTypes();
  bool ipv6_rpfilter();
  const QString interface_version();
  const QString state();
  const QString version();

  QDBusPendingReply<> authorizeAll();
  QDBusPendingReply<> checkPermanentConfig();
  QDBusPendingReply<> completeReload();
  QDBusPendingReply<> disablePanicMode();
  QDBusPendingReply<> enablePanicMode();
  QDBusPendingReply<QString> getDefaultZone();
  QDBusPendingReply<FWHelperSettings> getHelperSettings(const QString &helper);
  QDBusPendingReply<QStringList> getHelpers();
  QDBusPendingReply<FWIcmpTypeSettings>
  getIcmpTypeSettings(const QString &icmptype);
  QDBusPendingReply<QString> getLogDenied();
  QDBusPendingReply<QVariantMap> getServiceSettings2(const QString &service);
  QDBusPendingReply<QStringList> listIcmpTypes();
  QDBusPendingReply<QStringList> listServices();
  QDBusPendingReply<bool> queryPanicMode();
  QDBusPendingReply<> reload();
  QDBusPendingReply<> resetToDefaults();
  QDBusPendingReply<> runtimeToPermanent();
  QDBusPendingReply<> setAutomaticHelpers(const QString &value);
  QDBusPendingReply<> setDefaultZone(const QString &zone);
  QDBusPendingReply<> setLogDenied(const QString &value);

signals:
  void automaticHelpersChanged(const QString &value);
  void defaultZoneChanged(const QString &zone);
  void logDeniedChanged(const QString &value);
  void panicModeDisabled();
  void panicModeEnabled();
  void reloaded();

  void bridgeChanged(const bool &bridge);
  void ipSetChanged(const bool &ipSet);
  void ipSetTypesChanged(const QStringList &ipSetTypes);
  void ipv4Changed(const bool &ipv4);
  void ipv4ICMPTypesChanged(const QStringList &ipv4ICMPTypes);
  void ipv6Changed(const bool &ipv6);
  void ipv6ICMPTypesChanged(const QStringList &ipv6ICMPTypes);
  void ipv6_rpfilterChanged(const bool &ipv6_rpfilter);
  void interface_versionChanged(const QString &interface_version);
  void stateChanged(const QString &state);
  void versionChanged(const QString &version);

protected:
  FirewallDPrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(FirewallD)
};
} // namespace firewalld::runtime
