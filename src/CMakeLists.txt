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

add_library(firewalld-cpp SHARED ${DBUS_INTERFACE_SOURCES})
set_target_properties(firewalld-cpp PROPERTIES AUTOMOC TRUE)
include_directories(include)
target_link_libraries(firewalld-cpp PRIVATE Qt5::DBus Qt5::Core)
