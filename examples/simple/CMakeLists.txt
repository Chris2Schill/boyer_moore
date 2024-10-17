cmake_minimum_required(VERSION 3.0)

project(simple)

configure_file(searchspace.txt ${CMAKE_CURRENT_BINARY_DIR})
add_executable(simple simple.cpp)
target_link_libraries(simple PRIVATE boyer_moore)
