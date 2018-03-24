project( CMAKE )
cmake_minimum_required( VERSION 2.6 )

set( CMAKE_BUILD_TYPE "Debug" )
set_source_files_properties(hello.c useHello.c PROPERTIES LANGUAGE CXX )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )

include_directories( ${CMAKE_SOURCE_DIR}/includes )
include_directories( ${CMAKE_BINARY_DIR} )
configure_file(
        "${PROJECT_SOURCE_DIR}/configs.h.in"
        "${PROJECT_BINARY_DIR}/configs.h" )

add_subdirectory( src )
add_library( a STATIC a.cpp )
add_library( b SHARED b.cpp )

add_executable( ${PROJECT_NAME} main.c )
target_link_libraries( ${PROJECT_NAME}  a b )

file( GLOB SRCS *.c *.cpp *.cc *.h *.hpp )
add_executable( ${PROJECT_NAME} ${SRCS} )

