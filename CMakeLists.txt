cmake_minimum_required( VERSION 3.14 )

project ( Q7Zip
    LANGUAGES C CXX
    VERSION 1.0.0
)

list ( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/7zip )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (ANDROID)
    set(BUILD_TESTING_INIT OFF)
else()
    set(BUILD_TESTING_INIT ON)
endif()

option ( BUILD_TESTING "Build Unit Tests" ${BUILD_TESTING_INIT} )
option ( USE_QT5 "Use Qt5 libraries instead of Qt6" OFF )

if (USE_QT5)
    find_package(QT NAMES Qt5 REQUIRED)
else()
    find_package(QT NAMES Qt6 REQUIRED)
endif()

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test REQUIRED)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    set(CMAKE_CXX_STANDARD 17)
else()
    set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(GNUInstallDirs)

add_subdirectory( 7zip )
add_subdirectory( q7z )

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory( tests )
endif()
