from conans import python_requires, tools
import glob, os, subprocess

intel = python_requires("intel_helper/0.0.0@vaone-dev/master")


class OsgTools(intel.ConanFile):
    name = "osg_tools"
    version = "1.0.1"
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False], "build_tests": [True, False]}
    default_options = {"shared": True, "build_tests": False}
    no_copy_source = True
    scm = {"type": "git", "url": "auto"}
    requires = (
        "usul/[^1.0.1]@vaone-dev/develop",
        "OpenSceneGraph/[^3.6.3]@vaone-dev/master",
    )

    def system_requirements(self):
        if tools.os_info.is_linux:
            packages = []

            if tools.os_info.with_yum:
                arch = ""
                if self.settings.arch == "x86":
                    arch = ".i686"
                elif self.settings.arch == "x86_64":
                    arch = ".x86_64"
                packages.append("mesa-libGL-devel" + arch)
    
            installer = tools.SystemPackageTool()
            for package in packages:
                installer.install(package)

    def build_requirements(self):
        if self.options.build_tests:
            self.build_requires("Catch2/[^2.9.1]@catchorg/stable")

    def build(self):
        cmake = intel.CMake(self)
        defs = {
            "CMAKE_BUILD_WITH_INSTALL_RPATH": True,
            "OSG_DIR": self.deps_cpp_info["OpenSceneGraph"].rootpath,
            "usul_ROOT": self.deps_cpp_info["usul"].rootpath,
            "CMAKE_DEBUG_POSTFIX": "",
            "OSG_TOOLS_BUILD_TESTS": self.options.build_tests,
        }
        if self.options.build_tests:
            defs["Catch2_ROOT"] = self.deps_cpp_info["Catch2"].rootpath
        cmake.configure(defs=defs)
        cmake.build()

    def package(self):
        cmake = intel.CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["osg_tools"]
        if not self.options.shared:
            self.cpp_info.defines = ["OSG_TOOLS_STATIC_DEFINE"]

    def package_id(self):
        super().package_id()
        del self.info.options.build_tests
        self.info.requires["OpenSceneGraph"].full_version_mode()
