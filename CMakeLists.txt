
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#  MIT License: https://opensource.org/licenses/mit-license.html
#
################################################################################

################################################################################
#
#  Top-level CMake file for the osg_tools project.
#
#  Sources:
#  https://doc.qt.io/qt-5/cmake-manual.html
#  https://vicrucann.github.io/tutorials/cmake-qt-osg-1/
#  https://stackoverflow.com/questions/10851247/how-to-activate-c-11-in-cmake
#  https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
#  https://stackoverflow.com/questions/2368811/how-to-set-warning-level-in-cmake/50882216
#  https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=vs-2017
#  https://softwareengineering.stackexchange.com/questions/88532/whether-to-use-pedantic-flag-in-g-or-not
#  https://stackoverflow.com/questions/4001736/whats-up-with-the-thousands-of-warnings-in-standard-headers-in-msvc-wall
#  http://cmake.3232098.n2.nabble.com/Directing-cmake-to-link-against-shared-object-with-debug-postfix-d-td7595338.html
#  https://stackoverflow.com/questions/16682606/how-to-resovle-gcov-init-undefined-reference-issue-when-link
#  https://cmake.org/cmake/help/v3.13/module/FindOpenSceneGraph.html?highlight=findopenscenegraph
#  https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file
#
################################################################################

# We use the add_compile_definitions command.
# https://cmake.org/cmake/help/v3.12/release/3.12.html
cmake_minimum_required ( VERSION 3.12.0 )

# The name of this project.
project ( osg_tools VERSION 0.1.0 )

# Use this C++ standard unless the user specifies otherwise with:
# cmake path/to/source/dir -DCMAKE_CXX_STANDARD=14
if ( NOT DEFINED CMAKE_CXX_STANDARD )
  set ( CMAKE_CXX_STANDARD 17 )
endif()

# Turn off compiler-specific extensions by default.
if ( NOT DEFINED CMAKE_CXX_EXTENSIONS )
  set ( CMAKE_CXX_EXTENSIONS OFF )
endif()

# A convenient variable for telling the compiler to use these header files.
set ( OSG_TOOLS_CONFIG_DIR_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/config )
set ( OSG_TOOLS_CONFIG_DIR_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config )

# Set the version.
configure_file (
  ${OSG_TOOLS_CONFIG_DIR_INPUT}/Version.h.in
  ${OSG_TOOLS_CONFIG_DIR_OUTPUT}/OsgTools/Version.h )

# Add options here as needed for config file.

# Now that we have all the configuration options we can write the file.
configure_file (
  ${OSG_TOOLS_CONFIG_DIR_INPUT}/Config.h.in
  ${OSG_TOOLS_CONFIG_DIR_OUTPUT}/OsgTools/Config.h )

# Install generated files wherever the user specified to install things.
install (
  DIRECTORY ${OSG_TOOLS_CONFIG_DIR_OUTPUT}/OsgTools
  DESTINATION include
  FILES_MATCHING PATTERN "*.h"
)

# Find OpenGL. This is the right way to do things.
find_package ( OpenGL REQUIRED )

# Find and use OpenSceneGraph. Set OSG_ROOT environment variable.
find_package ( OpenSceneGraph REQUIRED )

# Extra steps for FindOpenSceneGraph because that module is somewhat dated.
# Note: We do not have to do this with OpenGL; it happens automatically.
add_library ( OpenSceneGraph::OSG INTERFACE IMPORTED )
target_include_directories ( OpenSceneGraph::OSG INTERFACE ${OPENSCENEGRAPH_INCLUDE_DIRS} )
target_link_libraries ( OpenSceneGraph::OSG INTERFACE ${OPENSCENEGRAPH_LIBRARIES} )

# Find and use usul. Set usul_ROOT environment variable to:
# 1) where it is installed, or
# 2) it's build directory.
find_package ( usul REQUIRED )

# Does the user want strict warnings?
option ( OSG_TOOLS_ENABLE_STRICT_WARNINGS "Enable strict warnings" ON )
if ( OSG_TOOLS_ENABLE_STRICT_WARNINGS )
  message ( "   -- Enabling strict warnings" )
  if ( MSVC ) # Also true for Intel compiler. Means "looks like Visual C++".
    add_compile_options ( /W4 )
  else()
    add_compile_options ( -Wall -Wextra -pedantic -pedantic-errors -Wconversion -Wsign-conversion )
  endif()
endif()

# Does the user want to treat warnings the same as errors?
option ( OSG_TOOLS_TREAT_WARNINGS_LIKE_ERRORS "Treat warnings like errors" ON )
if ( OSG_TOOLS_TREAT_WARNINGS_LIKE_ERRORS )
  message ( "   -- Treating warnings like errors" )
  if ( MSVC ) # Also true for Intel compiler. Means "looks like Visual C++".
    add_compile_options ( /WX )
  else()
    add_compile_options ( -Werror )
  endif()
endif()

# Does the user want to build the tests?
option ( OSG_TOOLS_BUILD_TESTS "Build the tests" OFF )

# Set default postfix if none was given on the command line.
if ( NOT DEFINED CMAKE_DEBUG_POSTFIX )
  set ( CMAKE_DEBUG_POSTFIX "_d" )
endif()

# For debug builds we want the _DEBUG preprocessor symbol to be defined.
add_compile_definitions ( $<$<CONFIG:Debug>:_DEBUG> )

# We do not need to see all those deprecation warnings in OpenSceneGraph.
add_definitions ( -DGL_SILENCE_DEPRECATION )

# Also process the CMakeLists.txt files found in these directories.
add_subdirectory ( source )
if ( OSG_TOOLS_BUILD_TESTS )
  add_subdirectory ( tests ) # The tests.
endif()

# Configure how this project gets imported into other cmake projects.
include ( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/export.cmake )
