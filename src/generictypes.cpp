#include "generictypes.h"

QDBusArgument &operator<<(QDBusArgument &argument,
                          const FWIcmpTypeSettings &icmpTypeSettings) {
  argument.beginStructure();
  argument << icmpTypeSettings.version << icmpTypeSettings.name
           << icmpTypeSettings.description << icmpTypeSettings.destinations;
  argument.endStructure();
  return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument,
                                FWIcmpTypeSettings &icmpTypeSettings) {
  argument.beginStructure();
  argument >> icmpTypeSettings.version >> icmpTypeSettings.name >>
      icmpTypeSettings.description >> icmpTypeSettings.destinations;
  argument.endStructure();
  return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument,
                          const FWHelperSettings &helperSettings) {
  argument.beginStructure();
  argument << helperSettings.version << helperSettings.name
           << helperSettings.description << helperSettings.family
           << helperSettings.module << helperSettings.ports;
  argument.endStructure();
  return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument,
                                FWHelperSettings &helperSettings) {
  argument.beginStructure();
  argument >> helperSettings.version >> helperSettings.name >>
      helperSettings.description >> helperSettings.family >>
      helperSettings.module >> helperSettings.ports;
  argument.endStructure();
  return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument,
                          const FWIPSetSettings &ipSetSettings) {
  argument.beginStructure();
  argument << ipSetSettings.version << ipSetSettings.name
           << ipSetSettings.description << ipSetSettings.type
           << ipSetSettings.options << ipSetSettings.entries;
  argument.endStructure();
  return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument,
                                FWIPSetSettings &ipSetSettings) {
  argument.beginStructure();
  argument >> ipSetSettings.version >> ipSetSettings.name >>
      ipSetSettings.description >> ipSetSettings.type >>
      ipSetSettings.options >> ipSetSettings.entries;
  argument.endStructure();
  return argument;
}

QDBusArgument &operator<<(QDBusArgument &argument,
                          const FWLockdownWhiteList &lockdownWhiteList) {
  argument.beginStructure();
  argument << lockdownWhiteList.commands << lockdownWhiteList.selinuxContexts
           << lockdownWhiteList.users << lockdownWhiteList.uids;
  argument.endStructure();
  return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument,
                                FWLockdownWhiteList &lockdownWhiteList) {
  argument.beginStructure();
  argument >> lockdownWhiteList.commands >> lockdownWhiteList.selinuxContexts >>
      lockdownWhiteList.users >> lockdownWhiteList.uids;
  argument.endStructure();
  return argument;
}
