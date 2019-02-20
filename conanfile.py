from conans import ConanFile, CMake

class OsgTools(ConanFile):
    name = "osg_tools"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "run_tests": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "run_tests": False,
    }

    exports_sources = "*"
    generators = "cmake"

    # These are the packages we need to build.
    requires = (
        "openscenegraph/3.6.3@vaone/stable",
    )

    # Tells conan what options are valid on the various platforms.
    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    # Tells conan that if the test are going to be run then catch is needed.
    def build_requirements(self):
        if self.options.run_tests:
            self.build_requires("Catch2/2.5.0@catchorg/stable")

    # Private helper function.
    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(
            build_folder = "build",
            defs = {
                "BUILD_TESTS": self.options.run_tests,
            },
        )
        return cmake

    # Tells conan how to build this project.
    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        if self.options.run_tests:
            cmake.test()

    # Tells conan how to package this project.
    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    # Tells conan how others use this project.
    def package_info(self):
        raise NotImplementedError

    # Tells conan to not bother including the option "run_tests" when making the hash.
    def package_id(self):
        del self.info.options.run_tests
