# OSG
find_package( OpenSceneGraph REQUIRED osgDB osgUtil osgViewer osgGA osgText osgFX osgQt osgAnimation osgParticle )
set( OSG_LIBRARIES
    debug ${OSG_LIBRARY_DEBUG}
    optimized ${OSG_LIBRARY}
    ${OSG_LIBRARIES}
)

target_link_libraries( ${PROJECT_NAME}
    ${QT_LIBRARIES}
    ${OSG_LIBRARIES}
    Utils btGUI )
