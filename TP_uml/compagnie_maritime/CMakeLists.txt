cmake_minimum_required( VERSION 3.0 )
project( compagnie_maritime )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

set( SOURCES src/Compagnie.cpp src/Bateau.cpp )

add_executable( compagnie_maritime.out src/main.cpp ${SOURCES} )

