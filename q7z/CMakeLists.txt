include(7zdefs)

set ( q7z_HEADERS
    q7z_create.h
    q7z_errors.h
    q7z_extract.h
    q7z_facade.h
    q7z_fileio.h
    q7z_global.h
    q7z_guid.h
    q7z_list.h
    q7z_range.h
)

set ( q7z_SOURCES
    q7z_facade.cpp
    q7z_fileio.cpp
)

add_library ( q7z SHARED ${q7z_HEADERS} ${q7z_SOURCES} )

q7z_target_definitions ( q7z )

target_compile_definitions( q7z PRIVATE -DBUILD_LIB_Q7Z )

target_link_libraries ( q7z PRIVATE Qt${QT_VERSION_MAJOR}::Core 7z )

set_target_properties ( q7z PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${q7z_HEADERS}"
)

add_library ( Q7Zip::q7z ALIAS q7z )

install(TARGETS q7z EXPORT Q7ZipExports
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    OBJECTS DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FRAMEWORK DESTINATION ${CMAKE_INSTALL_LIBDIR}
    BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/q7zip
    RESOURCE DESTINATION ${CMAKE_INSTALL_DATADIR}/q7zip
)

if(WIN32)
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/win/)
else()
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/unix/)
endif()

install( DIRECTORY "${7ZIP_BASE}"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/q7zip"
    FILES_MATCHING
    PATTERN "*.h"
)

install( EXPORT Q7ZipExports
    FILE Q7ZipTargets.cmake
    NAMESPACE Q7Zip::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Q7Zip
)

export ( EXPORT Q7ZipExports
    FILE ${PROJECT_BINARY_DIR}/Q7ZipTargets.cmake
    NAMESPACE Q7Zip::
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file (
    ${PROJECT_BINARY_DIR}/Q7ZipConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file (
    ${PROJECT_SOURCE_DIR}/Q7ZipConfig.cmake.in
    ${PROJECT_BINARY_DIR}/Q7ZipConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Q7Zip
)

install(FILES
    ${PROJECT_BINARY_DIR}/Q7ZipConfig.cmake
    ${PROJECT_BINARY_DIR}/Q7ZipConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Q7Zip
)
