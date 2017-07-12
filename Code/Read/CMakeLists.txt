cmake_minimum_required(VERSION 3.7)
project(Read)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Data.cpp)
add_executable(Read ${SOURCE_FILES})