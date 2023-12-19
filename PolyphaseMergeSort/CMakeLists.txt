cmake_minimum_required(VERSION 3.24)
project(PolyphaseMergeSort)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(PolyphaseMergeSort main.cpp inc/PolyphaseMergeSort.h inc/QuickSort.h)
