project( CMAKE )
cmake_minimum_required( VERSION 2.6 )

include_directories( ${CMAKE_SOURCE_DIR}/includes )
add_subdirectory( src )
add_library( a STATIC a.cpp )
add_library( b SHARED b.cpp )

add_executable( ${PROJECT_NAME} main.c )
target_link_libraries( ${PROJECT_NAME}  a b )

file( GLOB SRCS *.c *.cpp *.cc *.h *.hpp )
add_executable( ${PROJECT_NAME} ${SRCS} )
