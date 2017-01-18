cmake_minimum_required( VERSION 2.6 )
project( drawspline )
set( CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra" )

find_package( PkgConfig REQUIRED )
pkg_check_modules( MYPKG REQUIRED libglog )
include_directories( ${MYPKG_INCLUDE_DIRS} )

add_executable( drawspline.out 
    src/Spline.cpp
    src/Vec2.cpp
    src/drawspline.cpp )
target_link_libraries( drawspline.out ${MYPKG_LIBRARIES} )

