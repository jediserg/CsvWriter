cmake_minimum_required(VERSION 3.6)
project(CsvWriter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CsvWriter.cpp CsvWriter.h)
add_executable(CsvWriter ${SOURCE_FILES})