#include "firewalld-config-policies.h"
#include "firewalld_config_interface.h"

namespace firewalld::config {

class ConfigPoliciesPrivate : public QObject {
  Q_OBJECT
public:
  explicit ConfigPoliciesPrivate(ConfigPolicies *q);
  ~ConfigPoliciesPrivate() override;
  void init();

  OrgFedoraprojectFirewallD1ConfigPoliciesInterface configPoliciesIface_;
  ConfigPolicies *q_ptr;

  Q_DECLARE_PUBLIC(ConfigPolicies)
public slots:
  void configLockdownWhitelistUpdated();
};

} // namespace firewalld::config
