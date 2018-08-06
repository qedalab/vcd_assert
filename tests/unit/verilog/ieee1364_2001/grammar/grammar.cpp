#include "../design.hpp"
#include "../design_temp.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"

#include <fmt/format.h>

// #include "parse/test/parse.hpp"

#include "parse/test/match.hpp"
#include <catch2/catch.hpp>

using namespace Verilog::Test::Verilog::IEEE1364_2001;
using namespace Verilog::IEEE1364_2001;

TEST_CASE("Verilog.IEEE1364_2001.Grammar.Grammer",
          "[Verilog][IEEE1364_2001][Grammar][Grammar]")
{

  using Parse::Test::match_exactly;

  SECTION("keyword not an identifier")
  {
    CAPTURE(module_keyword);
    CHECK_FALSE(match_exactly<Grammar::identifier>(module_keyword));
  }

  SECTION("keyword")
  {
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::keyword>(module_keyword));
  }

  SECTION("include_statement")
  {
    CAPTURE(include_statement);
    CHECK(match_exactly<Grammar::include_statement>(include_statement));
  }

  SECTION("include_statement incorrect input")
  {
    CAPTURE(include_statement_no_qstring);
    CHECK_FALSE(match_exactly<Grammar::include_statement>(
        include_statement_no_qstring));
  }

  SECTION("compiler_directive")
  {
    CAPTURE(compiler_directive);
    CHECK(match_exactly<Grammar::compiler_directive>(compiler_directive));
  }

  SECTION("compiler_directive incorrect input")
  {
    CAPTURE(include_statement_no_qstring);
    CHECK_FALSE(match_exactly<Grammar::compiler_directive>(
        include_statement_no_qstring));
  }

  SECTION("module_keyword")
  {
    CAPTURE(module_keyword);
    CHECK(match_exactly<Grammar::module_keyword>(module_keyword));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_1")
  {
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_1));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_2")
  {
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_2));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_3")
  {
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_3));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_4")
  {
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_4));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_5")
  {
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_5));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_6")
  {
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_6));
  }

  SECTION("\'_module_declaration_\' with input module_declaration_7")
  {
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::_module_declaration_>(module_declaration_7));
  }

  SECTION("\'_module_description_\' with input module_declaration_1")
  {
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_1));
  }

  SECTION("\'_module_description_\' with input module_declaration_2")
  {
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_2));
  }

  SECTION("\'_module_description_\' with input module_declaration_3")
  {
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_3));
  }

  SECTION("\'_module_description_\' with input module_declaration_4")
  {
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_4));
  }

  SECTION("\'_module_description_\' with input module_declaration_5")
  {
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_5));
  }

  SECTION("\'_module_description_\' with input module_declaration_6")
  {
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_6));
  }

  SECTION("\'_module_description_\' with input module_declaration_7")
  {
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::_module_description_>(module_declaration_7));
  }

  SECTION("\'_grammar_\' with input module_declaration_1")
  {
    CAPTURE(module_declaration_1);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_1));
  }

  SECTION("\'_grammar_\' with input module_declaration_2")
  {
    CAPTURE(module_declaration_2);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_2));
  }

  SECTION("\'_grammar_\' with input module_declaration_3")
  {
    CAPTURE(module_declaration_3);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_3));
  }

  SECTION("\'_grammar_\' with input module_declaration_4")
  {
    CAPTURE(module_declaration_4);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_4));
  }

  SECTION("\'_grammar_\' with input module_declaration_5")
  {
    CAPTURE(module_declaration_5);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_5));
  }

  SECTION("\'_grammar_\' with input module_declaration_6")
  {
    CAPTURE(module_declaration_6);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_6));
  }

  SECTION("\'_grammar_\' with input module_declaration_7")
  {
    CAPTURE(module_declaration_7);
    CHECK(match_exactly<Grammar::_grammar_>(module_declaration_7));
  }

  SECTION("module_example_1")
  {
    CAPTURE(module_example_1);
    CHECK(match_exactly<Grammar::_grammar_>(module_example_1));
  }

  SECTION("module_example_2")
  {
    CAPTURE(module_example_2);
    CHECK(match_exactly<Grammar::_grammar_>(module_example_2));
  }

  SECTION("sdf_annotate_example")
  {
    CAPTURE(sdf_annotate_example);
    CHECK(match_exactly<Grammar::sdf_annotate_task>(sdf_annotate_example));
  }

  SECTION("begin_end_example_1")
  {
    CAPTURE(begin_end_example_1);
    CHECK(match_exactly<Grammar::unimplemented_begin_end>(begin_end_example_1));
  }

  SECTION("begin_end_example_2")
  {
    CAPTURE(begin_end_example_2);
    CHECK(match_exactly<Grammar::unimplemented_begin_end>(begin_end_example_2));
  }

  SECTION("begin_end_example_3")
  {
    CAPTURE(begin_end_example_3);
    CHECK(match_exactly<Grammar::unimplemented_begin_end>(begin_end_example_3));
  }

  SECTION("begin_end_example_4")
  {
    CAPTURE(begin_end_example_4);
    CHECK(match_exactly<Grammar::unimplemented_begin_end>(begin_end_example_4));
  }

  SECTION("initial_block_example_1")
  {
    CAPTURE(initial_block_example_1);
    CHECK(match_exactly<Grammar::initial_block>(initial_block_example_1));
  }

  SECTION("initial_block_example_2")
  {
    CAPTURE(initial_block_example_2);
    CHECK(match_exactly<Grammar::initial_block>(initial_block_example_2));
  }

  SECTION("initial_block_example_3")
  {
    CAPTURE(initial_block_example_3);
    INFO("Should not allow whitespace after last end keyword");
    CHECK_FALSE(match_exactly<Grammar::initial_block>(initial_block_example_3));
  }

  SECTION("initial_block_example_4")
  {
    CAPTURE(initial_block_example_4);
    CHECK(match_exactly<Grammar::initial_block>(initial_block_example_4));
  }

  SECTION("initial_block_with_sdf_example_1")
  {
    CAPTURE(initial_block_with_sdf_example_1);
    CHECK(match_exactly<Grammar::initial_block>(
        initial_block_with_sdf_example_1));
  }

  SECTION(fmt::format("Testing DRO Verilog Example (dro_example): \n{}\n",
                      dro_example))
  {

    CHECK(match_exactly<Grammar::_grammar_>(dro_example));
  }

  SECTION(fmt::format(
      "Testing DRO Verilog Testbench Example (tb_dro_example) : \n{}\n",
      tb_dro_example))
  {

    CHECK(match_exactly<Grammar::_grammar_>(tb_dro_example));
  }
}

// std::array<TimeScaleTest, 6> time_scale_tests{
//     TimeScaleTest{"$timescale 1\n s $end", TimeNumber::_1, TimeUnit::s},
//     TimeScaleTest{"$timescale  10 ms $end", TimeNumber::_10, TimeUnit::ms},
//     TimeScaleTest{"$timescale 100 us $end", TimeNumber::_100, TimeUnit::us},
//     TimeScaleTest{"$timescale 1ns $end", TimeNumber::_1, TimeUnit::ns},
//     TimeScaleTest{"$timescale 10  ps  $end", TimeNumber::_10, TimeUnit::ps},
//     TimeScaleTest{"$timescale 100 fs $end", TimeNumber::_100, TimeUnit::fs},
// };

// TEST_CASE("VCD.Events.TimeScale", "[VCD][Events][TimeScale]")
// {
//   using Parse::Test::require_parse;

//   TimeScaleView event{};

//   for (auto &&test : time_scale_tests) {
//     SECTION(std::string(test.str))
//     {
//       require_parse<Grammar::timescale_command, Actions::TimeScaleAction>(
//           test.str, event);

//       CHECK(event.unit == test.unit);
//       CHECK(event.number == test.number);
//     }
//   }
// }
