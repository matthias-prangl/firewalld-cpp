cmake_minimum_required(VERSION 3.22)
project("FirewallD cpp" LANGUAGES CXX)

add_compile_options(-Wall -Wextra -pedantic -Werror)

find_package(sdbus-c++ REQUIRED)
find_package(spdlog REQUIRED)
add_library(firewalld-cpp SHARED src/firewalld-proxy.cpp)
target_link_libraries(firewalld-cpp PRIVATE SDBusCpp::sdbus-c++ spdlog::spdlog)
target_include_directories(firewalld-cpp PRIVATE generated/include)
