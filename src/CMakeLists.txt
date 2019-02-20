
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#
################################################################################

################################################################################
#
#  Contains the logic specific to building and installing the library.
#
################################################################################

# We are compiling this library.
add_definitions ( -D_COMPILING_OSG_TOOLS )

# Define a variable that holds all the source files.
set ( SOURCE_FILES
  OsgTools/Group.cpp
)

# Make a library.
add_library ( ${PROJECT_NAME} ${SOURCE_FILES} )
