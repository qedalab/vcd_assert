#include "../types/timing_spec.hpp"

#include <parse/test/parse.hpp>

#include <sdf/actions/timing_check.hpp>
#include <sdf/actions/timing_spec.hpp>
#include <sdf/grammar/timing_spec.hpp>

#include <variant>
#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace SDF;
using namespace SDF::Test;
using Parse::Test::require_parse;


TEST_CASE("SDF.Actions.TimingSpecAction", "[SDF][Actions][TimingSpecAction]") {
  TimingSpec test{}; 
  SECTION("TimingSpec"){
    SECTION("test_timingspec_1_str :"){
      TimingSpec wanted = test_timingspec_1;
      require_parse<Grammar::timing_spec,
                    Actions::TimingSpecAction>(test_timingspec_1_sv, test);
      catch_test_timingspec(wanted,test);
    }
  }  
}
