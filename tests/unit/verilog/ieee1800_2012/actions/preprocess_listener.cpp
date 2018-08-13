#include "../../test/match_exactl_w_listeners.hpp"
#include "../../test/test_design.hpp"

#include "verilog/ieee1800_2012/actions/preprocess_listener.hpp"

#include "verilog/util/parse_input.hpp"

#include <catch2/catch.hpp>
#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>

TEST_CASE("Verilog.Actions.PreprocesListener",
          "[Verilog][Actions][PreprocesListener]")
{
  SECTION("single module, single input") // dro and tb_dro examples
  {
    SECTION("dro example")
    {
      INFO("Setup input list");
      std::vector<Verilog::Util::ParseInput> inputs{
          // clang-format off
        {
          "basic_dro_input", 
          Verilog::Util::InputTypeEnum::memory,
          dro_example
        }
          // clang-format on
      };

      INFO("Setup test data");
      auto wanted_reader_sp = std::make_shared<DesignReader>();
      wanted_reader_sp->module("basic_dro", "basic_dro_input");

      std::shared_ptr<Design> wanted_design =
          std::move(wanted_reader_sp->release());
      REQUIRE(wanted_design.operator bool());

      INFO("Parse and match");
      auto test_reader_sp = std::make_shared<DesignReader>();
      match_exactly_w_listeners<PreprocessListener>(
          wanted_design, test_reader_sp, inputs);

    }

    SECTION("tb dro example")
    {
      INFO("Setup input list");
      std::vector<Verilog::Util::ParseInput> inputs{
          // clang-format off
        {
          "tb_basic_dro_input", 
          Verilog::Util::InputTypeEnum::memory,
          tb_dro_example
        }
          // clang-format on
      };

      INFO("Setup pass criteria");
      auto wanted_reader_sp = std::make_shared<DesignReader>();
      wanted_reader_sp->module("tb_basic_dro", "tb_basic_dro_input");

      std::shared_ptr<Design> wanted_design =
          std::move(wanted_reader_sp->release());

      REQUIRE(wanted_design.operator bool());

      INFO("Setup test data");
      auto test_reader_sp = std::make_shared<DesignReader>();

      INFO("Parse and match");
      match_exactly_w_listeners<PreprocessListener>(wanted_design,
                                                    test_reader_sp, inputs);
    }
  }

  SECTION("multi module, single input")
  {
    
    SECTION("multi_module_example_1")
    {
      INFO("Setup input list");
      std::vector<Verilog::Util::ParseInput> inputs{
          // clang-format off
        {
          "multi_module_example_1", 
          Verilog::Util::InputTypeEnum::memory,
          multi_module_example_1
        }
          // clang-format on
      };

      INFO("Setup test data");
      auto wanted_reader_sp = std::make_shared<DesignReader>();
      wanted_reader_sp->module("tb_basic_dro_1", "multi_module_example_1");
      wanted_reader_sp->module("basic_dro_2", "multi_module_example_1");

      std::shared_ptr<Design> wanted_design =
          std::move(wanted_reader_sp->release());

      REQUIRE(wanted_design.operator bool());

      auto test_reader_sp = std::make_shared<DesignReader>();

      INFO("Parse and match");
      match_exactly_w_listeners<PreprocessListener>(wanted_design,
                                                    test_reader_sp, inputs);
    }
    
    SECTION("multi_module_example_2")
    {
      INFO("Setup input list");
      std::vector<Verilog::Util::ParseInput> inputs{
          // clang-format off
        {
          "multi_module_example_2", 
          Verilog::Util::InputTypeEnum::memory,
          multi_module_example_2
        }
          // clang-format on
      };

      INFO("Setup test data");
      auto wanted_reader_sp = std::make_shared<DesignReader>();
      wanted_reader_sp->module("basic_dro_1", "multi_module_example_2");
      wanted_reader_sp->module("basic_dro_2", "multi_module_example_2");

      std::shared_ptr<Design> wanted_design =
          std::move(wanted_reader_sp->release());

      REQUIRE(wanted_design.operator bool());

      auto test_reader_sp = std::make_shared<DesignReader>();

      INFO("Parse and match");
      match_exactly_w_listeners<PreprocessListener>(wanted_design,
                                                    test_reader_sp, inputs);
    }
    
    SECTION("multi_module_example_3")
    {
      INFO("Setup input list");
      std::vector<Verilog::Util::ParseInput> inputs{
          // clang-format off
        {
          "multi_module_example_3", 
          Verilog::Util::InputTypeEnum::memory,
          multi_module_example_3
        }
          // clang-format on
      };

      INFO("Setup test data");
      auto wanted_reader_sp = std::make_shared<DesignReader>();
      wanted_reader_sp->module("basic_dro_1", "multi_module_example_3");
      wanted_reader_sp->module("basic_dro_2", "multi_module_example_3");

      std::shared_ptr<Design> wanted_design =
          std::move(wanted_reader_sp->release());

      REQUIRE(wanted_design.operator bool());

      auto test_reader_sp = std::make_shared<DesignReader>();

      INFO("Parse and match");
      match_exactly_w_listeners<PreprocessListener>(wanted_design,
                                                    test_reader_sp, inputs);
    }
  }

  SECTION("multi module, multi input")
  {
    SECTION("ex 1 + ex 2") {}
    SECTION("ex 2 + ex 3") {}
    SECTION("ex 3 + ex 1") {}
    SECTION("ex 1 + ex 2 + ex 3") {}
  }
}