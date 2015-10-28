cmake_minimum_required(VERSION 3.3)
project(my_mpl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp abs.h power.h factorial.h intops.h euclid.h triangular_number.h sum.h inspect.h remove_const.h if.h enable_if.h traits.h)
add_executable(my_mpl ${SOURCE_FILES})