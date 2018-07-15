cmake_minimum_required(VERSION 2.8)
project( N_QUEEN_PROBLEM )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable( queen queen.cpp )
add_executable( bound bound.cpp )
add_executable( back back.cpp )





