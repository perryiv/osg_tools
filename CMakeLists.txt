
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
#
################################################################################

# We use the add_compile_definitions command.
# https://cmake.org/cmake/help/v3.12/release/3.12.html
cmake_minimum_required ( VERSION 3.12.0 )

# The name of this project.
project ( osg_tools )

# Are we using a familiar compiler? Quotes are important here.
if ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC" )
  set ( USING_MSVC ON )
elseif ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Intel" )
  set ( USING_INTEL ON )
elseif ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" )
  set ( USING_GCC ON )
elseif ( "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" )
  set ( USING_CLANG ON )
else()
  message ( FATAL_ERROR "\nUnknown compiler: ${CMAKE_CXX_COMPILER_ID}"  )
endif()

# Use this C++ standard unless the user specifies otherwise with:
# cmake path/to/source/dir -DCMAKE_CXX_STANDARD=14
if ( NOT DEFINED CMAKE_CXX_STANDARD )
  set ( CMAKE_CXX_STANDARD 17 )
endif()

# Turn off compiler-specific extensions by default.
if ( NOT DEFINED CMAKE_CXX_EXTENSIONS )
  set ( CMAKE_CXX_EXTENSIONS OFF )
endif()

# Define some variables that point to top-level directories.
set ( OSG_TOOLS_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source )

# This is where we want output files to go.
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# Set the version.
set ( OSG_TOOLS_VERSION_MAJOR 0 )
set ( OSG_TOOLS_VERSION_MINOR 1 )
set ( OSG_TOOLS_VERSION_PATCH 0 )
configure_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/config/Version.h.in
  ${OSG_TOOLS_INC_DIR}/OsgTools/Version.h )

# Add options here as needed for config file.

# Now that we have all the configuration options we can write the file.
configure_file (
  ${CMAKE_CURRENT_SOURCE_DIR}/config/Config.h.in
  ${OSG_TOOLS_INC_DIR}/OsgTools/Config.h )

# Let the user set these directories.
set ( OSG_INC_DIR $ENV{OSG_INC_DIR} CACHE STRING "Include path for OpenSceneGraph header files" )
set ( OSG_LIB_DIR $ENV{OSG_LIB_DIR} CACHE STRING "Include path for OpenSceneGraph library files" )
set ( USUL_INC_DIR $ENV{USUL_INC_DIR} CACHE STRING "Include path for Usul header files" )
set ( USUL_LIB_DIR $ENV{USUL_LIB_DIR} CACHE STRING "Include path for Usul library files" )

# Does the user want strict warnings?
option ( OSG_TOOLS_ENABLE_STRICT_WARNINGS "Enable strict warnings" ON )
if ( OSG_TOOLS_ENABLE_STRICT_WARNINGS )
  message ( "   -- Enabling strict warnings" )
  if ( USING_MSVC OR USING_INTEL )
    add_compile_options ( /W4 )
  else()
    add_compile_options ( -Wall -Wextra -pedantic -pedantic-errors )
  endif()
endif()

# Does the user want to treat warnings the same as errors?
option ( OSG_TOOLS_TREAT_WARNINGS_LIKE_ERRORS "Treat warnings like errors" ON )
if ( OSG_TOOLS_TREAT_WARNINGS_LIKE_ERRORS )
  message ( "   -- Treating warnings like errors" )
  if ( USING_MSVC OR USING_INTEL )
    add_compile_options ( /WX )
  else()
    add_compile_options ( -Werror )
  endif()
endif()

# For debug builds we want the _DEBUG preprocessor symbol to be defined.
add_compile_definitions ( $<$<CONFIG:Debug>:_DEBUG> )

# We do not need to see all those deprecation warnings in OpenSceneGraph.
add_definitions ( -DGL_SILENCE_DEPRECATION )

# Everybody in the subdirectories will need to include files from here.
include_directories ( ${OSG_TOOLS_INC_DIR} )
include_directories ( ${OSG_INC_DIR} )
include_directories ( ${USUL_INC_DIR} )

message ( "USUL_INC_DIR = ${USUL_INC_DIR}" )

# Where to look for libraries.
link_directories ( ${OSG_LIB_DIR} )
link_directories ( ${USUL_LIB_DIR} )

# Also process the CMakeLists.txt files found in these directories.
add_subdirectory ( source )
add_subdirectory ( tests )
