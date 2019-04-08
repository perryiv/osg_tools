
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#  MIT License: https://opensource.org/licenses/mit-license.html
#
################################################################################

################################################################################
#
#  CMake file for the OsgTools test program.
#
################################################################################

# Let the user set the include path for Catch2.
set ( CATCH2_INC_DIR $ENV{CATCH2_INC_DIR} CACHE STRING "Include path for Catch2 header file" )

# Does the user want to generate code coverage?
option ( OSG_TOOLS_ENABLE_CODE_COVERAGE
  "Generate test code coverage in supported configurations" OFF )
if ( OSG_TOOLS_ENABLE_CODE_COVERAGE )
  if ( UNIX ) # True for Linux, Mac, and Cygwin.
    message ( "   -- Generating test code coverage data" )
    add_compile_options ( -fprofile-arcs -ftest-coverage )
    if ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" )
      add_link_options ( --coverage )
    else() # GCC
      link_libraries ( gcov )
    endif()
  else()
    message ( WARNING "Test code coverage data not supported with current compiler" )
  endif()
endif()

# Add the include directory for catch.
include_directories ( ${CATCH2_INC_DIR} )

# Need to include files from this directory.
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR} )

# Define a variable that holds all the source files.
set ( SOURCE_FILES
  OsgTools/Main.cpp
  OsgTools/Groups/Group.cpp
  OsgTools/Math/Three.cpp
)

# Make an executable.
add_executable ( ${PROJECT_NAME}_test ${SOURCE_FILES} )

# Append a "d" to the file name if this is a debug build.
# Unlike with the library files, this does not happen automatically.
set_target_properties ( ${PROJECT_NAME}_test PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX} )

# Tell cmake we are going to use these libraries.
# It will automatically add -I, -L, and -D (etc) appropriately.
target_link_libraries ( ${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} )
