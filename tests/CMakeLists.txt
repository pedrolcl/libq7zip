include(../7zip/7zdefs.cmake)

add_executable ( q7ztest 
    data.qrc
    testq7z.cpp )

target_link_libraries ( q7ztest  
    Qt5::Core 
    Qt5::Test 
    q7z )

target_include_directories ( q7ztest PRIVATE ../q7z )
    
add_test ( NAME q7ztest COMMAND ${CMAKE_CURRENT_BINARY_DIR}/q7ztest )
