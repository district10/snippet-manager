# large address aware option setting
if( ${MINGW} )
    set( LARGEADDRESSAWARE "--large-address-aware" )
else( ${MINGW} )
    if ( WIN32 )
        set( LARGEADDRESSAWARE "/LARGEADDRESSAWARE" )
    else ( WIN32 )
        set( LARGEADDRESSAWARE " " )
    endif ( WIN32 )
endif( ${MINGW} )

if ( WIN32)
    SET( APP_OPT "WIN32" )
else ( WIN32 )
    if ( APPLE )
        #SET( APP_OPT "MACOSX_BUNDLE" )
        SET( APP_OPT "EXCLUDE_FROM_ALL" )
    else ( APPLE )
        SET( APP_OPT " " )
    endif ( APPLE )
endif ( WIN32 )