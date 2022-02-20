set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_sdf ../unit_main.cpp)
target_link_libraries(unit_sdf libsdf Catch2::Catch2 fmt::fmt range-v3::range-v3)

target_add_warnings(unit_sdf)
add_test(NAME unit_sdf COMMAND unit_sdf)

if (${RUN_ALL_TESTS})
  add_test(NAME unit_sdf_hidden COMMAND unit_sdf "[.]")
endif()

add_subdirectory(actions)
add_subdirectory(grammar)
add_subdirectory(rc)
add_subdirectory(serialize)
add_subdirectory(types)


