cmake_minimum_required(VERSION 2.8)
project( First_Sorting_Algos )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable( bubble bubble.cpp )
add_executable( insertion insertion.cpp )
add_executable( selection selection.cpp )
add_executable( merge merge.cpp )
add_executable( quick quick.cpp )
add_executable( heap heap.cpp)
add_executable( count count.cpp )



