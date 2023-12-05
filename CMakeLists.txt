cmake_minimum_required(VERSION 3.22)
project("FirewallD cpp" LANGUAGES CXX)

add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core DBus REQUIRED)
add_library(firewalld-cpp SHARED src/dbus/firewalld_config_zone_interface.cpp)
target_link_libraries(firewalld-cpp PRIVATE Qt5::DBus Qt5::Core)
