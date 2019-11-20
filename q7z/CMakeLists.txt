include(../7zip/7zdefs.cmake)

add_definitions(-DBUILD_LIB_Q7Z)

set ( q7z_SOURCES
	q7z_create.h
	q7z_errors.h
	q7z_extract.h
	q7z_facade.h
	q7z_fileio.h
	q7z_global.h
	q7z_guid.h
	q7z_list.h
	q7z_range.h
	q7z_facade.cpp
    q7z_fileio.cpp )

add_library ( q7z SHARED ${q7z_SOURCES})

if (WIN32)
    target_link_libraries ( q7z PRIVATE Qt5::Core Qt5::WinExtras 7z )
else()
    target_link_libraries ( q7z PRIVATE Qt5::Core 7z )
endif()
