ckage( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

target_link_libraries( exe ${Sophus_LIBRARIES} )
