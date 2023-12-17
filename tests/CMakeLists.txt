cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

project(tests)

add_executable(test_normal test.cpp ../signal/filter.cpp)

add_executable(test_single_header test.cpp)
target_compile_definitions(
    test_single_header
    PRIVATE
    SCIPY_SIGNAL_SINGLE_HEADER
)

enable_testing()
add_test(NAME test1 COMMAND test_normal)
add_test(NAME test2 COMMAND test_single_header)
