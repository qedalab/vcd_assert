#include "./cell.hpp"

#include <variant>
using namespace SDF;
using namespace SDF::Test;

using namespace std::literals::string_literals;



void SDF::Test::catch_test_port_tchk(PortTimingCheck &pt, PortTimingCheck &test)
{
  REQUIRE(pt.port == test.port);

  if(test.port.edge.has_value()){
    REQUIRE(pt.port.edge.has_value());
    REQUIRE(test.port.edge == pt.port.edge) ;
  }
  if(test.timing_check_condition.has_value()){
    REQUIRE(pt.timing_check_condition.has_value());
    REQUIRE(test.timing_check_condition == pt.timing_check_condition);
  }
  if(test.symbolic_name.has_value()){
    REQUIRE(pt.symbolic_name.has_value());
    REQUIRE(test.symbolic_name == pt.symbolic_name);
  }
}

void SDF::Test::catch_test_hold_check(Hold &hold, Hold &test)
{
  REQUIRE(hold.value == test.value);
  catch_test_port_tchk(hold.input,test.input);
  catch_test_port_tchk(hold.output,test.output);
}

void SDF::Test::catch_test_timing_checks(std::vector<TimingCheck> &checks, std::vector<TimingCheck> &tests)
{
  REQUIRE(checks.size() == tests.size());
  view::zip_with(
    [](auto check, auto test) -> void { 
      REQUIRE(check.get_enum_type()==test.get_enum_type());
      switch (test.get_enum_type()) {
        case TimingCheckType::hold:
          REQUIRE(std::holds_alternative<Hold>(check.value));
          
          catch_test_hold_check(std::get<Hold>(check.value),
                                    std::get<Hold>(test.value));
                                    
          break;
        default:
          throw std::runtime_error("InternalError");
      }
    },
    checks,tests
  );      
}

void SDF::Test::catch_test_timing_specs(std::vector<TimingSpec> specs, std::vector<TimingSpec> tests)
{
  view::zip_with(
    [](auto spec, auto test) -> void { 
      REQUIRE(spec.get_enum_type()==test.get_enum_type());
      switch (test.get_enum_type()) {
        case TimingSpecType::delay:
          throw std::runtime_error("InternalError");  
          break;
        case TimingSpecType::timing_check:
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

void SDF::Test::catch_test_cell(Cell cell, Cell test)
{

  REQUIRE(cell.cell_type == test.cell_type);
  REQUIRE(cell.cell_instance == test.cell_instance);

  REQUIRE(cell.timing_specs.size() == test.timing_specs.size());
  catch_test_timing_specs(cell.timing_specs, test.timing_specs);
}


void SDF::Test::catch_test_cells(std::vector<Cell> cells, std::vector<Cell> tests)
{

  REQUIRE(cells.size() == tests.size());

  view::zip_with(
    [](auto cell, auto test) -> void { 
      catch_test_cell(cell, test);
    },
    cells, tests
  );        

}