#pragma once

#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::config {

class ZonePrivate;

class Zone : public QObject {
  Q_OBJECT

  Q_PROPERTY(bool builtin READ builtin)
  Q_PROPERTY(bool isDefault READ isDefault)
  Q_PROPERTY(QString filename READ filename)
  Q_PROPERTY(QString name READ name)
  Q_PROPERTY(QString path READ path)

public:
  explicit Zone(const QString &path, QObject *parent = nullptr);
  ~Zone() override;

  bool builtin();
  bool isDefault();
  QString filename();
  QString name();
  QString path();

  QDBusPendingReply<> addForwardPort(const QString &port,
                                     const QString &protocol,
                                     const QString &toport,
                                     const QString &toaddr);
  QDBusPendingReply<> addIcmpBlock(const QString &icmptype);
  QDBusPendingReply<> addIcmpBlockInversion();
  QDBusPendingReply<> addInterface(const QString &interface);
  QDBusPendingReply<> addMasquerade();
  QDBusPendingReply<> addPort(const QString &port, const QString &protocol);
  QDBusPendingReply<> addProtocol(const QString &protocol);
  QDBusPendingReply<> addRichRule(const QString &rule);
  QDBusPendingReply<> addService(const QString &service);
  QDBusPendingReply<> addSource(const QString &source);
  QDBusPendingReply<> addSourcePort(const QString &port,
                                    const QString &protocol);
  QDBusPendingReply<> loadDefaults();

  QDBusPendingReply<bool> queryForwardPort(const QString &port,
                                           const QString &protocol,
                                           const QString &toport,
                                           const QString &toaddr);
  QDBusPendingReply<bool> queryIcmpBlock(const QString &icmptype);
  QDBusPendingReply<bool> queryIcmpBlockInversion();
  QDBusPendingReply<bool> queryInterface(const QString &interface);
  QDBusPendingReply<bool> queryMasquerade();
  QDBusPendingReply<bool> queryPort(const QString &port,
                                    const QString &protocol);
  QDBusPendingReply<bool> queryProtocol(const QString &protocol);
  QDBusPendingReply<bool> queryRichRule(const QString &rule);
  QDBusPendingReply<bool> queryService(const QString &service);
  QDBusPendingReply<bool> querySource(const QString &source);
  QDBusPendingReply<bool> querySourcePort(const QString &port,
                                          const QString &protocol);

  QDBusPendingReply<> remove();
  QDBusPendingReply<> removeForwardPort(const QString &port,
                                        const QString &protocol,
                                        const QString &toport,
                                        const QString &toaddr);
  QDBusPendingReply<> removeIcmpBlock(const QString &icmptype);
  QDBusPendingReply<> removeIcmpBlockInversion();
  QDBusPendingReply<> removeInterface(const QString &interface);
  QDBusPendingReply<> removeMasquerade();
  QDBusPendingReply<> removePort(const QString &port, const QString &protocol);
  QDBusPendingReply<> removeProtocol(const QString &protocol);
  QDBusPendingReply<> removeRichRule(const QString &rule);
  QDBusPendingReply<> removeService(const QString &service);
  QDBusPendingReply<> removeSource(const QString &source);
  QDBusPendingReply<> removeSourcePort(const QString &port,
                                       const QString &protocol);
  QDBusPendingReply<> rename(const QString &name);

  QDBusPendingReply<> setDescription(const QString &description);
  QDBusPendingReply<> setForwardPorts(const QVariantList &ports);
  QDBusPendingReply<> setIcmpBlockInversion(bool flag);
  QDBusPendingReply<> setIcmpBlocks(const QStringList &icmptypes);
  QDBusPendingReply<> setInterfaces(const QStringList &interfaces);
  QDBusPendingReply<> setMasquerade(bool masquerade);
  QDBusPendingReply<> setPorts(FWPortList ports);
  QDBusPendingReply<> setProtocols(const QStringList &protocols);
  QDBusPendingReply<> setRichRules(const QStringList &rules);
  QDBusPendingReply<> setServices(const QStringList &services);
  QDBusPendingReply<> setShort(const QString &shortName);
  QDBusPendingReply<> setSourcePorts(const QVariantList &ports);
  QDBusPendingReply<> setSources(const QStringList &sources);
  QDBusPendingReply<> setTarget(const QString &target);
  QDBusPendingReply<> setVersion(const QString &version);
  QDBusPendingReply<> update2(const QVariantMap &settings);

  QDBusPendingReply<QString> getDescription();
  QDBusPendingReply<QVariantList> getForwardPorts();
  QDBusPendingReply<bool> getIcmpBlockInversion();
  QDBusPendingReply<QStringList> getIcmpBlocks();
  QDBusPendingReply<QStringList> getInterfaces();
  QDBusPendingReply<bool> getMasquerade();
  QDBusPendingReply<FWPortList> getPorts();
  QDBusPendingReply<QStringList> getProtocols();
  QDBusPendingReply<QStringList> getRichRules();
  QDBusPendingReply<QStringList> getServices();
  QDBusPendingReply<QVariantMap> getSettings2();
  QDBusPendingReply<QString> getShort();
  QDBusPendingReply<QVariantList> getSourcePorts();
  QDBusPendingReply<QStringList> getSources();
  QDBusPendingReply<QString> getTarget();
  QDBusPendingReply<QString> getVersion();

signals:
  void removed(const QString &name);
  void renamed(const QString &name);
  void updated(const QString &name);

protected:
  ZonePrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(Zone)
};
} // namespace firewalld::config
