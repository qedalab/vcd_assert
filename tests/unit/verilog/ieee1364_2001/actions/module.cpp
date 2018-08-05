#include "../design.hpp"

#include "verilog/ieee1364_2001/actions/commands.hpp"
#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/actions/module.hpp"
#include "verilog/ieee1364_2001/grammar/commands.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
#include "verilog/ieee1364_2001/grammar/module.hpp"

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
using namespace Verilog::IEEE1364_2001::Actions;
using namespace Verilog::Test::Verilog::IEEE1364_2001;

namespace VerilogGrammar = Verilog::IEEE1364_2001::Grammar;
namespace rsv = ranges::view;

TEST_CASE("Verilog.Actions.Module", "[Verilog][Events][Module]")
{
  using Parse::Test::require_parse;

  SECTION("module declaration")
  {
    SECTION("Single module, single file") {}
    SECTION("Multi module, single file") {}
    SECTION("Multi module, multi file") {}
  }

  SECTION("Module instantiation")
  {
    SECTION("Basic Functionality")
    {
      SECTION("module_instantiation + ModuleInstantiationAction")
      {
        StringStringMapping test{};
        StringStringMapping wanted{"basic_dro", "DUT"};

        require_parse<VerilogGrammar::module_instantiation,
                      ModuleInstantiationAction>(module_instantiation_example,
                                                 test);

        REQUIRE(wanted.type == test.type);
        REQUIRE(wanted.name == test.name);
      }

      SECTION("module_description + ModuleDescriptionAction")
      {
        SECTION("tb dro example")
        {
          ModuleEvent test{};
          StringStringMapping wanted{"basic_dro", "DUT"};

          require_parse<VerilogGrammar::module_description,
                        ModuleDescriptionAction>(tb_dro_module, test);

          REQUIRE(test.instances.size() == 1);
          REQUIRE(wanted.type == test.instances[0].type);
          REQUIRE(wanted.name == test.instances[0].name);
        }

        SECTION("tb xor example")
        {
          ModuleEvent test{};
          StringStringMapping wanted{"basic_xor", "DUT"};

          require_parse<VerilogGrammar::module_description,
                        ModuleDescriptionAction>(tb_xor_module, test);

          REQUIRE(test.instances.size() == 1);
          REQUIRE(wanted.type == test.instances[0].type);
          REQUIRE(wanted.name == test.instances[0].name);
        }

        // SECTION("both tb_xor and tb_dro examples")
        // {
        //   std::vector<ModuleEvent> test{};
        //   std::vector<StringStringMapping> wanted{{"basic_dro", "DUT"},
        //                                           {"basic_xor", "DUT"}};

        //   tao::pegtl::memory_input<> tb_dro_input(tb_dro_example,
        //                                           "tb_dro_example");
        //   tao::pegtl::memory_input<> tb_xor_input(tb_xor_module,
        //                                           "tb_xor_module");

        //   REQUIRE(tao::pegtl::parse<
        //           VerilogGrammar::grammar,
        //           Parse::make_pegtl_template<ModuleDescriptionAction>::type,
        //           Parse::capture_control>(tb_dro_input, test));

        //   // REQUIRE(tao::pegtl::parse<
        //   //         VerilogGrammar::grammar,
        //   // Parse::make_pegtl_template<ModuleDescriptionAction>::type,
        //   //         Parse::capture_control>(tb_xor_input, test));

        //   // REQUIRE(test.instances.size() == 1);
        //   // REQUIRE(wanted.type == test[0].instances[0].type);
        //   // REQUIRE(wanted.name == test[0].instances[0].name);
        //   // REQUIRE(wanted.type == test.instances[0].type);
        //   // REQUIRE(wanted.name == test.instances[0].name);
        // }
      }
    }
  }

  SECTION("sdf annotation action")
  {

    Command test_command{};
    auto wanted = sdf_annotation_command;

    require_parse<VerilogGrammar::sdf_annotate_task, SDFAnnotateTaskAction>(
        sdf_annotate_example, test_command);
    auto test = std::get<SDFAnnotateCommand>(test_command);

    REQUIRE(wanted.sdf_file == test.sdf_file);
    REQUIRE(wanted.name_of_instance == test.name_of_instance);
  }
  SECTION("sdf annotation from initial_construct action")
  {
    std::vector<Command> test_commands{};
    auto wanted = sdf_annotation_command;
    CAPTURE(initial_construct_with_sdf_example_1);
    require_parse<VerilogGrammar::initial_construct, CommandArrayAction>(
        initial_construct_with_sdf_example_1, test_commands);

    REQUIRE(test_commands.size() == 1);

    auto test = std::get<SDFAnnotateCommand>(test_commands[0]);
    REQUIRE(wanted.sdf_file == test.sdf_file);
    REQUIRE(wanted.name_of_instance == test.name_of_instance);
  }

  SECTION("sdf annotation from module declaration action")
  {

    ModuleEvent test{};
    ModuleEvent wanted{"basic_dro", {}, {{sdf_annotation_command}}};

    require_parse<VerilogGrammar::module_declaration, ModuleDeclarationAction>(
        basic_annotation_example, test);

    REQUIRE(wanted.module_identifier == test.module_identifier);
    // REQUIRE(wanted.instances.size(),test.instances.size());

    for (auto &&[pair1, pair2] : rsv::zip(wanted.instances, test.instances)) {
      auto &&[str1, str2] = pair1;
      auto &&[str3, str4] = pair2;
      REQUIRE(str1 == str3);
      REQUIRE(str2 == str4);
    }
  }
}