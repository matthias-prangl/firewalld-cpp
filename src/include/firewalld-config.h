#pragma once

#include "firewalld-config-zone.h"

namespace firewalld::config {
QList<QSharedPointer<Zone>> zones();
}
