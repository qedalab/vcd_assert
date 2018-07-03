#ifndef TEST_SDF_TYPES_CELL_HPP
#define TEST_SDF_TYPES_CELL_HPP

#include <sdf/types/delayfile.hpp>
#include <sdf/types/cell.hpp>

namespace SDF::Test {

struct TestCell {
  std::string celltype;
  CellInstance cell_instance;
  std::vector<TimingSpec> timing_specs;
};

void read_in_test_scope(SDF::DelayFileReader &reader, TestCell &test);
void catch_test_scope(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_CELL_HPP
