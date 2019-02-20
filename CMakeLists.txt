
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
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
#
################################################################################

# We use the add_compile_definitions command.
# https://cmake.org/cmake/help/v3.12/release/3.12.html
cmake_minimum_required ( VERSION 3.12.0 )

# The name of this project.
project ( osg_tools )

# Use modern C++
set ( CMAKE_CXX_STANDARD 11 )

# This is where we want output files to go.
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# Make sure these environment variables are set.
if ( NOT DEFINED ENV{OSG_INC_DIR} )
  message ( FATAL_ERROR "\nEnvironment variable OSG_INC_DIR is not set." )
endif()
if ( NOT DEFINED ENV{OSG_LIB_DIR} )
  message ( FATAL_ERROR "\nEnvironment variable OSG_LIB_DIR is not set." )
endif()
if ( NOT DEFINED ENV{USUL_INC_DIR} )
  message ( FATAL_ERROR "\nEnvironment variable USUL_INC_DIR is not set." )
endif()

# Add these include directories.
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories ( $ENV{OSG_INC_DIR} )
include_directories ( $ENV{USUL_INC_DIR} )

# Where to look for libraries.
link_directories ( $ENV{OSG_LIB_DIR} )

# For debug builds we want the _DEBUG preprocessor symbol to be defined.
add_compile_definitions ( $<$<CONFIG:Debug>:_DEBUG> )

# We do not need to see all those deprecation warnings in OpenSceneGraph.
add_definitions ( -DGL_SILENCE_DEPRECATION )

# Also process the CMakeLists.txt files found in these directories.
add_subdirectory ( src )
add_subdirectory ( tests )
