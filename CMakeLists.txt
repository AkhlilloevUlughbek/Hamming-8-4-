cmake_minimum_required(VERSION 3.10)

project(hamming1)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_library(hamming1 hamming1.h hamming1.cpp)

add_executable(prog main.cpp)

target_link_libraries(prog PRIVATE hamming1)