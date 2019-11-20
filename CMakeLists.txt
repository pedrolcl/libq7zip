cmake_minimum_required( VERSION 3.1 )

project(q7zip)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (WIN32)
    find_package(Qt5 COMPONENTS Core Test WinExtras REQUIRED)
else()
    find_package(Qt5 COMPONENTS Core Test REQUIRED)
endif()

add_subdirectory( 7zip )
add_subdirectory( q7z )

enable_testing()
add_subdirectory( tests )
