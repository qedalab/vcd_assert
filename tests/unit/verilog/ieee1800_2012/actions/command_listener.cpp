#include "../../test/match_exactl_w_listeners.hpp"
#include "../../test/test_design.hpp"

#include "verilog/ieee1800_2012/actions/command_listener.hpp"

#include "verilog/util/parse_input.hpp"
#include "verilog/types/commands.hpp"

#include <catch2/catch.hpp>
#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>

using namespace Verilog::Test;
using namespace Verilog;

TEST_CASE("Verilog.Actions.CommandListener",
          "[Verilog][Actions][CommandListener]")
{

  SECTION("sdf annotation full")
  {
    // DesignView full_example {
    //   // clang-format off
    //   { //vector of modules
    //     { //module (INCLUDED BEFORE MAIN MODULE)
    //       "basic_dro",      // identifier
    //       dro_file_path_abs_.to_string(), // path
    //       {}       // instances lookup
    //     },
    //     { //module
    //       "tb_basic_dro",   // identifier
    //       tb_dro_file_path_abs_.to_string(), // path
    //       {// instances lookup
    //         {"DUT",0}
    //       }
    //     }
    //   },
    //   { //vector of instances
    //     {
    //       NetType::module,  //type_
    //       "DUT",            //identifier_    //what to name root net ?
    //       0 // index of dro module in module list
    //     }
    //   },
    //   { //module lookup
    //     {"basic_dro", 0},
    //     {"tb_basic_dro", 1}
    //   },
    //   { //sdf_commands total
    //     { // sdf_commands for tb_dro module
    //     }
    //   },
    //   { //sdf_commands_lookup_
    //   }
    // // clang-format on
    // };

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

    // SECTION("tb dro example")
    // {
    //   INFO("Setup test input");
    //     std::vector<Verilog::Util::ParseInput> inputs{
    //     // clang-format off
    //       {
    //         "dummy", 
    //         Verilog::Util::InputTypeEnum::memory,
    //         tb_dro_example
    //       }
    //     // clang-format on
    //   };

    //   INFO("Setup test data");
    //   auto wanted_reader_sp = std::make_shared<DesignReader>();
    //   auto test_reader_sp = std::make_shared<DesignReader>();

    //   wanted_reader_sp->module("tb_basic_dro", "dummy");
    //   wanted_reader_sp->next_module();
    //   wanted_reader_sp->command(SDFAnnotateCommand{"../../dro.sdf", "tb_basic_dro"});

    //   // set module name so that command is created correctly
    //   test_reader_sp->module("tb_basic_dro", "dummy");

    //   std::shared_ptr<Design> wanted_design =
    //       std::move(wanted_reader_sp->release());

    //   INFO("Parse and match");
    //   REQUIRE(wanted_design.operator bool());
    //   match_exactly_w_listeners<CommandListener>(wanted_design,
    //                                              test_reader_sp, inputs);
    // }
  }
}