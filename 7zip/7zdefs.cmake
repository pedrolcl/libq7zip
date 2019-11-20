add_definitions(-D_UNICODE -D_NO_CRYPTO)

if (WIN32)
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/win)
    include_directories(
        ${7ZIP_BASE}/C
        ${7ZIP_BASE}/CPP )

    add_definitions( -DWIN_LONG_PATH -D_CRT_SECURE_NO_WARNINGS -DUNICODE )
    if (MSVC)
        add_compile_options(-nologo -Zc:wchar_t -FS -Zc:strictStrings -Zi)
    endif()
endif()

if (UNIX) 
    set(7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/unix)
    include_directories (
        ${7ZIP_BASE}/C 
        ${7ZIP_BASE}/CPP 
        ${7ZIP_BASE}/CPP/myWindows 
        ${7ZIP_BASE}/CPP/include_windows )

    add_definitions( -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -DNDEBUG -D_REENTRANT -DENV_UNIX -DUNICODE )
endif()

if (APPLE)
    add_definitions(-DENV_MACOSX)
endif()

#disable warning messages:
#if (CMAKE_C_COMPILER_ID EQUAL GNU AND CMAKE_CXX_COMPILER_ID EQUAL GNU)
#    add_compile_options("-w")
#endif()
