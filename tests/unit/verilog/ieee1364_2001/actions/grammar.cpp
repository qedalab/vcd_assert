#include "../design.hpp"
#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"


#include <catch2/catch.hpp>
#include "parse/test/parse.hpp"
#include "parse/test/match.hpp"


using namespace Test::Verilog::IEEE1364_2001;
using namespace Verilog::IEEE1364_2001;
using Parse::Test::require_parse;

// TEST_CASE("Verilog.Actions.Design", "[Verilog][Events][Design]") {
  
//   SECTION("dro example"){
//     DesignReader reader;
//     require_parse<Grammar::_grammar_, Actions::GrammarAction>(
//         dro_example, reader, );

//     auto design_p = reader.release();
//     REQUIRE(design_p.operator bool());
//     Test::catch_test_design(*design_p, dro_example);
//   }
  
//   SECTION("tb_dro example"){
    

//     DesignReader reader;
//     require_parse<Grammar::_grammar_, Actions::GrammarAction>(
//         tb_dro_example, reader);

//     auto design_p = reader.release();
//     REQUIRE(design_p.operator bool());
//     Test::catch_test_design(*design_p, tb_dro_example);
//   }
  
//   using Parse::Test::require_parse;


// }
