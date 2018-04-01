if( NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/libpng-1.6.8 )
    if( NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/libpng-1.6.8.tar.gz )
        file( DOWNLOAD http://url/libpng-1.6.8.tar.gz ${CMAKE_CURRENT_BINARY_DIR}/libpng-1.6.8.tar.gz
              SHOW_PROGRESS EXPECTED_MD5 29b7065906e2551508a0d7eacd19174e )
    endif()
    execute_process( COMMAND ${CMAKE_COMMAND} -E tar xzf libpng-1.6.8.tar.gz )
endif()

# include/* -> include.zip
$ cmake -E tar cJ include.zip -- include

# include.zip -> include/*
$ cmake -E tar xJ include.zip
