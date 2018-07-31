set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_vcd ../unit_main.cpp)
target_link_libraries(unit_vcd libvcd Catch2::Catch2)
target_add_warnings(unit_vcd)
add_test(NAME unit_vcd COMMAND unit_vcd)

add_subdirectory(actions)
add_subdirectory(grammar)
add_subdirectory(serialize)
add_subdirectory(test)
add_subdirectory(types)
add_subdirectory(util)
add_subdirectory(integration)
