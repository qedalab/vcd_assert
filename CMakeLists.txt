cmake_minimum_required (VERSION 3.2)
project (Parse)

#Options
option(BUILD_TESTS "Build tests" FALSE)
option(BUILD_DOCS "Build documentation [unused]" FALSE)

#Include dependencies
find_package(pegtl REQUIRED)
find_package(range-v3 0.3.6 REQUIRED)

#Ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Add libparse library
add_library(libparse "src/parse")
target_include_directories(libparse PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libparse range-v3 taocpp::pegtl)

#Add libvcd library
add_library(libvcd "src/vcd")
target_include_directories(libvcd PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_libraries(libvcd PUBLIC libparse)

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
  enable_testing()
  add_subdirectory(tests)
endif()
