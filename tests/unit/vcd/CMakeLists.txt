set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(unit_vcd ../unit_main.cpp)
target_link_libraries(unit_vcd libvcd Catch2::Catch2)
add_test(NAME unit_vcd COMMAND unit_vcd)

add_subdirectory(events)
add_subdirectory(grammar)
add_subdirectory(types)
