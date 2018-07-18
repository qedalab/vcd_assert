
#include "../types/cell.hpp"

#include <parse/test/parse.hpp>

#include <sdf/actions/cell.hpp>
#include <sdf/actions/timing_spec.hpp>
#include <sdf/grammar/timing.hpp>

#include <sdf/serialize/cell.hpp>

// #include <range/v3/algorithm/copy.hpp>
#include <range/v3/utility/iterator.hpp>

#include <variant>
#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace SDF;
using namespace SDF::Test;
using Parse::Test::require_parse;


TEST_CASE("SDF.Actions.CellAction", "[SDF][Actions][CellAction]") {
  Cell test{}; 

  SECTION("CellAction"){

    Cell wanted = test_cell_1;

    
    std::string wanted_serialized;
    serialize_cell(ranges::back_inserter(wanted_serialized), 0,
                                  wanted);
    CAPTURE(wanted_serialized);

    // CAPTURE(test_cell_1_str);
    require_parse<Grammar::cell,
                  Actions::CellAction>(wanted_serialized, test);
  
    std::string test_serialized;
    serialize_cell(ranges::back_inserter(test_serialized), 0,
                                  test);
    CAPTURE(test_serialized);
  
  
    catch_test_cell(wanted,test);
  }  
}


// TEST_CASE("SDF.Actions.CellAction", "[SDF][Actions][CellAction]") {
//   std::vector<TimingSpec> test{};
//   SECTION("TimingSpecArrayAction"){
//     INFO("test_timingspecspec_1_str : " << test_timingspecspec_1_sv);
//        std::vector<TimingSpec> wanted = test_timingspecspec_1;
//       require_parse<Grammar::tc_spec,
//                     Actions::TimingCheckArrayAction>(test_timingspecspec_1_sv, test);
//       catch_test_timingspecspec(wanted,test);
//   }  
// }

