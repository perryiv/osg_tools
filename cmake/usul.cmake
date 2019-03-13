
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#  MIT License: https://opensource.org/licenses/mit-license.html
#
################################################################################

################################################################################
#
#  Configure usul if it has not been defined already.
#
################################################################################

if ( NOT TARGET usul )
  set ( USUL_INC_DIR $ENV{USUL_INC_DIR} CACHE PATH "Include path for Usul header files" )
  add_library ( usul INTERFACE IMPORTED )
  target_include_directories ( usul INTERFACE ${USUL_INC_DIR} )
  set ( USUL_LIB_DIR $ENV{USUL_LIB_DIR} CACHE PATH "Include path for Usul library files" )
  find_library ( USUL_LIBRARY usul HINTS ${USUL_LIB_DIR} )
  find_library ( USUL_LIBRARY_DEBUG usuld HINTS ${USUL_LIB_DIR} )
  set ( USUL_LIBRARIES )
  if ( USUL_LIBRARY_DEBUG ) # If the debug library is defined.
    set ( USUL_LIBRARIES ${USUL_LIBRARIES} $<$<CONFIG:Debug>:${USUL_LIBRARY_DEBUG}> )
    if ( USUL_LIBRARY ) # Assume this is release.
      set ( USUL_LIBRARIES ${USUL_LIBRARIES} $<$<NOT:$<CONFIG:Debug>>:${USUL_LIBRARY}> )
    endif()
  elseif ( USUL_LIBRARY ) # No assumptions about release or debug.
    set ( USUL_LIBRARIES ${USUL_LIBRARIES} ${USUL_LIBRARY} )
  endif()
  target_link_libraries ( usul INTERFACE ${USUL_LIBRARIES} )
endif()
