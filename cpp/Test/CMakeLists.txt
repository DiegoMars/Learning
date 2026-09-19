cmake_minimum_required(VERSION 3.10)

project(Test)

find_package(fmt CONFIG REQUIRED)

add_executable(Test helloworld.cpp)

target_link_libraries(Test PRIVATE fmt::fmt)
