cmake_minimum_required(VERSION 3.7)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/sorting.cpp src/searching.cpp)
include_directories(include)

add_executable(algorithms ${SOURCE_FILES})