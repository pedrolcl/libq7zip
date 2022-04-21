cmake_minimum_required( VERSION 3.1 )

project(q7zip)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test REQUIRED)

add_subdirectory( 7zip )
add_subdirectory( q7z )

if (NOT ANDROID)
    enable_testing()
    add_subdirectory( tests )
endif()
