#pragma once

#include <QString>

namespace firewalld::dbus {
inline static const QString kFirewallDDBusService =
    "org.fedoraproject.FirewallD1";
inline static const QString kFirewallDDBusBasePath =
    "/org/fedoraproject/FirewallD1";
inline static const QString kFirewallDDBusConfigPath =
    firewalld::dbus::kFirewallDDBusBasePath + "/config";
inline static const QString kDBusPropertiesIface =
    "org.freedesktop.DBus.Properties";
} // namespace firewalld::dbus
