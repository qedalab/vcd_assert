# VCD Assert
[![Build Status](https://travis-ci.org/pleroux0/vcd_assert.svg?branch=master)](https://travis-ci.org/pleroux0/vcd_assert)

A external program that check for timing violations by looking at the VCD output.

## Building

### Dependencies
 * [PEGTL](https://github.com/taocpp/PEGTL) - Parse Expression Grammar Template Library
 * [Range-V3](https://github.com/ericniebler/range-v3) - Experimental range library for C++11/14/17
 * [fmt](https://github.com/fmtlib/fmt) - A modern formatting library
 * [Catch2](https://github.com/catchorg/Catch2) - A modern, C++-native, header-only, test framework for unit-tests
 * [CLI11](https://github.com/CLIUtils/CLI11) - Command line parser for C++11

### With conan (recommended)
Add my remote

```bash
conan remote add pleroux0 https://api.bintray.com/conan/pleroux0/pleroux0 
```

This is needed for:

1. Catch2 - The latest released version (2.2.3) doesn't have the [`dev-new-cmake` patches][dev-cmake-patches]
2. range-v3 - The pull request for better conan/cmake usage is not merged or released yet

```bash
mkdir build
cd build
conan install ..
conan build ..
```

### With cmake
All dependencies need to be installed and findable with CMake's `find_package`

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

### Build issues that one should be aware of
* To compile with libc++ you need a version that contains [std::array deduction guides][libcxx:commit:std::array deduction guide]
* Building with clang and libstdc++ can trigger [a bug][clang:bug:31852]
* Requires Catch2 with [`dev-new-cmake` patches][dev-cmake-patches] - Not in released version (2.2.3) yet
* CLI11 master has incompatible changes to v1.5.4
* It appears GCC7 sometimes over eagerly instantiates templates causing weird compile errors. This has been worked around in the code and the master branch compiles.

[dev-cmake-patches]:https://github.com/catchorg/Catch2/commit/b957eb4172aecdfec4a940b4eb6f844e3e9caa5a
[libcxx:commit:std::array deduction guide]:https://github.com/llvm-mirror/libcxx/commit/8a50bbc2b96117fc222bf3f8718b5aba8330000a
[clang:bug:31852]:https://bugs.llvm.org/show_bug.cgi?id=31852
