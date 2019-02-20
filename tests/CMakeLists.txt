
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#
################################################################################

################################################################################
#
#  Contains the logic specific to building the unit tests.
#
################################################################################

# Make sure this environment variable is set.
if ( NOT DEFINED ENV{CATCH2_INC_DIR} )
  message ( FATAL_ERROR
    "\nEnvironment variable CATCH2_INC_DIR is not set. "
    "\nIt should point to a directory that contains these files:\n"
    "https://github.com/catchorg/Catch2/tree/master/single_include/catch2"
  )
endif()

# Add the include directory for catch.
include_directories ( $ENV{CATCH2_INC_DIR} )

# Define a variable that holds all the source files.
set ( SOURCE_FILES
  OsgTools/Main.cpp
  OsgTools/Group.cpp
)

# Make an executable.
add_executable ( ${PROJECT_NAME}_test ${SOURCE_FILES} )

# We're going to use this library.
# CMake will automatically add -I, -L, and -D (etc) appropriately.
target_link_libraries ( ${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} OpenThreads osg )
