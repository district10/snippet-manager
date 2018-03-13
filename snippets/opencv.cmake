find_package( OpenCV REQUIRED )
# include( $ENV{OpenCV2_DIR}/OpenCVConfig.cmake )
message( STATUS "OpenCV library status:" )
message( STATUS "    version: ${OpenCV_VERSION}" )
message( STATUS "    libraries: ${OpenCV_LIBS}" )
message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
