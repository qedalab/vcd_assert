#include "../../test/match_exactl_w_listeners.hpp"
#include "../../test/test_design.hpp"

#include "verilog/ieee1800_2012/actions/netlist_listener.hpp"

#include "verilog/util/parse_input.hpp"

#include <catch2/catch.hpp>
#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>

using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;

TEST_CASE("Verilog.Actions.NetlistListener",
          "[Verilog][Actions][NetlistListener]")
{

  // SECTION("dro example")
  // {
  //   INFO("Setup test input");
  //   std::vector<Verilog::Util::ParseInput> inputs{
  //       // clang-format off
  //     {
  //       "basic_dro_input", 
  //       Verilog::Util::InputTypeEnum::memory,
  //       dro_example
  //     }
  //       // clang-format on
  //   };

  //   INFO("Setup test criteria");
  //   auto wanted_reader_sp = std::make_shared<DesignReader>();
  //   wanted_reader_sp->module("basic_dro", "basic_dro_input");

  //   INFO("Setup test reader");
  //   auto test_reader_sp = std::make_shared<DesignReader>();
  //   test_reader_sp->module("basic_dro", "basic_dro_input");

  //   std::shared_ptr<Design> wanted_design =
  //       std::move(wanted_reader_sp->release());

  //   REQUIRE(wanted_design.operator bool());

  //   INFO("Parse and match");
  //   match_exactly_w_listeners<NetlistListener>(wanted_design, test_reader_sp,
  //                                              inputs);
  // }

  SECTION("dro + tb_dro example")
  {
    INFO("Setup test input");
    std::vector<Verilog::Util::ParseInput> inputs{
        // clang-format off
      {
        "basic_dro_input", 
        Verilog::Util::InputTypeEnum::memory,
        dro_example
      },
      {
        "tb_basic_dro_input", 
        Verilog::Util::InputTypeEnum::memory,
        tb_dro_example 
      }
        // clang-format on
    };

    INFO("Setup test data");
    auto wanted_reader_sp = std::make_shared<DesignReader>();
    wanted_reader_sp->module("basic_dro", "basic_dro_input");
    wanted_reader_sp->next_module();
    wanted_reader_sp->module("tb_basic_dro", "tb_basic_dro_input");
    wanted_reader_sp->instance(NetType::module, "DUT", "basic_dro");
    wanted_reader_sp->next_module();

    std::shared_ptr<Design> wanted_design =
        std::move(wanted_reader_sp->release());
    REQUIRE(wanted_design.operator bool());


    // set module name so that command is created correctly
    auto test_reader_sp = std::make_shared<DesignReader>();
    test_reader_sp->module("basic_dro", "basic_dro_input");
    test_reader_sp->module("tb_basic_dro", "tb_basic_dro_input");

 
    INFO("Parse and match");
    match_exactly_w_listeners<NetlistListener>(wanted_design, test_reader_sp,
                                               inputs, true);
  }
}