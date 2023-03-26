macro ( q7z_target_definitions target )
    if (TARGET ${target})
        target_compile_definitions(${target} PUBLIC -D_UNICODE -D_NO_CRYPTO)

        if (WIN32)
            set( _7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/win )
            target_include_directories(${target} PUBLIC
                $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/q7z>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/C>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/CPP>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/C>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/CPP>
            )
            target_compile_definitions(${target} PUBLIC -DWIN_LONG_PATH -D_CRT_SECURE_NO_WARNINGS -DUNICODE )
            if (MSVC)
                target_compile_options(${target} PUBLIC -nologo -Zc:wchar_t -FS -Zc:strictStrings -Zi)
            endif()
        endif()

        if (UNIX)
            set( _7ZIP_BASE ${PROJECT_SOURCE_DIR}/7zip/unix )
            target_include_directories (${target} PUBLIC
                $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/q7z>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/C>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/CPP>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/CPP/myWindows>
                $<BUILD_INTERFACE:${_7ZIP_BASE}/CPP/include_windows>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/C>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/CPP>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/CPP/myWindows>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/q7zip/CPP/include_windows>
            )
            target_compile_definitions( ${target} PUBLIC
                -D_FILE_OFFSET_BITS=64
                -D_LARGEFILE_SOURCE
                -DNDEBUG
                -D_REENTRANT
                -DENV_UNIX
                -DUNICODE
            )
        endif()

        if (APPLE)
            target_compile_definitions(${target} PUBLIC -DENV_MACOSX)
        endif()
    endif()
endmacro()
