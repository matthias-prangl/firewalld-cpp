#include "../src/dbus/firewalld_interface.h"
#include <QObject>

class A : public QObject {
 Q_OBJECT
public:
  A(QObject *parent = nullptr);
  OrgFedoraprojectFirewallD1Interface *f;
};
