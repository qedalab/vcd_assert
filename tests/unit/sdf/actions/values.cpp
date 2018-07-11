
#include "../types/values.hpp"
#include <sdf/actions/values.hpp>
#include <sdf/grammar/values.hpp>

#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <parse/test/parse.hpp>

using namespace SDF;
using namespace SDF::Test;
using Parse::Test::require_parse;


TEST_CASE("SDF.Actions.Number", "[SDF][Actions][Number]") {
  
  
  SECTION(fmt::format("Number {}", test_number_1_sv)) {

    Number test{};
    Number wanted{test_number_1};

    require_parse<Grammar::real_number, Actions::NumberAction>(
        test_number_1_sv, test);
    CAPTURE(wanted);
    CAPTURE(test);
    REQUIRE(test == wanted);
  }


  SECTION("Should parse unsigned values") {

    Number test{};
    Number wanted{test_number_2};
    INFO(fmt::format("Number {}", test_number_2_sv))
      
    require_parse<Grammar::signed_real_number, Actions::NumberAction>(
        test_number_2_sv, test);

    CAPTURE(wanted);
    CAPTURE(test);
    REQUIRE(test == wanted);

  }
}

TEST_CASE("SDF.Actions.Triple", "[SDF][Actions][Triple]") {

  SECTION("Should parse unsigned values") {

    Triple test{};
    Triple wanted{test_triple_1};
    INFO(fmt::format("Triple {}", test_triple_1_sv))
      
    require_parse<Grammar::triple, Actions::TripleAction<Grammar::real_number>>(
        test_triple_1_sv, test);

    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);

    REQUIRE(test.min == wanted.min); 

    REQUIRE(test.typ == wanted.typ); 

    REQUIRE(test.max == wanted.max);

    // catch_test_triple(wanted, test);
  }

  SECTION("Should parse unsigned values") {

    Triple test{};
    Triple wanted{test_triple_4};
    INFO(fmt::format("Triple {}", test_triple_4_sv))
      
    require_parse<Grammar::rtriple, Actions::TripleAction<Grammar::signed_real_number>>(
        test_triple_4_sv, test);

    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);
    
    REQUIRE(test.min == wanted.min); 

    REQUIRE(test.typ == wanted.typ); 

    REQUIRE(test.max == wanted.max);
    // catch_test_triple(wanted, test);
  }
}
