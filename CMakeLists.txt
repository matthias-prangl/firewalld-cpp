cmake_minimum_required(VERSION 3.22)
project("FirewallD cpp" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core DBus REQUIRED)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_subdirectory(src)
add_subdirectory(test)

