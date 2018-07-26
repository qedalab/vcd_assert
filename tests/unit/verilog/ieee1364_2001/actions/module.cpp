#include "../design.hpp"

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

#include <string>
#include <string_view>

using namespace Verilog::Test::Verilog::IEEE1364_2001;
using namespace Verilog::IEEE1364_2001;

namespace __Grammar = Verilog::IEEE1364_2001::Grammar;

TEST_CASE("Verilog.Actions.Module", "[Verilog][Events][Module]")
{
  SECTION("sdf annotation action"){

    Verilog::DesignReader reader;
    memory_input<> input(dro_example, "dro");

    Verilog::Util::InputMap inputs{};

    REQUIRE(tao::pegtl::parse<
            __Grammar::_grammar_, Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input, reader, inputs));
  
  }
  
  SECTION("sdf annotation from module declartion action"){

    Verilog::DesignReader reader;
    memory_input<> input(dro_example, "dro");

    Verilog::Util::InputMap inputs{};

    REQUIRE(tao::pegtl::parse<
            __Grammar::_grammar_, Parse::make_pegtl_template<Actions::GrammarAction>::type,
            Parse::capture_control>(input, reader, inputs));
  
  }
}