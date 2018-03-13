find_package( Pangolin )
include_directories( ${Pangolin_INCLUDE_DIRS} )

target_link_libraries( exe ${Pangolin_LIBRARIES} )
