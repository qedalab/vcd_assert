cmake_minimum_required (VERSION 3.2)

project (vcd_assert VERSION 1.0.0)

#Options
option(BUILD_TESTS "Build tests" FALSE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

include(cmake/warnings.cmake)
include(cmake/create_vcd_from_verilog.cmake)

#Include dependencies
find_package(fmt REQUIRED)
find_package(pegtl REQUIRED)
find_package(range-v3 0.3.6 REQUIRED)
find_package(CLI11 REQUIRED)

# add_library(verilog_parser INTERFACE)  
# target_include_directories(verilog_parser INTERFACE "${PROJECT_SOURCE_DIR}/external/verilog-parser/src")

# add_subdirectory("${PROJECT_SOURCE_DIR}/external/verilog-parser/src")
# # target_compile_definitions(verilog_parser INTERFACE fms-extensions)

#Ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Add libparse library
add_library(libparse "src/parse")
target_include_directories(libparse PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libparse PUBLIC range-v3 taocpp::pegtl)
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

#Add libverilog library
add_library(libverilog "src/verilog")
target_include_directories(libverilog PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libverilog PUBLIC libparse fmt::fmt)
# target_compile_definitions(libverilog PUBLIC -DVERBOSE_DEBUG_OUTPUT=1)
target_add_warnings(libverilog)

#Add vcd_assert library
add_library(libvcd_assert "src/vcd_assert")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd_assert PUBLIC libvcd libsdf libverilog libparse)
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

set_target_properties(libparse libvcd libvcd_assert vcd_assert libsdf libverilog
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
