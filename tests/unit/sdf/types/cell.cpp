#include "./cell.hpp"

// using namespace SDF::Test;
#include <variant>
using namespace SDF;
using namespace SDF::Test;

using namespace std::literals::string_literals;

// catch_test_cells(delayfile, delayfile.get_cells(), test.cells);


// void SDF::Test::read_in_test_cell(SDF::DelayFileReader &reader, TestCell &test)
// { 

//   Cell c = Cell(test.cell_type, test.cell_instance, test.timing_specs);
//   reader.add_cell(c);

//   for(auto& ts: test.timing_specs) {
//     read_in_test_timing_spec(reader, cell); // timing spec reader does not exist.
//   }

// }
void catch_test_timing_checks(TimingCheckSpec &check, TimingCheckSpec &test)
{
  
  REQUIRE(check.size() == test.size());
  // REQUIRE(cells.size() == tests.size())
  // REQUIRE(cells.size() == tests.size())
  
}

void catch_test_timing_specs(std::vector<TimingSpec> specs, std::vector<TimingSpec> tests)
{
  view::zip_with(
    [](auto spec, auto test) -> void { 
      REQUIRE(spec.get_enum_type()==test.get_enum_type());
      switch (test.get_enum_type()) {
        case TimingSpecType::delay:
          throw std::runtime_error("InternalError");  
          break;
        case TimingSpecType::timing_check:

          // TimingCheckSpec sp = std::get<TimingCheckSpec>(std::move(spec));
          REQUIRE(std::holds_alternative<TimingCheckSpec>(spec.value));
          
          catch_test_timing_checks(std::get<TimingCheckSpec>(spec.value),
                                    std::get<TimingCheckSpec>(test.value));
                                    
          break;
        case TimingSpecType::timing_env:
          throw std::runtime_error("InternalError");  
          break;
        case TimingSpecType::label:
          throw std::runtime_error("InternalError");  
          break;
        default:
          throw std::runtime_error("InternalError");
      }
    },
    specs,tests
  );      
}

void catch_test_cell(Cell cell, Cell test)
{

  REQUIRE(cell.cell_type == test.cell_type);
  REQUIRE(cell.cell_instance == test.cell_instance);

  REQUIRE(cell.timing_specs.size() == test.timing_specs.size());
  catch_test_timing_specs(cell.timing_specs, test.timing_specs);
}


void catch_test_cells(std::vector<Cell> cells, std::vector<Cell> tests)
{

  REQUIRE(cells.size() == tests.size());

  view::zip_with(
    [](auto cell, auto test) -> void { 
      catch_test_cell(cell, test);
    },
    cells, tests
  );        

}