include (7zdefs.cmake)

if(WIN32)
    include(win/CMakeLists.txt)
else()
    include(unix/CMakeLists.txt)
endif()

add_library ( 7z STATIC $<TARGET_OBJECTS:obj7z> )
set_target_properties( 7z PROPERTIES POSITION_INDEPENDENT_CODE ON)
