#include "./grammar.hpp"


using namespace Parse::Test;
using namespace Verilog::IEEE1364_2001;
using namespace Test::Verilog::IEEE1364_2001::Grammar;

TEST_CASE("Verilog.IEEE1364_2001.Grammar.Grammer", "[Verilog][IEEE1364_2001][Grammar][Grammar]") {

  SECTION("identifier"){
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::identifier>(module_keyword));
  }
  
  SECTION("module_keyword"){
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::module_keyword>(module_keyword));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_1"){
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_1));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_2"){
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_2));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_3"){
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_3));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_4"){
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_4));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_5"){
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_5));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_6"){
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_6));
  }

  SECTION("\'module_declaration_hack\' with input module_declaration_7"){
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::module_declaration_hack>(module_declaration_7));
  }
  
 SECTION("\'description_hack\' with input module_declaration_1"){
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_1));
  }

  SECTION("\'description_hack\' with input module_declaration_2"){
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_2));
  }

  SECTION("\'description_hack\' with input module_declaration_3"){
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_3));
  }

  SECTION("\'description_hack\' with input module_declaration_4"){
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_4));
  }

  SECTION("\'description_hack\' with input module_declaration_5"){
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_5));
  }

  SECTION("\'description_hack\' with input module_declaration_6"){
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_6));
  }

  SECTION("\'description_hack\' with input module_declaration_7"){
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::description_hack>(module_declaration_7));
  }
  

  SECTION("module_example_1"){
    CAPTURE(module_example_1);
    CHECK(match_exactly<Grammar::grammar_hack>(module_example_1));
  }

  SECTION("module_example_2"){
    CAPTURE(module_example_2);
    CHECK(match_exactly<Grammar::grammar_hack>(module_example_2));
  }


  SECTION(fmt::format(
      "Testing DRO Verilog Example (dro_example): \n{}\n",
        dro_example)) {

      CHECK(match_exactly<Grammar::grammar_hack>(dro_example));

  }

  SECTION(fmt::format(
      "Testing DRO Verilog Testbench Example (tb_dro_example) : \n{}\n",
        tb_dro_example)) {

      CHECK(match_exactly<Grammar::grammar_hack>(tb_dro_example));

  }

}