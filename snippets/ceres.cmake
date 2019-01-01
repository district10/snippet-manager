cmake_minimum_required(VERSION 2.8)

project(helloworld)

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

# helloworld
add_executable(helloworld helloworld.cc)
target_link_libraries(helloworld ${CERES_LIBRARIES})

    # Find a version of Ceres compiled with SuiteSparse & EigenSparse support.
    #
    # NOTE: This will report Ceres as **not** found if the detected version of
    #            Ceres was not compiled with both SuiteSparse & EigenSparse.
    #            Remember, if you have multiple versions of Ceres installed, you
    #            can use Ceres_DIR to specify which should be used.
    find_package(Ceres REQUIRED COMPONENTS SuiteSparse EigenSparse)
