#VCD Assert

## Building

# Dependencies
PEGTL
Range-V3
fmt
Catch2
CLI11

#With conan

```bash
mkdir build
cd build
conan install ..
conan build ..
```

#With cmake
All dependencies need to be installed and findable with CMake's `find_package`

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Build issues that one should be aware of
* To compile with libc++ you need a version newer than https://github.com/llvm-mirror/libcxx/commit/8a50bbc2b96117fc222bf3f8718b5aba8330000a for std::array deduction guides
* Building with clang with libstdc++ can trigger `https://bugs.llvm.org/show_bug.cgi?id=31852`
* Requires Catch2 with `dev-new-cmake` patches - Not in released version (2.2.3) yet
* CLI11 master has incompatible changes to v1.5.4
