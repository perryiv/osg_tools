### OsgTools

This is a modernization of the low-level utility code found
[here](https://github.com/perryiv/cadkit/tree/master/OsgTools),
which is itself just an unaltered copy of
[this code](https://sourceforge.net/p/cadkit/code/HEAD/tree/trunk/OsgTools/).

### Dependencies

Building the library requires:

- [CMake](https://cmake.org/)
- [OpenSceneGraph](http://www.openscenegraph.org/)
- [Usul](https://github.com/perryiv/usul)

Building the test program requires
[Catch2](https://github.com/catchorg/Catch2).

### Testing

To configure, compile, and test, do this:

    cd usul
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ./bin/osg_tools_test
