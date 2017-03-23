cmake_minimum_required( VERSION 2.6 )
project( fibo )
set( CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra" )

add_executable( print_fibo.out 
    src/Fibo.cpp
    src/print_fibo.cpp )

