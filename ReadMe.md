### Usul

This is a modernization of the low-level utility code found
[here](https://github.com/perryiv/cadkit/tree/master/OsgTools),
which is itself just an unaltered copy of
[this code](https://sourceforge.net/p/cadkit/code/HEAD/tree/trunk/OsgTools/).

### Do This first

Install these if you don't already have them:

- [CMake](https://cmake.org/) version 3.1.0 or later
- [Conan](https://conan.io/)

Then do this one time:

    conan remote add catchorg https://api.bintray.com/conan/catchorg/Catch2

### Optional

The instructions below assume you have a recent version of
[Node.js](https://nodejs.org/) and `npm`.

If not then you can look in the `scripts` section of the `package.json` file to see what the following `npm run` commands actually do.

### Building

Do this once:

    cd osg_tools
    npm run install

You can probably get away with doing this just once too:

    npm run config

Now to compile the code do this:

    npm run build

### Testing

Assuming you have compiled (see above) run the tests like this:

    npm run test

### Developing

This will rebuild (but not reconfigure) the code when a source file changes:

    npm run watch
