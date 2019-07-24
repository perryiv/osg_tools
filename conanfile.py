from conans import python_requires
import glob, os, subprocess

intel = python_requires("intel_helper/0.0.0@vaone-dev/master")


class OsgTools(intel.ConanFile):
    name = "osg_tools"
    version = "1.0.1"
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = {"shared": True}
    no_copy_source = True
    scm = {"type": "git", "url": "auto"}
    requires = (
        "usul/[^1.0.1]@vaone-dev/develop",
        "OpenSceneGraph/[^3.6.3]@vaone-dev/master",
    )

    def build(self):
        cmake = intel.CMake(self)
        cmake.configure(
            defs={
                "CMAKE_BUILD_WITH_INSTALL_RPATH": True,
                "OSG_DIR": self.deps_cpp_info["OpenSceneGraph"].rootpath,
                "usul_ROOT": self.deps_cpp_info["usul"].rootpath,
                "CMAKE_DEBUG_POSTFIX": "",
            }
        )
        cmake.build()

    def package(self):
        cmake = intel.CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["osg_tools"]
        if not self.options.shared:
            self.cpp_info.defines = ["OSG_TOOLS_STATIC_DEFINE"]
