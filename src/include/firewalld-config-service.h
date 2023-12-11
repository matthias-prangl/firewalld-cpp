#pragma once
#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::config {

class ServicePrivate;

class Service : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool builtin READ builtin)
  Q_PROPERTY(bool isDefault READ isDefault)
  Q_PROPERTY(QString filename READ filename)
  Q_PROPERTY(QString name READ name)
  Q_PROPERTY(QString path READ path)

public:
  explicit Service(const QString &path, QObject *parent = nullptr);
  ~Service() override;

  bool builtin();
  bool isDefault();
  QString filename();
  QString name();
  QString path();

  QDBusPendingReply<> addInclude(const QString &include);
  QDBusPendingReply<> addPort(const QString &port, const QString &protocol);
  QDBusPendingReply<> addProtocol(const QString &protocol);
  QDBusPendingReply<> addSourcePort(const QString &port,
                                    const QString &protocol);
  QDBusPendingReply<QString> getDescription();
  QDBusPendingReply<QString> getDestination(const QString &family);
  QDBusPendingReply<FWStringMap> getDestinations();
  QDBusPendingReply<QStringList> getIncludes();
  QDBusPendingReply<FWPortList> getPorts();
  QDBusPendingReply<QStringList> getProtocols();
  QDBusPendingReply<QVariantMap> getSettings2();
  QDBusPendingReply<QString> getShort();
  QDBusPendingReply<FWPortList> getSourcePorts();
  QDBusPendingReply<QString> getVersion();
  QDBusPendingReply<> loadDefaults();
  QDBusPendingReply<bool> queryDestination(const QString &family,
                                           const QString &address);
  QDBusPendingReply<bool> queryInclude(const QString &include);
  QDBusPendingReply<bool> queryPort(const QString &port,
                                    const QString &protocol);
  QDBusPendingReply<bool> queryProtocol(const QString &protocol);
  QDBusPendingReply<bool> querySourcePort(const QString &port,
                                          const QString &protocol);
  QDBusPendingReply<> remove();
  QDBusPendingReply<> removeDestination(const QString &family);
  QDBusPendingReply<> removeInclude(const QString &include);
  QDBusPendingReply<> removePort(const QString &port, const QString &protocol);
  QDBusPendingReply<> removeProtocol(const QString &protocol);
  QDBusPendingReply<> removeSourcePort(const QString &port,
                                       const QString &protocol);
  QDBusPendingReply<> rename(const QString &name);
  QDBusPendingReply<> setDescription(const QString &description);
  QDBusPendingReply<> setDestination(const QString &family,
                                     const QString &address);
  QDBusPendingReply<> setDestinations(FWStringMap destinations);
  QDBusPendingReply<> setIncludes(const QStringList &includes);
  QDBusPendingReply<> setPorts(FWPortList ports);
  QDBusPendingReply<> setProtocols(const QStringList &protocols);
  QDBusPendingReply<> setShort(const QString &shortName);
  QDBusPendingReply<> setSourcePorts(FWPortList ports);
  QDBusPendingReply<> setVersion(const QString &version);
  QDBusPendingReply<> update2(const QVariantMap &settings);

signals:
  void removed(const QString &name);
  void renamed(const QString &name);
  void updated(const QString &name);

  void builtinChanged(const bool &builtin);
  void isDefaultChanged(const bool &isDefault);
  void filenameChanged(const QString &filename);
  void nameChanged(const QString &name);
  void pathChanged(const QString &path);

protected:
  ServicePrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(Service)
};
} // namespace firewalld::config
