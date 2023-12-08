#pragma once

#include <QDBusArgument>

typedef QList<int> IntList;
Q_DECLARE_METATYPE(IntList);

typedef QMap<QString,QString> FWStringMap;
Q_DECLARE_METATYPE(FWStringMap);

typedef QMap<QString, QMap<QString, QStringList>> FWActiveZoneMap;
Q_DECLARE_METATYPE(FWActiveZoneMap)

typedef QList<QList<QString>> FWPortArray;
Q_DECLARE_METATYPE(FWPortArray)

typedef QPair<QString, QString> FWPort;
Q_DECLARE_METATYPE(FWPort)

typedef QList<FWPort> FWPortList;
Q_DECLARE_METATYPE(FWPortList)

typedef struct {
  QString version;
  QString name;
  QString description;
  QStringList destinations;
} FWIcmpTypeSettings;
Q_DECLARE_METATYPE(FWIcmpTypeSettings)

QDBusArgument &operator<<(QDBusArgument &argument, const FWIcmpTypeSettings &icmpTypeSettings);
const QDBusArgument &operator>>(const QDBusArgument &argument, FWIcmpTypeSettings &icmpTypeSettings);

typedef struct {
  QString version;
  QString name;
  QString description;
  QString family;
  QString module;
  FWPortList ports;
} FWHelperSettings;
Q_DECLARE_METATYPE(FWHelperSettings)

QDBusArgument &operator<<(QDBusArgument &argument, const FWHelperSettings &helperSettings);
const QDBusArgument &operator>>(const QDBusArgument &argument, FWHelperSettings &helperSettings);

typedef struct {
  QString version;
  QString name;
  QString description;
  QString type;
  FWStringMap options;
  QStringList entries;
} FWIPSetSettings;
Q_DECLARE_METATYPE(FWIPSetSettings)

QDBusArgument &operator<<(QDBusArgument &argument, const FWIPSetSettings &ipSetSettings);
const QDBusArgument &operator>>(const QDBusArgument &argument, FWIPSetSettings &ipSetSettings);

typedef struct {
  QStringList commands;
  QStringList selinuxContexts;
  QStringList users;
  IntList uids;
} FWLockdownWhiteList;
Q_DECLARE_METATYPE(FWLockdownWhiteList);

QDBusArgument &operator<<(QDBusArgument &argument, const FWLockdownWhiteList &fwLockdownWhiteList);
const QDBusArgument &operator>>(const QDBusArgument &argument, FWLockdownWhiteList &fwLockdownWhiteList);
