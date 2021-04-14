from conan.tools.cmake import CMake, CMakeToolchain
from conans import ConanFile, tools
import os


class OsgTools(ConanFile):
    name = "osg_tools"
    license = "MIT"
    author = "Perry L Miller IV (perry@modelspace.com)"
    url = "https://github.com/perryiv/osg_tools"
    description = "Classes and functions that use OpenSceneGraph"
    topics = "OpenSceneGraph", "C++", "utility"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "run_tests": [True, False],
    }
    default_options = {"shared": False, "run_tests": True}

    scm = {"type": "git", "url": "auto", "revision": "auto"}
    revision_mode = "scm"
    requires = (
        "usul/5.0.0@perryiv/stable",
        "openscenegraph/3.6.5",
    )

    no_copy_source = True
    generators = "cmake_find_package",

    def set_version(self):
        with open ( os.path.join ( self.recipe_folder, "version.txt" ) ) as file:
            self.version = file.read()

    def requirements(self):
        if self.options.run_tests:
            self.requires("catch2/2.13.1", private=True)

    def generate(self):
        toolchain = CMakeToolchain(self)
        toolchain.variables["OSG_TOOLS_BUILD_TESTS"] = self.options.run_tests
        toolchain.variables["OSG_TOOLS_ENABLE_CODE_COVERAGE"] = False
        toolchain.variables["CMAKE_DEBUG_POSTFIX"] = ""
        toolchain.variables["CMAKE_VERBOSE_MAKEFILE"] = True
        # Work around OpenSceneGraph package on conan center not handling different C++ standards.
        if "THIS_JOB_CPP_STANDARD" in os.environ:
            toolchain.variables["CMAKE_CXX_STANDARD"] = os.environ["THIS_JOB_CPP_STANDARD"]
        toolchain.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self.options.run_tests:
            with tools.run_environment(self):
                cmake.test(output_on_failure=True)

    def package(self):
        cmake = CMake(self)
        cmake.install()
        self.copy(pattern="License.md", dst="licenses")

    def package_info(self):
        self.cpp_info.libs = ["osg_tools"]
        if not self.options.shared:
            self.cpp_info.defines = ["OSG_TOOLS_STATIC_DEFINE"]
        if not self.in_local_cache:
            self.cpp_info.includedirs = [
                "source",
                os.path.join("build", self.settings.build_type.value, "config")
            ]

    def package_id(self):
        del self.info.options.run_tests
        del self.info.settings.compiler.cppstd
