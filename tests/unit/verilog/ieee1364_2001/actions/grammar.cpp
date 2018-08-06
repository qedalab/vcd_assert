#include "../design.hpp"
#include "../design_temp.hpp"

#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
#include "verilog/util/parse_input.hpp"

#include "parse/actions/control.hpp"
#include "parse/actions/make_pegtl_template.hpp"
#include "parse/test/match.hpp"
#include "parse/test/parse.hpp"
#include "parse/util/static_string.hpp"

#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>

#include <catch2/catch.hpp>
#include <parse/util/filesystem.hpp>
#include <range/v3/view/indices.hpp>

#include <string>
#include <string_view>

using namespace Verilog;

using namespace Verilog::IEEE1364_2001;
using namespace Verilog::Test::Verilog::IEEE1364_2001;

namespace VerilogTest = Verilog::Test::Verilog::IEEE1364_2001;
namespace VerilogGrammar = Verilog::IEEE1364_2001::Grammar;
namespace fs = Parse::Util::fs;
namespace rsv = ranges::view;

TEST_CASE("Verilog.Actions.Design", "[Verilog][Events][Design]")
{

  SECTION("dro only, from memory")
  {
    DesignReader reader;
    tao::pegtl::memory_input<> input(dro_example, "dro");

    Verilog::Util::InputMap inputs{};

    for (auto &&pass : rsv::indices(2)) {
      bool first_pass = pass == 0;
      REQUIRE(tao::pegtl::parse<
              VerilogGrammar::_grammar_,
              Parse::make_pegtl_template<Actions::GrammarAction>::type,
              Parse::capture_control>(input, reader, inputs, first_pass));
    }

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());
    // Test::catch_test_design(*design_p, dro_example);
  }

  SECTION("both tb_dro and dro from memory")
  {
    Verilog::DesignReader reader{};

    std::string test_string{dro_example};
    const char *test_string_p = test_string.c_str();

    tao::pegtl::memory_input<> input_tb_dro(tb_dro_example, "tb_dro");

    Verilog::Util::InputMap inputs{};
    inputs.emplace(
        "dro.v", // include_string
        Verilog::Util::ParseInput{
            Verilog::Util::InputTypeEnum::const_char_pointer, test_string_p});

    for (auto &&pass : rsv::indices(2)) {

      bool first_pass = (pass == 0);
      REQUIRE(tao::pegtl::parse<
              VerilogGrammar::_grammar_,
              Parse::make_pegtl_template<Actions::GrammarAction>::type,
              Parse::capture_control>(input_tb_dro, reader, inputs,
                                      first_pass));
    }

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());
    // VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
    // // Test::catch_test_design(*design_p, dro_example);
  }

  SECTION("dro only, from file")
  {
    Verilog::DesignReader reader{};

    tao::pegtl::file_input<> input(dro_file_path_abs_.to_string_view());

    Verilog::Util::InputMap inputs{}; // unused

    for (auto &&pass : rsv::indices(2)) {

      bool first_pass = pass == 0;
      REQUIRE(tao::pegtl::parse<
              VerilogGrammar::_grammar_,
              Parse::make_pegtl_template<Actions::GrammarAction>::type,
              Parse::capture_control>(input, reader, inputs, first_pass));
    }

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());
    // Test::catch_test_design(*design_p, dro_example);
    // VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
  }

  SECTION("both tb_dro and dro from file")
  {
    Verilog::DesignReader reader{};
    Verilog::Util::InputMap inputmap{}; // no library files.

    tao::pegtl::file_input<> input_tb_dro(
        tb_dro_file_path_abs_.to_string_view());
    tao::pegtl::file_input<> input_dro(dro_file_path_abs_.to_string_view());

    REQUIRE(tao::pegtl::parse<
            VerilogGrammar::_grammar_,
            Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input_dro, reader, inputmap, 1));

    REQUIRE(tao::pegtl::parse<
            VerilogGrammar::_grammar_,
            Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input_tb_dro, reader, inputmap, 1));

    input_dro.restart();
    input_tb_dro.restart();

    REQUIRE(tao::pegtl::parse<
            VerilogGrammar::_grammar_,
            Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input_dro, reader, inputmap, 0));

    REQUIRE(tao::pegtl::parse<
            VerilogGrammar::_grammar_,
            Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input_tb_dro, reader, inputmap, 0));

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());

    VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
  }

  // void catch_test_design()
}

// Verilog::CatchDesign::test()
