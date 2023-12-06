#include "firewalld-cpp-test.h"
#include <QCoreApplication>
#include <qcoreapplication.h>
#include "firewalld-config.h"

int main(int argc, char** argv) {

  QCoreApplication app(argc, argv);
  qWarning() << firewalld::config::zones();
  for(const auto& zone : firewalld::config::zones()) {
    qWarning() << zone->getDescription().value();
  }

  app.exec();
  return 0;
}
