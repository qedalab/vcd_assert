#include "../design.hpp"
#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
#include "verilog/util/parse_input.hpp"

#include <utility>      // std::pair, std::make_pair
#include <catch2/catch.hpp>
// #include <.hpp>
#include "parse/test/parse.hpp"
#include "parse/test/match.hpp"
#include "parse/actions/make_pegtl_template.hpp"
#include "parse/actions/control.hpp"

#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>



using namespace Verilog::Test::Verilog::IEEE1364_2001;
// using namespace Verilog;
using namespace Verilog::IEEE1364_2001;

TEST_CASE("Verilog.Actions.Design", "[Verilog][Events][Design]") {
  
  using tao::pegtl::memory_input;
  using tao::pegtl::parse;
  using tao::pegtl::apply_mode;
  using tao::pegtl::rewind_mode;

  SECTION("dro only, from memory"){
    Verilog::DesignReader reader;
    memory_input<> input(dro_example, "dro");

    Verilog::Util::InputMap inputs{};

    using __Grammar = Verilog::IEEE1364_2001::Grammar::_grammar_;
    REQUIRE(tao::pegtl::parse<__Grammar,
                  Parse::make_pegtl_template<Actions::GrammarAction>::type,
                  Parse::capture_control
                  >(input,reader,inputs));

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());
    // Test::catch_test_design(*design_p, dro_example);
  }
  
  SECTION("both tb_dro and dro from memory"){
    Verilog::DesignReader reader;

    std::string test_string{dro_example};

    const char* test_string_p = test_string.c_str();
    
    memory_input<> input_tb_dro(tb_dro_example, "tb_dro");
    
    Verilog::Util::InputMap inputs{};
    inputs.emplace(
      "dro.v", //include_string
      Verilog::Util::ParseInput{
        Verilog::Util::InputTypeEnum::const_char_pointer,
        test_string_p});

    using __Grammar = Verilog::IEEE1364_2001::Grammar::_grammar_;
    REQUIRE(tao::pegtl::parse<__Grammar,
                  Parse::make_pegtl_template<Actions::GrammarAction>::type,
                  Parse::capture_control
                  >(input_tb_dro,reader,inputs));

    // auto design_p = reader.release();
    // REQUIRE(design_p.operator bool());
    // // Test::catch_test_design(*design_p, dro_example);
  }

  SECTION("dro only, from file"){
    Verilog::DesignReader reader;
    // memory_input<> input(dro_example, "dro");
    tao::pegtl::file_input<> input("../../dro.v");

    Verilog::Util::InputMap inputs{};

    using __Grammar = Verilog::IEEE1364_2001::Grammar::_grammar_;
    REQUIRE(tao::pegtl::parse<__Grammar,
                  Parse::make_pegtl_template<Actions::GrammarAction>::type,
                  Parse::capture_control
                  >(input,reader,inputs));

    auto design_p = reader.release();
    REQUIRE(design_p.operator bool());
    // Test::catch_test_design(*design_p, dro_example);
  }

  SECTION("both tb_dro and dro from file"){
    Verilog::DesignReader reader;

    std::string test_string{dro_example};

    const char* test_string_p = test_string.c_str();
    
    tao::pegtl::file_input<> input_tb_dro("../resources/examples/vcdassert/example_1/tb_dro.v");
    // file_input<> input_tb_dro("../../../src/tb_dro");
    
    Verilog::Util::InputMap inputs{};
    inputs.emplace(
      "dro.v", //include_string
      Verilog::Util::ParseInput{
        Verilog::Util::InputTypeEnum::file,
        test_string_p});

    using __Grammar = Verilog::IEEE1364_2001::Grammar::_grammar_;
    REQUIRE(tao::pegtl::parse<__Grammar,
                  Parse::make_pegtl_template<Actions::GrammarAction>::type,
                  Parse::capture_control
                  >(input_tb_dro,reader,inputs));

    // auto design_p = reader.release();
    // REQUIRE(design_p.operator bool());
    // // Test::catch_test_design(*design_p, dro_example);
  }


}
