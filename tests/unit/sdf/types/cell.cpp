#include "./cell.hpp"

using namespace SDF::Test;
using namespace std::literals::string_literals;

// void SDF::Test::read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test)
// { 

//   Cell c = Cell(test.cell_type, test.cell_instance, test.timing_specs);
//   reader.add_cell(c);

//   for(auto& ts: test.timing_specs) {
//     read_in_test_timing_spec(reader, cell); // timing spec reader does not exist.
//   }

// }

// void SDF::Test::catch_test_cell(SDF::DelayFile &header, SDF::Cell &cell,
//                                  TestCell &test)
// {

//   CHECK(cell.get_cell_type() == test.cell_type);
//   CHECK(cell.get_cell_instance() == test.cell_instance);

//   CHECK(cell.num_timing_specs() == test.timing_specs.size());

//   for(auto &inner_test_timing_specs: test.timing_specs) {
//     SECTION("Timing Spec: "s + inner_test_timing_specs.cell_instance) {
//       REQUIRE(cell.contains_cell(inner_test_cell.cell_instance));
//       auto cell_index = cell.get_cell_index(inner_test_cell.cell_instance);
//       REQUIRE(cell_index < header.num_cells());
//       auto &inner_cell = header.get_cell(cell_index);
//       catch_test_cell(header, inner_cell, inner_test_cell);
//     }
//   }

//   for(auto &test_var: test.variables) {
//     SECTION("Var: "s + test_var.ref) {
//       REQUIRE(cell.contains_variable(test_var.ref));
//       auto var_index = cell.get_variable_index(test_var.ref);
//       REQUIRE(var_index < header.num_variables());
//       auto &var = header.get_var(var_index);
//       catch_test_var(header, cell, var, test_var);
//     }
//   }
// }
