cmake_minimum_required( VERSION 3.0 )
project( mediatheque )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

set( SOURCES src/Media.cpp src/Mediatheque.cpp src/Utilisateur.cpp )

add_executable( mediatheque.out src/main.cpp ${SOURCES} )

