# compile all sources in current directory
file( GLOB SRCS *.c *.cpp *.cc *.h *.hpp )  # a varible called SRCS with all files whose path match "*.c *.cpp..."
set( PROGRAM_TARGETS
    SeedFillTest
    SuperSeedsTest
    BoundaryFillTest
    contours
)
foreach( TARGET_NAME ${PROGRAM_TARGETS} )
    add_executable( ${TARGET_NAME} ${TARGET_NAME}.cpp )
    # add_dependencies( ${TARGET_NAME} Blahblah )
    target_link_libraries( ${TARGET_NAME} ${OpenCV_LIBS} ${QT_LIBRARIES} Blahblah )
    set_target_properties( ${TARGET_NAME} PROPERTIES FOLDER MiscExamples )
endforeach( TARGET_NAME )

##################################
file( GLOB SRCS *.cpp)
foreach( src ${SRCS} )
    string( REGEX REPLACE "(^.*/|.cpp$)" "" exe ${src} )
    add_executable( ${exe} ${src} )
    target_link_libraries( ${exe}
        openMVG_image
        openMVG_features
        openMVG_matching
        openMVG_system
        openMVG_multiview
        vlsift
        stlplus)
    set_property(TARGET ${exe} PROPERTY FOLDER OpenMVG/Samples)
endforeach( src )
