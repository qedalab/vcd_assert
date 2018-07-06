#ifndef TEST_SDF_TYPES_CELL_HPP
#define TEST_SDF_TYPES_CELL_HPP

#include <sdf/types/cell.hpp>

#include "./timing_check.hpp"

#include <catch2/catch.hpp>

#include <string>
#include <variant>
#include <vector>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/zip_with.hpp>

using namespace ranges;

namespace SDF::Test {
using namespace SDF;

// struct TestCell {
//   std::string cell_type;
//   CellInstance cell_instance;
//   std::vector<TimingSpec> timing_specs;
// };

struct TestCell : public Cell{};

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

// void SDF::Test::read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test)
void catch_test_timing_checks(TimingCheckSpec &check, TimingCheckSpec &test);
void catch_test_timing_specs(std::vector<TimingSpec> specs, std::vector<TimingSpec> tests);
void catch_test_cell(Cell cell, Cell test);
void catch_test_cells(std::vector<Cell> cells, std::vector<Cell> tests);

// // void read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_cells(std::vector<Cell> cells, std::vector<Cell> test);
// void catch_test_cell(SDF::Cell &cell, SDF::Cell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_CELL_HPP
