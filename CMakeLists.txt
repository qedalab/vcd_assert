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
# find_package(antlr4-runtime REQUIRED)

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


# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/resources/antlr/antlr-4.7.1-complete.jar)

#set location of local runtime sources  
set(ANTLR4CPP_RUNTIME_LOCATION ${PROJECT_SOURCE_DIR}/resources/antlr/antlr4-cpp-runtime-4.7.1-source.zip)

#set local runtime instead of download 
set(ANTLR4CPP_LOCAL_REPO ${ANTLR4CPP_RUNTIME_LOCATION})
set(ANTLR4CPP_LOCAL_ROOT ${CMAKE_BINARY_DIR}/antlr4cpp-runtime)
# set(ANTLR4CPP_LOCAL_PREFIX ${ANTLR4CPP_LOCAL_ROOT}/antlr/antlr4cpp-runtime)

#Include Antlr4 downloader and generate macro 
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
# add external build for antlrcpp
include( ExternalAntlr4Cpp )
# include(cmake/ExternalAntlr4Cpp.cmake)
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")


#Generate sources from antlr grammar (see cmake/ExternalAntlrCpp.cmake for details)
set(VERILOG2012_SRC_DIR ${PROJECT_SOURCE_DIR}/src/verilog/ieee1800_2012)
set(ANTLR4CPP_GENERATED_SRC_DIR ${VERILOG2012_SRC_DIR}/antlr)
antlr4cpp_process_grammar(vcd_assert Verilog ${VERILOG2012_SRC_DIR}/SV2012.g4 "")


# set(antlr4cpp_project_namespace Verilog)
# set(antlr4cpp_grammar_parser ${VERILOG2012_SRC_DIR}/SV2012.g4)
# add_custom_target("antlr4cpp_generation_${antlr4cpp_project_namespace}"
#     COMMAND
#     ${CMAKE_COMMAND} -E make_directory ${ANTLR4CPP_GENERATED_SRC_DIR}
#     COMMAND
#     "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR4CPP_JAR_LOCATION}" -Dlanguage=Cpp -listener -visitor -o "${ANTLR4CPP_GENERATED_SRC_DIR}/${antlr4cpp_project_namespace}" -package ${antlr4cpp_project_namespace} "${antlr4cpp_grammar_lexer}" "${antlr4cpp_grammar_parser}"
#     WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
#     DEPENDS "${antlr4cpp_grammar_lexer}" "${antlr4cpp_grammar_parser}"
#     )


message(STATUS "Found generated sources: ${antlr4cpp_src_files_Verilog}")
message(STATUS "antlr4 include dirs: ${antlr4cpp_include_dirs_Verilog}")


#Add libverilog library
add_library(libverilog "src/verilog")
target_sources(libverilog PRIVATE ${antlr4cpp_src_files_Verilog})

target_include_directories(libverilog PUBLIC "${PROJECT_SOURCE_DIR}/include/"  ${ANTLR4CPP_INCLUDE_DIRS}  ${antlr4cpp_include_dirs_Verilog})
# target_link_libraries(libverilog PUBLIC libparse fmt::fmt ${ANTLR4CPP_LIBS}/antlr4-runtime) # ${ANTLR4CPP_LIBS}
add_dependencies(libverilog antlr4cpp antlr4cpp_generation_Verilog)
link_directories( ${ANTLR4CPP_LIBS} )
target_link_libraries(libverilog PUBLIC libparse fmt::fmt antlr4-runtime) #antlr4-runtime ${ANTLR4CPP_LIBS}

# set (CMAKE_SHARED_LINKER_FLAGS "-I/usr/local/include/antlr4-runtime/")
# target_compile_definitions(libverilog PUBLIC  -DVERBOSE_DEBUG_OUTPUT=1)
# target_add_warnings(libverilog)


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

set_target_properties(libparse libvcd libvcd_assert vcd_assert libsdf libverilog
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
