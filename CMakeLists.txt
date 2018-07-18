cmake_minimum_required (VERSION 3.2)
project (Parse)

#Options
option(BUILD_TESTS "Build tests" FALSE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

include(cmake/warnings.cmake)

#Include dependencies
find_package(fmt REQUIRED)
find_package(pegtl REQUIRED)
find_package(range-v3 0.3.6 REQUIRED)
find_package(CLI11 REQUIRED)

#Set static_string's string_view flag
set(AK_TOOLKIT_CONFIG_USING_STRING_VIEW 1)
if(${AK_TOOLKIT_CONFIG_USING_STRING_VIEW})
  add_library(static_string INTERFACE)  
  target_include_directories(static_string INTERFACE "${PROJECT_SOURCE_DIR}/external/static_string/include")
endif()

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
target_link_libraries(libparse range-v3 taocpp::pegtl)
target_add_warnings(libparse)

#Add libvcd library
add_library(libvcd "src/vcd")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd PUBLIC libparse )
target_add_warnings(libvcd)

#Add libsdf library
add_library(libsdf "src/sdf")
target_include_directories(libsdf PUBLIC "${PROJECT_SOURCE_DIR}/include/")
if(${AK_TOOLKIT_CONFIG_USING_STRING_VIEW})
  target_compile_definitions(libsdf PUBLIC AK_TOOLKIT_CONFIG_USING_STRING_VIEW=1)
endif()
target_link_libraries(libsdf PUBLIC libparse fmt::fmt static_string )
target_add_warnings(libsdf)

#Add vcd_assert library
add_library(libvcd_assert "src/vcd_assert")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
# target_link_libraries(libvcd_assert PUBLIC libvcd verilog_parser)
target_link_libraries(libvcd_assert PUBLIC libvcd libsdf libparse)
# target_add_warnings(libvcd_assert)

add_subdirectory(src)

if(${BUILD_TESTS})
  find_package(Catch2 2.2.3 REQUIRED)
  include(CTest)
  add_subdirectory(tests)

  set_target_properties(unit_parse unit_parse unit_vcd unit_vcd_assert
                        unit_sdf libvcd_bench_grammar
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
endif()

set_target_properties(libparse libvcd libvcd_assert vcd_assert libsdf
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
