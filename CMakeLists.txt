cmake_minimum_required(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)
SET(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(shared_mem)

include(cmake/FetchSpdLog.cmake)

set(SOURCES
    src/boyer_moore.cpp
    src/pattern.cpp
    src/searchspace.cpp
)

add_library(boyer_moore STATIC ${SOURCES})
target_include_directories(boyer_moore PUBLIC include)
target_link_libraries(boyer_moore PUBLIC spdlog::spdlog)

add_subdirectory(examples)
# add_subdirectory(test)
