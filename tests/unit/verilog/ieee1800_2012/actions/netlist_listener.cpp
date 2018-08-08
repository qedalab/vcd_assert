
#include "../../test.hpp"
// #include "../design_temp.hpp"

#include "verilog/ieee1800_2012/actions/netlist_listener.hpp"

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

TEST_CASE("Verilog.Actions.NetlistListener",
          "[Verilog][Actions][NetlistListener]")
{

  SECTION("sdf annotation action")
  {
    // CAPTURE(dro_example);

    ANTLRInputStream input(dro_example);
    SV2012Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SV2012Parser parser(&tokens);
        
    auto *tree = parser.source_text();
    std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
    FAIL();
  }



//   // SECTION("sdf annotation action")
//   // {

//   //   Command test_command{};
//   //   auto wanted = sdf_annotation_command;

//   //   require_parse<__Grammar::sdf_annotate_task,
//   //   Actions::SDFAnnotateTaskAction>(
//   //       sdf_annotate_example, test_command);
//   //   auto test = std::get<SDFAnnotateCommand>(test_command);

//   //   REQUIRE(wanted.sdf_file == test.sdf_file);
//   //   REQUIRE(wanted.name_of_instance == test.name_of_instance);
//   // }
//   // SECTION("sdf annotation from initial_block action")
//   // {
//   //   std::vector<Command> test_commands{};
//   //   auto wanted = sdf_annotation_command;
//   //   CAPTURE(initial_block_with_sdf_example_1);
//   //   require_parse<__Grammar::initial_block, Actions::CommandArrayAction>(
//   //       initial_block_with_sdf_example_1, test_commands);

//   //   REQUIRE(test_commands.size() == 1);

//   //   auto test = std::get<SDFAnnotateCommand>(test_commands[0]);
//   //   REQUIRE(wanted.sdf_file == test.sdf_file);
//   //   REQUIRE(wanted.name_of_instance == test.name_of_instance);
//   // }

//   // SECTION("sdf annotation from module declaration action")
//   // {

//   //   using IEEE1364_2001::Actions::ModuleEvent;
//   //   ModuleEvent test{};
//   //   ModuleEvent wanted{"basic_dro", {}, {{sdf_annotation_command}}};

//   //   require_parse<__Grammar::_module_declaration_,
//   // Actions::ModuleDeclarationAction>(basic_annotation_example,
//   //                                                   test);

//   //   REQUIRE(wanted.module_identifier == test.module_identifier);
//   //   // REQUIRE(wanted.instances.size(),test.instances.size());

//   //   for (auto &&[pair1, pair2] :
//   //        ranges::view::zip(wanted.instances, test.instances)) {
//   //     auto &&[str1, str2] = pair1;
//   //     auto &&[str3, str4] = pair2;
//   //     REQUIRE(str1 == str3);
//   //     REQUIRE(str2 == str4);
//   //   }

//   //   // REQUIRE(test_commands.size() == 1);

//   //   // auto test = std::get<SDFAnnotateCommand>(test_commands[0]);
//   //   // REQUIRE(wanted.sdf_file == test.sdf_file);
//   //   // REQUIRE(wanted.name_of_instance == test.name_of_instance);
//   // }

//   // SECTION("module instantiation from module declaration action")
//   // {

//   //   using IEEE1364_2001::Actions::StringStringMapping;
//   //   StringStringMapping test{};
//   //   StringStringMapping wanted{"basic_dro", "DUT"};

//   //   require_parse<__Grammar::module_instantiation,
//   //                 Actions::ModuleInstantiationAction>(
//   //       module_instantiation_example, test);

//   //   REQUIRE(wanted.type == test.type);
//   //   REQUIRE(wanted.name == test.name);
//   // }

}