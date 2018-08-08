
#include "../../test.hpp"
// #include "../design_temp.hpp"

#include "verilog/ieee1800_2012/actions/command_listener.hpp"
#include "verilog/types/enums.hpp"
// #include "verilog/ieee1800_2012/actions/grammar.hpp"
#include "parse/util/filesystem.hpp"

#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include <iostream>
#include <range/v3/algorithm/reverse.hpp>
#include <range/v3/distance.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>
#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>

#include "SV2012BaseListener.h"
#include "SV2012Lexer.h"
#include "SV2012Parser.h"
#include "verilog/antlr_runtime.hpp"

using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;

    // CAPTURE(tb_dro_example);



TEST_CASE("Verilog.Actions.CommandListener",
          "[Verilog][Actions][CommandListener]")
{

  SECTION("sdf annotation full")
  {
    DesignView full_example {
      // clang-format off
      { //vector of modules
        { //module (INCLUDED BEFORE MAIN MODULE)
          "basic_dro",      // identifier
          dro_file_path_abs_.to_string(), // path      
          {}       // instances lookup
        },
        { //module
          "tb_basic_dro",   // identifier
          tb_dro_file_path_abs_.to_string(), // path
          {// instances lookup
            {"DUT",0}
          }   
        }
      },
      { //vector of instances
        {
          NetType::module,  //type_
          "DUT",            //identifier_    //what to name root net ?
          0 // index of dro module in module list
        }
      },
      { //module lookup
        {"basic_dro", 0},
        {"tb_basic_dro", 1}
      },
      { //sdf_commands total
        { // sdf_commands for tb_dro module
        }
      }, 
      { //sdf_commands_lookup_
      }  
    // clang-format on
    };

    INFO("Setup test data");
    DesignReader reader{};
    
    /*TEST REQUIRES THAT reader be partially provisioned with module stuff*/
    reader.module("tb_basic_dro", tb_dro_file_path_abs_.to_string());


    INFO("Setup parsing");
    ANTLRInputStream input(tb_dro_example);

    
    INFO("Parse input into parse tree");
    SV2012Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SV2012Parser parser(&tokens);  
    /*auto *tree =*/ parser.source_text();
    // std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

    INFO("Initialize listener");
    // CommandListener cl(parser, reader, tb_dro_file_path_abs_.to_string());

    INFO("Walk tree with listener");
    // tree::ParseTreeWalker walker{};
    // walker.walk(cl, tree);

    FAIL();
  }
}