#include "firewalld-config-policies.h"
#include "firewalld-config-policies_p.h"
#include "firewalld_config_interface.h"
#include "firewalld_dbus.h"
#include "generictypes.h"
#include <qobject.h>
 firewalld::config::ConfigPoliciesPrivate::ConfigPoliciesPrivate(
    ConfigPolicies *q)
    : configPoliciesIface_(firewalld::dbus::kFirewallDDBusService,
                           firewalld::dbus::kFirewallDDBusConfigPath,
                           QDBusConnection::systemBus()),
      q_ptr(q) {
  qDBusRegisterMetaType<IntList>();
  qDBusRegisterMetaType<FWLockdownWhiteList>();
}

firewalld::config::ConfigPoliciesPrivate::~ConfigPoliciesPrivate() {}

void firewalld::config::ConfigPoliciesPrivate::init() {
  QObject::connect(&configPoliciesIface_,
                   &OrgFedoraprojectFirewallD1ConfigPoliciesInterface::
                       LockdownWhitelistUpdated,
                   this,
                   &ConfigPoliciesPrivate::configLockdownWhitelistUpdated);
}

void firewalld::config::ConfigPoliciesPrivate::
    configLockdownWhitelistUpdated() {
  Q_Q(ConfigPolicies);
  emit q->lockdownWhitelistUpdated();
}

firewalld::config::ConfigPolicies::ConfigPolicies(QObject *parent)
    : QObject(parent), d_ptr(new ConfigPoliciesPrivate(this)) {
  Q_D(ConfigPolicies);
  d->init();
}

firewalld::config::ConfigPolicies::~ConfigPolicies() {
  Q_D(ConfigPolicies);
  delete d;
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::addLockdownWhitelistCommand(
    const QString &command) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.addLockdownWhitelistCommand(command);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::addLockdownWhitelistContext(
    const QString &context) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.addLockdownWhitelistContext(context);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::addLockdownWhitelistUid(int uid) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.addLockdownWhitelistUid(uid);
}

QDBusPendingReply<> firewalld::config::ConfigPolicies::addLockdownWhitelistUser(
    const QString &user) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.addLockdownWhitelistUser(user);
}

QDBusPendingReply<FWLockdownWhiteList>
firewalld::config::ConfigPolicies::getLockdownWhitelist() {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.getLockdownWhitelist();
}

QDBusPendingReply<QStringList>
firewalld::config::ConfigPolicies::getLockdownWhitelistCommands() {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.getLockdownWhitelistCommands();
}

QDBusPendingReply<QStringList>
firewalld::config::ConfigPolicies::getLockdownWhitelistContexts() {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.getLockdownWhitelistContexts();
}

QDBusPendingReply<IntList>
firewalld::config::ConfigPolicies::getLockdownWhitelistUids() {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.getLockdownWhitelistUids();
}

QDBusPendingReply<QStringList>
firewalld::config::ConfigPolicies::getLockdownWhitelistUsers() {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.getLockdownWhitelistUsers();
}

QDBusPendingReply<bool>
firewalld::config::ConfigPolicies::queryLockdownWhitelistCommand(
    const QString &command) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.queryLockdownWhitelistCommand(command);
}

QDBusPendingReply<bool>
firewalld::config::ConfigPolicies::queryLockdownWhitelistContext(
    const QString &context) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.queryLockdownWhitelistContext(context);
}

QDBusPendingReply<bool>
firewalld::config::ConfigPolicies::queryLockdownWhitelistUid(int uid) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.queryLockdownWhitelistUid(uid);
}

QDBusPendingReply<bool>
firewalld::config::ConfigPolicies::queryLockdownWhitelistUser(
    const QString &user) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.queryLockdownWhitelistUser(user);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::removeLockdownWhitelistCommand(
    const QString &command) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.removeLockdownWhitelistCommand(command);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::removeLockdownWhitelistContext(
    const QString &context) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.removeLockdownWhitelistContext(context);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::removeLockdownWhitelistUid(int uid) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.removeLockdownWhitelistUid(uid);
}

QDBusPendingReply<>
firewalld::config::ConfigPolicies::removeLockdownWhitelistUser(
    const QString &user) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.removeLockdownWhitelistUser(user);
}

QDBusPendingReply<> firewalld::config::ConfigPolicies::setLockdownWhitelist(
    FWLockdownWhiteList settings) {
  Q_D(ConfigPolicies);
  return d->configPoliciesIface_.setLockdownWhitelist(settings);
}
