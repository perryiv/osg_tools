
################################################################################
#
#  Copyright (c) 2019, Perry L Miller IV
#  All rights reserved.
#  MIT License: https://opensource.org/licenses/mit-license.html
#
################################################################################

################################################################################
#
#  Test script.
#
################################################################################

# Exit immediately if one of the following commands do not return zero.
set -e

# Echo all the commands.
set -x

# This is necessary for Mac.
export DYLD_FALLBACK_LIBRARY_PATH=".:$OSG_ROOT/lib"

rm -rf build
mkdir build
cd build

cmake .. \
  -DCMAKE_VERBOSE_MAKEFILE=ON \
  -DCMAKE_BUILD_TYPE="Release" \
  -DOSG_TOOLS_BUILD_TESTS=ON \
  -DOSG_TOOLS_ENABLE_CODE_COVERAGE=OFF
cmake --build .

tests/osg_tools_test --abort --use-colour=yes --durations=no

cd ..

rm -rf build
mkdir build
cd build

cmake .. \
  -DCMAKE_VERBOSE_MAKEFILE=ON \
  -DCMAKE_BUILD_TYPE="Debug" \
  -DOSG_TOOLS_BUILD_TESTS=ON \
  -DOSG_TOOLS_ENABLE_CODE_COVERAGE=ON
cmake --build .

tests/osg_tools_testd --abort --use-colour=yes --durations=no

cd ..
gcovr
