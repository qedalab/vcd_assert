#include "../design.hpp"

#include "verilog/ieee1364_2001/grammar/commands.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
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

#include <string>
#include <string_view>

using namespace Verilog::Test::Verilog::IEEE1364_2001;
using namespace Verilog::IEEE1364_2001;

namespace __Grammar = Verilog::IEEE1364_2001::Grammar;
using namespace Verilog;

inline auto sdf_annotation_command = SDFAnnotateCommand{"../../dro.sdf", "tb_dro", {}, {}, {}, {}, {}};

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
  SECTION("sdf annotation from module declaration action")
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

    using IEEE1364_2001::Actions::ModuleEvent;
    ModuleEvent test{};
    ModuleEvent wanted{"dro", {}, {sdf_annotation_command}};

    require_parse<__Grammar::_module_declaration_,
                  Actions::ModuleDeclarationAction>(
        initial_block_with_sdf_example_1, test);
  }
}