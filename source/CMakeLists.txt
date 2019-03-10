
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

# We are compling osg_tools.
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

# Tell cmake how to install the headers and binaries if the user types
# "make install" or compiles the Visual C++ INSTALL project. The default
# directory prefix is /usr/local or "C:/Program Files", and can be changed
# on the command line with -DCMAKE_INSTALL_PREFIX=/some/path.
install ( TARGETS ${PROJECT_NAME} DESTINATION lib )
install ( DIRECTORY ${OSG_TOOLS_INC_DIR}/OsgTools DESTINATION include FILES_MATCHING PATTERN "*.h" )
