set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_sdf ../unit_main.cpp)
target_link_libraries(unit_sdf libsdf Catch2::Catch fmt::fmt)

add_subdirectory(grammar)
add_subdirectory(rc)
add_subdirectory(types)


