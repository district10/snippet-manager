find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
set( QT_DONT_USE_QTGUI TRUE )
target_link_libraries( ${PROJECT_NAME}  ${QT_LIBRARIES} )

file( GLOB_RECURSE HDRS_FILES *.h *.hpp )
file( GLOB_RECURSE SRCS_FILES *.cpp )
file( GLOB_RECURSE UI_FILES *.ui )

qt4_wrap_cpp( MOC_SRCS ${HDRS_FILES} )
qt4_wrap_ui( UI_HDRS ${UI_FILES} )

source_group( "UI Files" FILES ${UI_FILES} )
source_group( "Generated Files" FILES ${MOC_SRCS} ${UI_HDRS} )
add_library( lib STATIC ${SRCS_FILES} ${UI_FILES} ${HDRS_FILES} ${MOC_SRCS} ${UI_HDRS} )
target_link_libraries( lib ${QT_LIBRARIES} )

target_link_libraries( ${PROJECT_NAME} ${QT_LIBRARIES} lib )

file( GLOB BT_RCS_RAW *.qrc )
qt4_add_resources( BT_RCS ${BT_RCS_RAW} )
add_executable( ${PROJECT_NAME} main.cpp ${BT_RCS} )
