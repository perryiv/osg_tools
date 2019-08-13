
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

# We want position independent code.
set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# Define a variable that holds all the source files.
set ( SOURCE_FILES
  OsgTools/Builders/Builder.cpp
  OsgTools/Builders/Primitive.cpp
  OsgTools/Builders/Rectangle.cpp
  OsgTools/Builders/Sphere.cpp
  OsgTools/Group/Group.cpp
  OsgTools/Strings/Format.cpp
)

# Make the library using the source files.
# Hey CMake, here is a library and all the stuff you need to know about it.
add_library ( ${PROJECT_NAME} ${SOURCE_FILES} )

# We are compling osg_tools.
target_compile_definitions ( ${PROJECT_NAME} PRIVATE COMPILING_OSG_TOOLS )

if ( NOT BUILD_SHARED_LIBS )
  target_compile_definitions ( ${PROJECT_NAME} PUBLIC OSG_TOOLS_STATIC_DEFINE )
endif()

# Tell cmake that other projects that use this one will need our header files.
target_include_directories (
  ${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${OSG_TOOLS_CONFIG_DIR_OUTPUT}>
  $<INSTALL_INTERFACE:include>
)

# CMake will automatically add -I, -L, and -D (etc) appropriately.
target_link_libraries ( ${PROJECT_NAME} PUBLIC
  OpenGL::GL
  OpenSceneGraph::OSG
  usul
)

# Bake the version into the file name and create symlinks if appropriate.
set_target_properties ( ${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Tell cmake how to install the headers and binaries if the user types
# "make install" or compiles the Visual C++ INSTALL project. The default
# directory prefix is /usr/local or "C:/Program Files", and can be changed
# on the command line with -DCMAKE_INSTALL_PREFIX=/some/path.
install (
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_targets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install (
  DIRECTORY OsgTools
  DESTINATION include FILES_MATCHING PATTERN "*.h"
)
