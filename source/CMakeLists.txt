
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#  MIT License: https://opensource.org/licenses/mit-license.html
#
################################################################################

################################################################################
#
#  CMake file for the library.
#
################################################################################

# We are compling usul.
add_compile_definitions ( COMPILING_OSG_TOOLS )

# We want position independent code.
set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# Define a variable that holds all the source files.
set ( SOURCE_FILES
  OsgTools/Group.cpp
)

# Make the library using the source files.
add_library ( ${PROJECT_NAME} SHARED ${SOURCE_FILES} )

# Tell cmake that other projects that use this one will need
# the header files from OSG_TOOLS_INC_DIR.
target_include_directories ( ${PROJECT_NAME} INTERFACE ${OSG_TOOLS_INC_DIR} )

# CMake will automatically add -I, -L, and -D (etc) appropriately.
target_link_libraries ( ${PROJECT_NAME} PUBLIC
  OpenGL::GL
  OpenSceneGraph::OSG
  debug usul${CMAKE_DEBUG_POSTFIX}
  optimized usul
)

# Bake the version into the file name and create symlinks if appropriate.
set_target_properties ( ${PROJECT_NAME} PROPERTIES
  VERSION ${OSG_TOOLS_VERSION_STRING}
  SOVERSION ${OSG_TOOLS_VERSION_MAJOR}
)
