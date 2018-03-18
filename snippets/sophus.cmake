find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )
IF( NOT Sophus_LIBRARIES )
    SET( Sophus_LIBRARIES "libSophus.so" )
ENDIF()
message( STATUS "Sophus library status:" )
message( STATUS "    includes: ${Sophus_INCLUDE_DIRS}" )
message( STATUS "    libraries: ${Sophus_LIBRARIES}" )
# -- Sophus library status:
# --     includes: /usr/local/lib/cmake/Sophus/../../../include
# --     libraries: libSophus.so
