#pragma once

#include "generictypes.h"
#include <QDBusPendingReply>

namespace firewalld::config {

class ConfigPoliciesPrivate;

class ConfigPolicies : public QObject {
  Q_OBJECT

public:
  explicit ConfigPolicies(QObject *parent = nullptr);
  ~ConfigPolicies() override;

  QDBusPendingReply<> addLockdownWhitelistCommand(const QString &command);
  QDBusPendingReply<> addLockdownWhitelistContext(const QString &context);
  QDBusPendingReply<> addLockdownWhitelistUid(int uid);
  QDBusPendingReply<> addLockdownWhitelistUser(const QString &user);
  QDBusPendingReply<FWLockdownWhiteList> getLockdownWhitelist();
  QDBusPendingReply<QStringList> getLockdownWhitelistCommands();
  QDBusPendingReply<QStringList> getLockdownWhitelistContexts();
  QDBusPendingReply<IntList> getLockdownWhitelistUids();
  QDBusPendingReply<QStringList> getLockdownWhitelistUsers();
  QDBusPendingReply<bool> queryLockdownWhitelistCommand(const QString &command);
  QDBusPendingReply<bool> queryLockdownWhitelistContext(const QString &context);
  QDBusPendingReply<bool> queryLockdownWhitelistUid(int uid);
  QDBusPendingReply<bool> queryLockdownWhitelistUser(const QString &user);
  QDBusPendingReply<> removeLockdownWhitelistCommand(const QString &command);
  QDBusPendingReply<> removeLockdownWhitelistContext(const QString &context);
  QDBusPendingReply<> removeLockdownWhitelistUid(int uid);
  QDBusPendingReply<> removeLockdownWhitelistUser(const QString &user);
  QDBusPendingReply<> setLockdownWhitelist(FWLockdownWhiteList settings);
signals:
  void lockdownWhitelistUpdated();

protected:
  ConfigPoliciesPrivate *const d_ptr;

private:
  Q_DECLARE_PRIVATE(ConfigPolicies)
};

} // namespace firewalld::config
