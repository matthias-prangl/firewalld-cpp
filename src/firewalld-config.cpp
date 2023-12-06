#include "firewalld-config_p.h"
#include "firewalld_dbus.h"
#include "firewalld-config.h"
#include <qdbusconnection.h>

Q_GLOBAL_STATIC(firewalld::config::FirewallDConfigPrivate,
                globalFirewallDConfig)

firewalld::config::FirewallDConfigPrivate::FirewallDConfigPrivate()
    : iface_(firewalld::dbus::kFirewallDDBusService,
             firewalld::dbus::kFirewallDDBusConfigPath,
             QDBusConnection::systemBus()) {
  init();
}

void firewalld::config::FirewallDConfigPrivate::init() {
  if (!iface_.isValid()) {
    return;
  }
  auto zonesReply = iface_.listZones();
  zonesReply.waitForFinished();

  if (zonesReply.isError()) {
    return;
  }

  for (const auto &zonePath : zonesReply.value()) {
    const QString &path = zonePath.path();
    zoneMap_.insert(path, QSharedPointer<Zone>::create(path));
  }
}

QList<QSharedPointer<firewalld::config::Zone>> firewalld::config::zones() {
  QList<QSharedPointer<Zone>> zones;
  for (auto i = globalFirewallDConfig->zoneMap_.cbegin();
       i != globalFirewallDConfig->zoneMap_.cend(); ++i) {
    zones.append(i.value());
  }
  return zones;
}
