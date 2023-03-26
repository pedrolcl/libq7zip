include (7zdefs)

if(WIN32)
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/win)
    include(win/CMakeLists.txt)
else()
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/unix)
    include(unix/CMakeLists.txt)
endif()

add_library( 7z STATIC $<TARGET_OBJECTS:obj7z> )

q7z_target_definitions( 7z )

set_target_properties( 7z PROPERTIES POSITION_INDEPENDENT_CODE ON)

if (APPLE)
    target_link_libraries(7z "-framework CoreFoundation")
endif()
