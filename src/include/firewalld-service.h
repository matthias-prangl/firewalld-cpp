#pragma once

#include "generictypes.h"

namespace firewalld {
class Service {
public:
  Service(const QVariantMap serviceSettings);

private:
  QString version_;
  QString name_;
  QString description_;
  FWPortList ports_;
  QStringList moduleNames_;
  FWStringMap destinations_;
  QStringList protocols_;
  FWPortList sourcePorts_;
  QStringList includes_;
  QStringList helpers_;
};
} // namespace firewalld
