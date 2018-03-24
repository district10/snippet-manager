find_package( G2O REQUIRED )

include_directories( ${G2O_INCLUDE_DIRS} )

target_link_libraries( exe
   ${OpenCV_LIBS}
   ${CSPARSE_LIBRARY}
   g2o_core g2o_stuff g2o_types_sba g2o_csparse_extension
)
