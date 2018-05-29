from conans import ConanFile, CMake

class LibParseConan(ConanFile):
    name = "libparse"
    version = "master"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = (
        "external/sugar/cmake/*",
        "external/standards/*",
        "include/*",
        "src/*",
        "tests/*",
        "CMakeLists.txt"
    )
    options = {
        "build_tests": [True, False],
        "build_docs": [True, False],
    }
    default_options = (
        "build_tests=True",
        "build_docs=False",
    )
    requires = (
        "pegtl/2.5.1@bincrafters/stable",
        "range-v3/0.3.6@ericniebler/stable",
    )
    generators = "cmake"

    def build(self):
        cmake = CMake(self)

        if self.options.build_tests:
            cmake.definitions["BUILD_TESTS"] = "ON"

        if self.options.build_docs:
            cmake.definitions["BUILD_DOCS"] = "ON"

        cmake.configure(source_dir=self.source_folder)
        cmake.build()

        if self.options.build_tests:
            cmake.test()

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs.append("parse")

    def build_requirements(self):
        self.build_requires("fmt/5.0.0@bincrafters/stable")
        if self.options.build_tests:
            self.build_requires("catch2/2.2.2@bincrafters/stable")
