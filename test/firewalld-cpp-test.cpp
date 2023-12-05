#include "firewalld-cpp-test.h"
#include "../src/dbus/firewalld_interface.h"

A::A(QObject *parent) : QObject(parent) {
  f = new OrgFedoraprojectFirewallD1Interface("org.fedoraproject.FirewallD1",
                                              "/org/fedoraproject/FirewallD1",
                                              QDBusConnection::systemBus());
  qWarning() << "c'ted";
  connect(f, &OrgFedoraprojectFirewallD1Interface::Reloaded, this,
          []() { qWarning() << "reloaded"; });
}
