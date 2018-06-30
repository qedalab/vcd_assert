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
    generators = "cmake_paths"

    def build(self):
        cmake = CMake(self)

        cmake.definitions["BUILD_TESTS"] = "ON"
        cmake.definitions["BUILD_DOCS"] = "ON"
        cmake.definitions["CMAKE_TOOLCHAIN_FILE"] = "conan_paths.cmake"

        cmake.configure()

        cmake.build()
        cmake.test()

    def package(self):
        pass

    def build_requirements(self):
        self.build_requires("pegtl/2.6.0@taocpp/stable")
        self.build_requires("range-v3/0.3.6@pleroux0/stable")
        self.build_requires("fmt/5.0.0@bincrafters/stable")
        self.build_requires("Catch/2.2.3@pleroux0/stable")
        self.build_requires("CLI11/1.5.4@CLIUtils/stable")
