cmake_minimum_required (VERSION 3.2)
project (Parse)

#Options
option(BUILD_TESTS "Build tests" FALSE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

include(cmake/warnings.cmake)

#Include dependencies
find_package(pegtl REQUIRED)
find_package(range-v3 0.3.6 REQUIRED)
find_package(fmt 5.0.0 REQUIRED)

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
target_link_libraries(libvcd PUBLIC libparse)
target_add_warnings(libvcd)

#Add libsdf library
add_library(libsdf "src/sdf")
target_include_directories(libsdf PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libsdf PUBLIC libparse )

#Add vcd_assert library
add_library(libvcd_assert "src/vcd_assert")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd_assert PUBLIC libvcd)
target_add_warnings(libvcd_assert)

#Enable warnings
if ( CMAKE_COMPILER_IS_GNUCC )
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

add_subdirectory(src)

if(${BUILD_TESTS})
  find_package(Catch2 2.2.3 REQUIRED)
  find_package(CLI11 REQUIRED)
  include(CTest)
  add_subdirectory(tests)
endif()
