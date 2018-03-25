cmake_minimum_required( VERSION 2.8.12 )  # Ships with Ubuntu 14.04 (Trusty)

project( CMAKE )
set(APP_MAJOR_VERSION 1)
set(APP_MINOR_VERSION 0)
set(APP_PATCH_VERSION 0)
set(APP_VERSION ${APP_MAJOR_VERSION}.${APP_MINOR_VERSION}.${APP_PATCH_VERSION})

set( CMAKE_COLOR_MAKEFILE ON )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
mark_as_advanced( CMAKE_VERBOSE_MAKEFILE ) # Allow advanced users to generate Makefiles printing detailed commands

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_CAPITALIZED)
add_definitions(-DUNICODE)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")

set( CMAKE_BUILD_TYPE "Debug" )
set_source_files_properties(hello.c useHello.c PROPERTIES LANGUAGE CXX )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )
include_directories( ${CMAKE_SOURCE_DIR}/includes )
include_directories( ${CMAKE_BINARY_DIR} )
configure_file(
        "${PROJECT_SOURCE_DIR}/configs.h.in"
        "${PROJECT_BINARY_DIR}/configs.h" )
link_directories( ${CMAKE_SOURCE_DIR}/lib/Debug ${CMAKE_SOURCE_DIR}/lib/Release ${CMAKE_BINARY_DIR}/ )

set( LIBRARY_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin
    CACHE
    PATH
    "Single directory for all libraries" )
set( EXECUTABLE_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin
    CACHE
    PATH
    "Single directory for all executables" )

add_subdirectory( src )
add_library( a STATIC a.cpp )
add_library( b SHARED b.cpp )
add_executable( ${PROJECT_NAME} main.c )
target_link_libraries( ${PROJECT_NAME}  a b )

file( GLOB SRCS *.c *.cpp *.cc *.h *.hpp )
add_executable( ${PROJECT_NAME} ${SRCS} )
