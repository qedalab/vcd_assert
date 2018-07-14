#include "./cell.hpp"
#include "./timing_spec.hpp"

#include <variant>
using namespace SDF;
using namespace SDF::Test;

using namespace std::literals::string_literals;

void SDF::Test::catch_test_timing_specs(std::vector<TimingSpec> specs, std::vector<TimingSpec> tests)
{
  SECTION("Timing Spec Size"){
    REQUIRE(specs.size() == tests.size());
  }
  for(auto && [spec,test] : ranges::view::zip(specs,tests))
    catch_test_timingspec(spec,test); 
}

void SDF::Test::catch_test_cell(Cell cell, Cell test)
{
  SECTION("Cell"){
    REQUIRE(cell.cell_type == test.cell_type);
    REQUIRE(cell.cell_instance == test.cell_instance);
  }
  catch_test_timing_specs(cell.timing_specs, test.timing_specs);
}


void SDF::Test::catch_test_cells(std::vector<Cell> cells, std::vector<Cell> tests)
{
  REQUIRE(cells.size() == tests.size());

  for(auto&& [cell,test] : ranges::view::zip(cells, tests))
    catch_test_cell(cell,test);    
}