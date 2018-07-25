#include "../design.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"


#include <fmt/format.h>

// #include "parse/test/parse.hpp"

#include <catch2/catch.hpp>
#include "parse/test/match.hpp"

using namespace Verilog::Test::Verilog::IEEE1364_2001;
using namespace Verilog::IEEE1364_2001;


TEST_CASE("Verilog.IEEE1364_2001.Grammar.Grammer", "[Verilog][IEEE1364_2001][Grammar][Grammar]") {

  using Parse::Test::match_exactly;
  SECTION("identifier"){
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::identifier>(module_keyword));
  }
  
  SECTION("module_keyword"){
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::module_keyword>(module_keyword));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_1"){
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_1));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_2"){
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_2));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_3"){
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_3));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_4"){
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_4));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_5"){
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_5));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_6"){
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_6));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_7"){
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_7));
  }
  
 SECTION("\'_module_description_\' with input module_declaration_1"){
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_1));
  }

  SECTION("\'_module_description_\' with input module_declaration_2"){
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_2));
  }

  SECTION("\'_module_description_\' with input module_declaration_3"){
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_3));
  }

  SECTION("\'_module_description_\' with input module_declaration_4"){
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_4));
  }

  SECTION("\'_module_description_\' with input module_declaration_5"){
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_5));
  }

  SECTION("\'_module_description_\' with input module_declaration_6"){
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_6));
  }

  SECTION("\'_module_description_\' with input module_declaration_7"){
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_7));
  }
  

  SECTION("module_example_1"){
    CAPTURE(module_example_1);
    CHECK(match_exactly<Grammar::_grammar_>(module_example_1));
  }

  SECTION("module_example_2"){
    CAPTURE(module_example_2);
    CHECK(match_exactly<Grammar::_grammar_>(module_example_2));
  }


  SECTION(fmt::format(
      "Testing DRO Verilog Example (dro_example): \n{}\n",
        dro_example)) {

      CHECK(match_exactly<Grammar::_grammar_>(dro_example));

  }

  SECTION(fmt::format(
      "Testing DRO Verilog Testbench Example (tb_dro_example) : \n{}\n",
        tb_dro_example)) {

      CHECK(match_exactly<Grammar::_grammar_>(tb_dro_example));

  }

}