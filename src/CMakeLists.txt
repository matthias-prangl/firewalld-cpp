set(DBUS_INTERFACE_SOURCES
  dbus/firewalld_config_helper_interface.cpp
  dbus/firewalld_config_icmptype_interface.cpp
  dbus/firewalld_config_interface.cpp
  dbus/firewalld_config_ipset_interface.cpp
  dbus/firewalld_config_policy_interface.cpp
  dbus/firewalld_config_service_interface.cpp
  dbus/firewalld_config_zone_interface.cpp
  dbus/firewalld_interface.cpp
)

set(SOURCES
  firewalld-config.cpp
  firewalld-config-policies.cpp
  firewalld-config-service.cpp
  firewalld-config-zone.cpp
  firewalld-internal.cpp
  firewalld-rt.cpp
  firewalld-rt-zone.cpp
  firewalld-service.cpp
  generictypes.cpp
)

set(HEADERS 
  include/firewalld-config.h
  include/firewalld-config-policies.h
  include/firewalld-config-service.h
  include/firewalld-config-zone.h
  include/firewalld-rt.h
  include/firewalld-rt-zone.h
  include/firewalld-service.h
  include_p/firewalld-config_p.h
  include_p/firewalld-config-policies_p.h
  include_p/firewalld-config-service_p.h
  include_p/firewalld-config-zone_p.h
  include_p/firewalld-internal.h
  include_p/firewalld-rt_p.h
  include_p/firewalld-rt-zone_p.h
)

add_library(firewalld-cpp SHARED ${SOURCES} ${HEADERS} ${DBUS_INTERFACE_SOURCES})
set_target_properties(firewalld-cpp PROPERTIES AUTOMOC TRUE)
target_include_directories(firewalld-cpp PUBLIC include)
target_include_directories(firewalld-cpp PRIVATE include_p dbus)
target_link_libraries(firewalld-cpp PRIVATE Qt6::DBus Qt6::Core)
