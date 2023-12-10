#pragma once

#include "dbus/firewalld_interface.h"

namespace firewalld::runtime {

class FirewallD;

class FirewallDPrivate : public QObject {
  Q_OBJECT

public:
  explicit FirewallDPrivate(FirewallD *q);
  ~FirewallDPrivate() override;
  void init();

  bool bridge;
  bool ipSet;
  QStringList ipSetTypes;
  bool ipv4;
  QStringList ipv4ICMPTypes;
  bool ipv6;
  QStringList ipv6ICMPTypes;
  bool ipv6_rpfilter;
  QString interface_version;
  QString state;
  QString version;

  OrgFedoraprojectFirewallD1Interface firewalldIface_;
  FirewallD *q_ptr;
  Q_DECLARE_PUBLIC(FirewallD)

public slots:
  void firewalldAutomaticHelpersChanged(const QString &value);
  void firewalldDefaultZoneChanged(const QString &zone);
  void firewalldLogDeniedChanged(const QString &value);
  void firewalldPanicModeDisabled();
  void firewalldPanicModeEnabled();
  void firewalldReloaded();
};
} // namespace firewalld::runtime
