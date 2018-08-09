
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

#include "SV2012BaseListener.h"
#include "SV2012Lexer.h"
#include "SV2012Parser.h"
#include "verilog/antlr_runtime.hpp"

using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;
using namespace antlr4::tree;
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

   /*
    const DelayFileView wanted = test_delayfile_1;

    //Delayfile from test delayfile view 
    DelayFileTester dft = DelayFileTester();
    auto test_delayfile_p = dft.get_test_delayfile(wanted);

    //serialize test delayfile
    std::string serialized;
    serialize_delayfile(ranges::back_inserter(serialized), test_delayfile_p);

    //parse serialized delayfile using DelayFileReader
    DelayFileReader test_reader{};
    require_parse<Grammar::delay_file, Actions::DelayFileAction>(
        serialized, test_reader);

    //get Delayfile from parse result
    auto test_p = test_reader.release();
    REQUIRE(test_p.operator bool());
    // auto& test = ;

    //compare delayfile from parse with original delayfile view.
    catch_test_delayfile(test_delayfile_1, *test_p);
   */



    INFO("Setup test data");
    
    auto reader_sp = std::make_shared<DesignReader>();
    
    /*TEST REQUIRES THAT reader be partially provisioned with module stuff*/
    reader_sp->module("tb_basic_dro", tb_dro_file_path_abs_.to_string());


    INFO("Setup parsing");
    ANTLRInputStream input(tb_dro_example);
    // CAPTURE(tb_dro_example);
    
    INFO("Parse input into parse tree");
    SV2012Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    
    auto parser_sp = std::make_shared<SV2012Parser>(&tokens) ;

    // auto parser_p = std::make_shared<SV2012Parser>(*parser);  

    auto *tree = parser_sp->source_text();

    std::cout << tree->toStringTree(parser_sp.get()) << std::endl << std::endl;

    INFO("Initialize listener");
    CommandListener cl(parser_sp,reader_sp);

    INFO("Walk tree with listener");
    ParseTreeWalker walker;
    walker.walk(&cl, tree);


    auto design_p = reader_sp->release();
    REQUIRE(design_p.operator bool());

    REQUIRE(design_p->num_sdf_commands() == 1);
    FAIL();
  }
}