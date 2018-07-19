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
    INFO(fmt::format("Number {}", test_number_1_str.to_string_view()))

    require_parse<Grammar::real_number, Actions::NumberAction>(
        test_number_1_str.to_string_view(), test);
    CAPTURE(wanted);
    CAPTURE(test);
    if(wanted.has_value()){
      REQUIRE(test.has_value());
      REQUIRE(test.value() == wanted.value());
    }
  }


  SECTION("Signed Number") {

    Number test{};
    Number wanted{test_number_2};
    INFO(fmt::format("Number {}", test_number_2_str.to_string_view()))
      
    require_parse<Grammar::signed_real_number, Actions::NumberAction>(
        fmt::format("{}", test_number_2_str.to_string_view()), test);

    CAPTURE(wanted);
    CAPTURE(test);
    CAPTURE(test);
    if(wanted.has_value()){
      REQUIRE(test.has_value());
      REQUIRE(test.value() == wanted.value());
    }

  }
}

TEST_CASE("SDF.Actions.Triple", "[SDF][Actions][Triple]") {

  SECTION("Triple of unsigned numbers") {

    Triple test{};
    Triple wanted = test_triple_1;
    INFO(fmt::format("Triple {}", test_triple_1_str.to_string_view()))
      
    require_parse<Grammar::triple, Actions::TripleAction<Grammar::real_number>>(
        fmt::format("{}", test_triple_1_str.to_string_view()), test);

    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);

    catch_test_triple(wanted,test);
  }
  
  SECTION("Triple of signed numbers") {

    Triple test{};
    Triple wanted{test_triple_4};
    INFO(fmt::format("Triple {}", test_triple_4_str.to_string_view()))
      
    require_parse<Grammar::rtriple, Actions::TripleAction<Grammar::signed_real_number>>(
        fmt::format("{}", test_triple_4_str.to_string_view()), test);
    
    CAPTURE(test.min);
    CAPTURE(test.typ);
    CAPTURE(test.max);
    
    catch_test_triple(wanted,test);
  }

}

TEST_CASE("SDF.Actions.Value", "[SDF][Actions][Value]") {
  
  SECTION("Value with unsigned single number") {

    Value test{};
    Number wanted{test_number_1};
    INFO(fmt::format("Value ({})", test_number_1_str.to_string_view()))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::value, Actions::ValueAction>(
        fmt::format("({})", test_number_1_str.to_string_view()), test);
    
    REQUIRE(std::holds_alternative<Number>(test)); 
    Number result = std::get<Number>(test);

    CAPTURE(result);
    if(wanted.has_value()){
      REQUIRE(result.has_value());
      REQUIRE(result.value() == wanted.value());
    }
  }

  SECTION("Value with signed single number") {

    Value test{};
    Number wanted{test_number_2};
    INFO(fmt::format("Value ({})", test_number_2_str.to_string_view()))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::rvalue, Actions::ValueAction>(
        fmt::format("({})", test_number_2_str.to_string_view()), test);
    
    REQUIRE(std::holds_alternative<Number>(test)); 
    Number result = std::get<Number>(test);

    CAPTURE(result);
    if(wanted.has_value()){
      REQUIRE(result.has_value());
      REQUIRE(result.value() == wanted.value());
    }
  }

  SECTION("Value with unsigned triple numbers") {

    Value test{};
    Triple wanted{test_triple_2};
    INFO(fmt::format("Value ({})", test_triple_2_str.to_string_view()))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::value, Actions::ValueAction>(
        fmt::format("({})", test_triple_2_str.to_string_view()), test);
    
    REQUIRE(std::holds_alternative<Triple>(test)); 
    Triple result = std::get<Triple>(test);

    CAPTURE(result.min);
    CAPTURE(result.typ);
    CAPTURE(result.max);
    
    catch_test_triple(wanted, result);
  }

  SECTION("Value triple with signed numbers") {

    Value test{};
    Triple wanted{test_triple_4};
    INFO(fmt::format("Value ({})", test_triple_4_str.to_string_view()))
      
    // require_parse<Grammar::rvalue, Actions::ValueAction<Grammar::signed_real_number>>(
    require_parse<Grammar::rvalue, Actions::ValueAction>(
        fmt::format("({})", test_triple_4_str.to_string_view()), test);
    
    REQUIRE(std::holds_alternative<Triple>(test)); 
    Triple result = std::get<Triple>(test);

    CAPTURE(result.min);
    CAPTURE(result.typ);
    CAPTURE(result.max);
    
    catch_test_triple(wanted, result);
  }

}
