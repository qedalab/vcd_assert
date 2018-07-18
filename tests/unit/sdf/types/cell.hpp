#ifndef TEST_SDF_TYPES_CELL_HPP
#define TEST_SDF_TYPES_CELL_HPP

#include <sdf/types/cell.hpp>

#include "./timing_spec.hpp"

#include <catch2/catch.hpp>

#include <string>
#include <variant>
#include <vector>
#include <range/v3/view/zip.hpp>

#include <string_view>

#include <ak_toolkit/static_string.hpp>
namespace sstr = ak_toolkit::static_str;

namespace SDF::Test {
using namespace SDF;

// struct TestCell {
//   std::string cell_type;
//   CellInstance cell_instance;
//   std::vector<TimingSpec> timing_specs;
// };


struct TestCell : public Cell{};

constexpr auto test_celltype_1_str = sstr::literal("(CELLTYPE \"DFF\")");
inline const std::string test_celltype_1{"DFF"};

constexpr auto test_cellinstance_1_str = sstr::literal("(INSTANCE *)");
inline const CellInstance test_cellinstance_1{
  Star{}
};

constexpr auto test_cellinstance_2_str = "path";
inline const CellInstance test_cellinstance_2{
  HierarchicalIdentifier{
    HChar::dot,
    {"path"}
  }
};

constexpr auto test_cell_1_str = 
  "(CELL \n  " + test_celltype_1_str + "\n  " +
  test_cellinstance_1_str + "\n    " +
  test_timingspec_array_1_str + "\n)";

inline const Cell test_cell_1{
  test_celltype_1,
  test_cellinstance_1,
  test_timingspec_array_1
};

// // void SDF::Test::read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test)
// void catch_test_port_tchk(PortTimingCheck &pt, PortTimingCheck &test);
// void catch_test_hold_check(Hold &hold, Hold &test);
// void catch_test_timing_checks(std::vector<TimingCheck> &checks, std::vector<TimingCheck> &tests);
// void catch_test_timing_checks(TimingCheckSpec &check, TimingCheckSpec &test);
void catch_test_timing_specs(std::vector<TimingSpec> specs, std::vector<TimingSpec> tests);
void catch_test_cell(Cell cell, Cell test);
void catch_test_cells(std::vector<Cell> cells, std::vector<Cell> tests);
// // void read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_cells(std::vector<Cell> cells, std::vector<Cell> test);
// void catch_test_cell(SDF::Cell &cell, SDF::Cell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_CELL_HPP
