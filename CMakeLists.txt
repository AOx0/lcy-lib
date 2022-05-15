cmake_minimum_required(VERSION 3.21)
project(test)

add_executable(test test.cpp)
target_link_libraries(test ${CMAKE_SOURCE_DIR}/target/release/liblcy_lib_c.a)