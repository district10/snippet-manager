set_source_files_properties( ${CD_FILES} PROPERTIES HEADER_FILE_ONLY TRUE) #DO NOT COMPILE CS FILES
target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} ${OpenCV_LIBS} Utils SignLogger SignTransformer )
set_target_properties( ${PROJECT_NAME} PROPERTIES LINK_FLAGS ${LARGEADDRESSAWARE} )
set_target_properties( ${PROJECT_NAME} PROPERTIES FOLDER Src )
set_target_properties( ${PROJECT_NAME} PROPERTIES VS_KEYWORD Qt4VSv1.0 )
install( TARGETS ${PROJECT_NAME} DESTINATION bin )
