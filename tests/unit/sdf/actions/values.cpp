#include "../types/values.hpp"

#include <parse/test/parse.hpp>

#include <sdf/actions/values.hpp>
#include <sdf/grammar/values.hpp>

#include <variant>
#include <catch2/catch.hpp>
#include <fmt/format.h>

using namespace SDF;
using namespace SDF::Test;
using Parse::Test::require_parse;


TEST_CASE("SDF.Actions.Number", "[SDF][Actions][Number]") {
  
  
  SECTION("Unsigned Number") {

    Number test{};
    Number wanted{test_number_1};
    INFO(fmt::format("Number {}", test_number_1_sv))

    require_parse<Grammar::real_number, Actions::NumberAction>(
        test_number_1_sv, test);
    CAPTURE(wanted);
    CAPTURE(test);
    REQUIRE(test == wanted);
  }


  SECTION("Signed Number") {

    Number test{};
    Number wanted{test_number_2};
    INFO(fmt::format("Number {}", test_number_2_sv))
      
    require_parse<Grammar::signed_real_number, Actions::NumberAction>(
        fmt::format("{}", test_number_2_sv), test);

    CAPTURE(wanted);
    CAPTURE(test);
    REQUIRE(test == wanted);

  }
}

TEST_CASE("SDF.Actions.Triple", "[SDF][Actions][Triple]") {

  SECTION("Triple of unsigned numbers") {

    Triple test{};
    Triple wanted = test_triple_1;
    INFO(fmt::format("Triple {}", test_triple_1_sv))
      
    require_parse<Grammar::triple, Actions::TripleAction<Grammar::real_number>>(
        fmt::format("{}", test_triple_1_sv), test);

    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);

    REQUIRE( test.min == Approx(wanted.min)); 
    REQUIRE( test.typ == Approx(wanted.typ)); 
    REQUIRE( test.max == Approx(wanted.max));

    // catch_test_triple(wanted, test);
  }
  
  SECTION("Triple of signed numbers") {

    Triple test{};
    Triple wanted{test_triple_4};
    INFO(fmt::format("Triple {}", test_triple_4_sv))
      
    require_parse<Grammar::rtriple, Actions::TripleAction<Grammar::signed_real_number>>(
        fmt::format("{}", test_triple_4_sv), test);
    
    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);
    
    REQUIRE(test.min == Approx(wanted.min) ); 
    REQUIRE(test.typ == Approx(wanted.typ) ); 
    REQUIRE(test.max == Approx(wanted.max) );
    // catch_test_triple(wanted, test);
  }

}

TEST_CASE("SDF.Actions.Value", "[SDF][Actions][Value]") {
  
  SECTION("Value with unsigned single number") {

    Value test{};
    Number wanted{test_number_1};
    INFO(fmt::format("Value ({})", test_number_1_sv))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::value, Actions::ValueAction>(
        fmt::format("({})", test_number_1_sv), test);
    
    REQUIRE(std::holds_alternative<Number>(test)); 
    Number result = std::get<Number>(test);

    CAPTURE(result);
    REQUIRE(result == wanted); 
  }

  SECTION("Value with signed single number") {

    Value test{};
    Number wanted{test_number_2};
    INFO(fmt::format("Value ({})", test_number_2_sv))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::rvalue, Actions::ValueAction>(
        fmt::format("({})", test_number_2_sv), test);
    
    REQUIRE(std::holds_alternative<Number>(test)); 
    Number result = std::get<Number>(test);

    CAPTURE(result);
    REQUIRE(result == wanted);
    // catch_test_triple(wanted, test);
  }

  SECTION("Value with unsigned triple numbers") {

    Value test{};
    Triple wanted{test_triple_2};
    INFO(fmt::format("Value ({})", test_triple_2_sv))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::value, Actions::ValueAction>(
        fmt::format("({})", test_triple_2_sv), test);
    
    REQUIRE(std::holds_alternative<Triple>(test)); 
    Triple result = std::get<Triple>(test);

    CAPTURE(result.min);
    CAPTURE(result.typ);
    CAPTURE(result.max);
    
    REQUIRE(result.min == Approx(wanted.min)); 
    REQUIRE(result.typ == Approx(wanted.typ)); 
    REQUIRE(result.max == Approx(wanted.max));
    // catch_test_triple(wanted, test);
  }

  SECTION("Value triple with signed numbers") {

    Value test{};
    Triple wanted{test_triple_4};
    INFO(fmt::format("Value ({})", test_triple_4_sv))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::rvalue, Actions::ValueAction>(
        fmt::format("({})", test_triple_4_sv), test);
    
    REQUIRE(std::holds_alternative<Triple>(test)); 
    Triple result = std::get<Triple>(test);

    CAPTURE(result.min);
    CAPTURE(result.typ);
    CAPTURE(result.max);
    
    REQUIRE(result.min == Approx(wanted.min)); 
    REQUIRE(result.typ == Approx(wanted.typ)); 
    REQUIRE(result.max == Approx(wanted.max));
    // catch_test_triple(wanted, test);
  }

}
