cmake_minimum_required( VERSION 3.0 )
project( calculette )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

add_executable( calculette1.out src/calculette1.cpp )
add_executable( calculette2.out src/calculette2.cpp )

