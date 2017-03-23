cmake_minimum_required( VERSION 3.0 )
project( chat )
#set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( PKG REQUIRED gtkmm-2.4 sfml-all )
include_directories( ${PKG_INCLUDE_DIRS} )

find_package( Boost COMPONENTS thread system REQUIRED )

add_executable( client.out src/client/client.cpp src/client/Ui.cpp src/client/Net.cpp )
target_link_libraries( client.out ${PKG_LIBRARIES} 
    ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} )

add_executable( server.out src/server/server.cpp src/server/Server.cpp )
target_link_libraries( server.out ${PKG_LIBRARIES} )

install (TARGETS client.out server.out DESTINATION bin)

