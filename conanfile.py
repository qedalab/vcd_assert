from conans import ConanFile, CMake


class VCDAssertConan(ConanFile):
    name = "libparse"
    version = "master"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = (
        "include/*",
        "src/*",
        "tests/*",
        "CMakeLists.txt"
    )
    generators = "cmake_find_package"

    def build(self):
        cmake = CMake(self)

        cmake.definitions["BUILD_TESTS"] = "ON"
        cmake.definitions["BUILD_DOCS"] = "ON"
        cmake.definitions["RUN_ALL_TESTS"] = "ON"
        cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"

        cmake.configure()

        cmake.build()
        cmake.test(["--",  "CTEST_OUTPUT_ON_FAILURE=TRUE"])

    def package(self):
        pass

    def build_requirements(self):
        self.build_requires("taocpp-pegtl/2.8.3")
        self.build_requires("range-v3/0.11.0")
        self.build_requires("fmt/5.3.0")
        self.build_requires("catch2/2.13.8")
        self.build_requires("cli11/1.9.1")
