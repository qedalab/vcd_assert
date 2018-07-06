#ifndef TEST_SDF_TYPES_CELL_HPP
#define TEST_SDF_TYPES_CELL_HPP

#include <sdf/types/cell.hpp>

#include "./timing_check.hpp"

#include <string>

namespace SDF::Test {

// struct TestCell {
//   std::string cell_type;
//   CellInstance cell_instance;
//   std::vector<TimingSpec> timing_specs;
// };

struct TestCell : public Cell{};

// void read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_cell(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

static const std::string test_celltype_1{
  "DFF"
};

static const CellInstance test_cellinstance_1{
  Star{}
};

static const CellInstance test_cellinstance_2{
  HierarchicalIdentifier{
    HChar::dot,
    {"path"}
  }
};

static const std::vector<TimingSpec> test_timingspec_array_1{
  {test_timingcheckspec_1}
};

static const Cell test_testcell_1{
  test_celltype_1,
  test_cellinstance_1,
  test_timingspec_array_1
};


} // SDF::Test

#endif // TEST_SDF_TYPES_CELL_HPP
