add_executable ( q7ztest 
    data.qrc
    testq7z.cpp
)

include ( 7zdefs )

q7z_target_definitions( q7ztest )

target_link_libraries ( q7ztest  
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Test 
    Q7Zip::q7z
)
    
add_test ( NAME q7ztest COMMAND ${CMAKE_CURRENT_BINARY_DIR}/q7ztest )
