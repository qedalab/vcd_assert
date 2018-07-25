#include "verilog/ieee1364_2001/actions/grammar.hpp"

// Test::Design dro_example_design_test {
//   { //vector
//     { //module
//       "dro",   // identifier
//       {},      // instances
//       {},      // variable
//       {}       // attributes
//     }
//   },
//   {},
//   {},
//   {},

//   Test::Net { 
//       NetType::module, //type_
//       "dro",           //identifier_    //what to name root net ?
//       (std::size_t)0   //definition_index_ 
//       {
//           // No child nets
//       },
//       {
//           // No variables 
//       }
//   }
// };

// Test::Design tb_dro_example_design_test {
//   { //vector
//     { //module
//       "dro",   // identifier
//       {},      // instances
//       {},      // variable
//       {}       // attributes
//     }
//   },
//   {},
//   {},
//   {},

//   Test::Net { 
//       NetType::module, //type_
//       "dro",           //identifier_    //what to name root net ?
//       (std::size_t)0   //definition_index_ 
//       {
//           // No child nets
//       },
//       {
//           // No variables 
//       }
//   }
// };

// TEST_CASE("Verilog.Events.Design", "[Verilog][Events][Design]") {
//   SECTION("dro example"){
    
//     DesignReader reader;
//     require_parse<Grammar::_grammar_, Actions::GrammarAction>(
//         dro_example, reader);

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
