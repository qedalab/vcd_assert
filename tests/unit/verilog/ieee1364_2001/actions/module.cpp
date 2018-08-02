#include "../design.hpp"

#include "verilog/ieee1364_2001/grammar/commands.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
#include "verilog/ieee1364_2001/grammar/module.hpp"
#include "verilog/ieee1364_2001/actions/commands.hpp"
#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/actions/module.hpp"

#include "verilog/types/commands.hpp"

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

#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>

using namespace Verilog;
using namespace Verilog::IEEE1364_2001;
using namespace Verilog::Test::Verilog::IEEE1364_2001;

namespace __Grammar = Verilog::IEEE1364_2001::Grammar;
namespace rsv = ranges::view;


TEST_CASE("Verilog.Actions.Module", "[Verilog][Events][Module]")
{
  using Parse::Test::require_parse;

  SECTION("sdf annotation action")
  {

    Command test_command{};
    auto wanted = sdf_annotation_command;

    require_parse<__Grammar::sdf_annotate_task, Actions::SDFAnnotateTaskAction>(
        sdf_annotate_example, test_command);
    auto test = std::get<SDFAnnotateCommand>(test_command);

    REQUIRE(wanted.sdf_file == test.sdf_file);
    REQUIRE(wanted.name_of_instance == test.name_of_instance);
  }
  SECTION("sdf annotation from initial_block action")
  {
    std::vector<Command> test_commands{};
    auto wanted = sdf_annotation_command;
    CAPTURE(initial_block_with_sdf_example_1);
    require_parse<__Grammar::initial_block, Actions::CommandArrayAction>(
        initial_block_with_sdf_example_1, test_commands);

    REQUIRE(test_commands.size() == 1);

    auto test = std::get<SDFAnnotateCommand>(test_commands[0]);
    REQUIRE(wanted.sdf_file == test.sdf_file);
    REQUIRE(wanted.name_of_instance == test.name_of_instance);
  }

  SECTION("sdf annotation from module declaration action")
  {

    Actions::ModuleEvent test{};
    Actions::ModuleEvent wanted{"basic_dro", {}, {{sdf_annotation_command}}};

    require_parse<__Grammar::_module_declaration_,
                  Actions::ModuleDeclarationAction>(
        basic_annotation_example, test);

    REQUIRE(wanted.module_identifier == test.module_identifier);
    // REQUIRE(wanted.instances.size(),test.instances.size());

    for(auto&& [pair1,pair2] : rsv::zip(wanted.instances,test.instances)){
      auto &&[str1,str2] = pair1;
      auto &&[str3,str4] = pair2;
      REQUIRE(str1== str3);
      REQUIRE(str2 == str4);
    }
  }

  SECTION("module instantiation")
  {

    Actions::StringStringMapping test{};
    Actions::StringStringMapping wanted{"basic_dro", "DUT"};

    require_parse<__Grammar::module_instantiation,
                  Actions::ModuleInstantiationAction>(
        module_instantiation_example, test);

    REQUIRE(wanted.type == test.type);
    REQUIRE(wanted.name == test.name);
  }

  SECTION("module instantiation from module description")
  {

    Actions::ModuleEvent test{};

    SECTION("tb dro example"){ 
      Actions::StringStringMapping wanted{"basic_dro", "DUT"};
      
      require_parse<__Grammar::_module_description_,
                    Actions::ModuleDescriptionAction>(
          tb_dro_module, test);

      REQUIRE(test.instances.size() == 1);
      REQUIRE(wanted.type == test.instances[0].type);
      REQUIRE(wanted.name == test.instances[0].name);
    }

    SECTION("tb xor example"){ 
      Actions::StringStringMapping wanted{"basic_xor", "DUT"};

      require_parse<__Grammar::_module_description_,
                    Actions::ModuleDescriptionAction>(
          tb_xor_module, test);

      REQUIRE(test.instances.size() == 1);
      REQUIRE(wanted.type == test.instances[0].type);
      REQUIRE(wanted.name == test.instances[0].name);
    }

    SECTION("multi instantiation example"){ 
      Actions::StringStringMapping wanted{"basic_xor", "DUT_1"};
      Actions::StringStringMapping wanted{"basic_xor", "DUT_2"};

      require_parse<__Grammar::_module_description_,
                    Actions::ModuleDescriptionAction>(
          tb_xor_module, test);

      REQUIRE(test.instances.size() == 2);
      REQUIRE(wanted.type == test.instances[0].type);
      REQUIRE(wanted.name == test.instances[0].name);
    }

  }

  SECTION("module declaration from multi module file")
  {

  }

SECTION("multi module instantiation from module description action")
  {

  }

  // SECTION("module instantiation from module description action")
  // {

  //   DesignReader reader{};
  //   Instance unused;
    
  //   SECTION("dro example"){ 
  //     Actions::StringStringMapping wanted{"basic_xor", "DUT"};
  //     require_parse<__Grammar::_module_description_,
  //                   Actions::GrammarAction>(
  //         tb_dro_example, reader);
      
  //     auto test = reader.release();
  //     REQUIRE(test.operator bool());

  //     REQUIRE(test->num_instances() == 1);
  //     // REQUIRE(wanted.type == test->get_instance(0).type_);
  //     REQUIRE(wanted.name == test->get_instance(0).identifier_);
  //   }

  //   SECTION("xor example"){ 
  //     Actions::StringStringMapping wanted{"basic_dro", "DUT"};
  //     require_parse<__Grammar::_module_description_,
  //                   Actions::GrammarAction>(
  //         xor_verilog_example, reader);
      
  //     auto test = reader.release();
  //     REQUIRE(test.operator bool());

  //     REQUIRE(test->num_instances() == 1);
  //     // REQUIRE(wanted.type == test->get_instance(0).identifier_);
  //     REQUIRE(wanted.name == test->get_instance(0).identifier_);
  //   }
  // }



}