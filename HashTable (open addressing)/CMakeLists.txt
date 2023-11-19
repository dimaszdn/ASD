cmake_minimum_required(VERSION 3.24)
project(HashTable_Open_addressing)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable_Open_addressing main.cpp inc/HashTable.h)
