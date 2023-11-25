cmake_minimum_required(VERSION 3.24)
project(Hash_Table__chain_method_)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Hash_Table__chain_method_ main.cpp inc/HashTable.h)

file(COPY "files" DESTINATION "/")