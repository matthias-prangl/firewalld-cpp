add_executable(firewalld-cpp-test main.cpp firewalld-cpp-test.cpp)
target_link_libraries(firewalld-cpp-test PRIVATE firewalld-cpp Qt6::Core Qt6::DBus)
set_target_properties(firewalld-cpp-test PROPERTIES AUTOMOC TRUE)

target_include_directories(firewalld-cpp-test PRIVATE ../src/include)
target_compile_options(firewalld-cpp-test PRIVATE -fPIC)

