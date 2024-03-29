cmake_minimum_required (VERSION 3.10)

project (vcd_assert VERSION 1.0.0)

#Options
option(BUILD_TESTS "Build tests" TRUE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

include(cmake/warnings.cmake)
include(cmake/antlr.cmake)
include(cmake/example_as_test.cmake)

antlr_init("4.7.1")

#Include dependencies
find_package(fmt REQUIRED)
find_package(pegtl REQUIRED)
find_package(range-v3 0.11.0 REQUIRED)
find_package(CLI11 REQUIRED)
# find_package(antlr4-runtime REQUIRED)

#Ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Add libparse library
add_library(libparse "src/parse")
target_include_directories(libparse PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libparse PUBLIC range-v3::range-v3 taocpp::pegtl)
target_add_warnings(libparse)

#Handle filesystem seperately
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_link_libraries(libparse PUBLIC c++experimental)
else()
  target_link_libraries(libparse PUBLIC stdc++fs)
endif()

#Add libvcd library
add_library(libvcd "src/vcd")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd PUBLIC libparse )
target_add_warnings(libvcd)

#Add libsdf library
add_library(libsdf "src/sdf")
target_include_directories(libsdf PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libsdf PUBLIC libparse fmt::fmt)
target_add_warnings(libsdf)

set(VERILOG2012_SRC_DIR ${PROJECT_SOURCE_DIR}/src/verilog/ieee1800_2012)
antlr_grammar(Verilog SV2012 "${VERILOG2012_SRC_DIR}/SV2012.g4" "")

#Add libverilog library
add_library(libverilog "src/verilog")
target_sources(libverilog PRIVATE ${antlr4cpp_src_files_Verilog})

target_include_directories(libverilog PUBLIC "${PROJECT_SOURCE_DIR}/include/"  ${ANTLR4CPP_INCLUDE_DIRS}  ${antlr4cpp_include_dirs_Verilog})
target_link_libraries(libverilog PUBLIC fmt::fmt Verilog libparse)

#Add vcd_assert library
add_library(libvcd_assert "src/vcd_assert")
target_include_directories(libvcd_assert PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd_assert PUBLIC libvcd libsdf libverilog libparse )
target_add_warnings(libvcd_assert)

add_subdirectory(src)

if(${BUILD_TESTS})
  option(RUN_ALL_TESTS "Run slow hidden tests" FALSE)
  find_package(Catch2 2.2.3 REQUIRED)
  include(CTest)
  add_subdirectory(tests)

  set_target_properties(unit_parse unit_parse unit_vcd unit_vcd_assert
                        unit_sdf unit_verilog libvcd_bench_grammar
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
endif()

set_target_properties(libparse libvcd libvcd_assert vcd_assert libsdf libverilog Verilog
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
