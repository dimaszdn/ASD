cmake_minimum_required(VERSION 3.24)
project(Binary_tree)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Binary_tree main.cpp inc/BinaryTree.h)
