cmake_minimum_required(VERSION 3.22)
project("FirewallD cpp" LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core DBus REQUIRED)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_subdirectory(src)
add_subdirectory(test)

