cmake_minimum_required (VERSION 3.1)
project (Parse)

#Options
option(BUILD_TESTS "Build tests" FALSE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

#Include dependencies
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#Compiler flag helper
#include("./external/sugar/cmake/Sugar")
#include(sugar_generate_warning_flags)

#Add include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)


link_directories(${CONAN_LIB_DIRS})
include_directories(${CONAN_INCLUDE_DIRS})

#Ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#All warnings, Always
#sugar_generate_warning_flags(
#        target_compile_options
#        target_properties
#        ENABLE ALL
#)

set_property(GLOBAL PROPERTY COMPILE_OPTIONS "${target_compile_options}")

#Use src/CMakeLists.txt for building executable
add_subdirectory(src)
add_library(libvcd_assert ${SRC})
target_link_libraries(libvcd_assert ${CONAN_LIBS})

if(${BUILD_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()
