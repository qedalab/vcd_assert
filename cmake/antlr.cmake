include(ExternalProject)

find_package(Java COMPONENTS Runtime)

macro(antlr_init version)
  set(ANTLR_VERSION ${version})
  set(ANTLR_DIR "${CMAKE_BINARY_DIR}/antlr/${version}")
  set(ANTLR_GENERATED "${ANTLR_DIR}/generated")
  set(ANTLR_JAR "${ANTLR_DIR}/antlr-${version}-complete.jar")
  set(ANTLR_RUNTIME_ZIP "${ANTLR_DIR}/antlr-cpp-runtime-${version}-source.zip")

  if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(ANTLR_BUILD_TYPE RelWithDebInfo)
  else ()
    set(ANTLR_BUILD_TYPE ${CMAKE_BUILD_TYPE})
  endif ()

  if(NOT EXISTS "${ANTLR_DIR}")
    file(MAKE_DIRECTORY "${ANTLR_DIR}")
  endif()

  if(NOT EXISTS "${ANTL_GENERATED}")
    file(MAKE_DIRECTORY "${ANTLR_GENERATED}")
  endif()

  if(NOT EXISTS "${ANTLR_JAR}")
    message("Downloading antlr jar")
    file(DOWNLOAD
      "http://www.antlr.org/download/antlr-${version}-complete.jar"
      ${ANTLR_JAR}
    )
  endif()

  if(NOT EXISTS "${ANTLR_RUNTIME_ZIP}")
    message("Downloading antlr4 runtime zip")
    file(DOWNLOAD
      "http://www.antlr.org/download/antlr4-cpp-runtime-${version}-source.zip"
      ${ANTLR_RUNTIME_ZIP}
    )
  endif()

  ExternalProject_ADD(
    antlr_cpp_runtime #NAME
    PREFIX  ${ANTLR_DIR}/prefix/
    URL ${ANTLR_RUNTIME_ZIP}
    CONFIGURE_COMMAND ${CMAKE_COMMAND}
      -DCMAKE_BUILD_TYPE=${ANTLR_BUILD_TYPE}
      -DANTLR4CPP_JAR_LOCATION=${ANTLR_JAR}
      -DBUILD_SHARED_LIBS=OFF
      -DBUILD_TESTS=OFF
      -DCMAKE_INSTALL_PREFIX:PATH=${ANTLR_DIR}/install
      <SOURCE_DIR>
    LOG_CONFIGURE ON
    LOG_BUILD ON
  )

  add_library(antlr4_runtime_target INTERFACE)

  target_link_libraries(
    antlr4_runtime_target
    INTERFACE
    ${ANTLR_DIR}/install/lib/libantlr4-runtime.a
  )

  target_include_directories(
    antlr4_runtime_target
    INTERFACE
    "${ANTLR_DIR}/install/include/antlr4-runtime"
  )

  add_dependencies(
    antlr4_runtime_target
    antlr_cpp_runtime
  )

endmacro()

function(antlr_grammar name prefix lexer parser)
  set(OUTPUT_PREFIX "${ANTLR_GENERATED}/${name}/${prefix}")

  #Source file outputs
  set(OUTPUT 
    "${OUTPUT_PREFIX}BaseListener.cpp"
    "${OUTPUT_PREFIX}Lexer.cpp"
    "${OUTPUT_PREFIX}Listener.cpp"
    "${OUTPUT_PREFIX}Parser.cpp"
  )

  add_custom_command(
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR_JAR}" -Dlanguage=Cpp -no-visitor -listener -o "${ANTLR_GENERATED}/${name}" -package "${name}" "${lexer}" "${parser}"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    DEPENDS ${lexer} ${parser}
    OUTPUT ${OUTPUT}
  )

  add_library(
    ${name}
    ${OUTPUT}
  )

  target_include_directories(${name}
    PUBLIC
    "${ANTLR_GENERATED}/${name}"
  )

  target_link_libraries(
    ${name}
    PUBLIC
    antlr4_runtime_target
  )

endfunction()
