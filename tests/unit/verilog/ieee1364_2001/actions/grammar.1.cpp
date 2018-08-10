#include "../design.hpp"

#include "verilog/ieee1364_2001/actions/grammar.hpp"
#include "verilog/ieee1364_2001/grammar/grammar_hacked.hpp"
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
#include <parse/util/filesystem.hpp>
#include <range/v3/view/indices.hpp>

#include <string>
#include <string_view>

using namespace Verilog;
using namespace Verilog::IEEE1364_2001::Actions;
using namespace Verilog::Test::Verilog::IEEE1364_2001;

namespace VerilogTest = Verilog::Test::Verilog::IEEE1364_2001;
namespace VerilogGrammar = Verilog::IEEE1364_2001::Grammar;
namespace fs = Parse::Util::fs;
namespace rsv = ranges::view;

TEST_CASE("Verilog.Actions.Design", "[Verilog][Events][Design]")
{
  DesignReader reader{};
  Verilog::Util::InputMap inputmap{};

  SECTION("FROM MEMORY")
  {
    SECTION("Single File")
    {
      SECTION("Single module")
      {
        SECTION("DRO Only")
        {

          for (auto &&pass : rsv::indices(2)) {

            tao::pegtl::memory_input<> input(dro_example, "dro_example");

            bool first_pass = pass == 0;
            REQUIRE(tao::pegtl::parse<
                    VerilogGrammar::grammar,
                    Parse::make_pegtl_template<GrammarAction>::type,
                    Parse::capture_control>(input, reader, inputmap,
                                            first_pass));
          }

          auto design_p = reader.release();
          REQUIRE(design_p.operator bool());
          // Test::catch_test_design(*design_p, dro_example);
        }

        // SECTION("TB_XOR Only")
        // {
        //   StringStringMapping wanted{"basic_xor", "DUT"};

        //   tao::pegtl::memory_input<> input(tb_xor_module, "tb_xor_module");

        //   REQUIRE(
        //       tao::pegtl::parse<VerilogGrammar::grammar,
        //                         Parse::make_pegtl_template<GrammarAction>::type,
        //                         Parse::capture_control>(input, reader,
        //                         inputmap,
        //                                                 1));

        //   REQUIRE_THROWS(
        //       tao::pegtl::parse<VerilogGrammar::grammar,
        //                         Parse::make_pegtl_template<GrammarAction>::type,
        //                         Parse::capture_control>(input, reader,
        //                         inputmap,
        //                                                 0));

        //   auto test = reader.release();
        //   REQUIRE(test.operator bool());

        //   REQUIRE(test->num_instances() == 0);
        // }
      }
      SECTION("Multi Module")
      {
        SECTION("Non-dependent modules : ")
        {
          std::vector<StringStringMapping> wanted{{"basic_dro", "DUT"},
                                                  {"basic_xor", "DUT"}};

          auto multi_module_input =
              fmt::format("{}\n\n{}\n\n{}\n\n{}", dro_example, xor_module,
                          tb_dro_example, tb_xor_module);

          for (auto &&pass : rsv::indices(2)) {

            tao::pegtl::memory_input<> input(multi_module_input,
                                             "multi_module_input");

            bool first_pass = pass == 0;
            REQUIRE(tao::pegtl::parse<
                    VerilogGrammar::grammar,
                    Parse::make_pegtl_template<GrammarAction>::type,
                    Parse::capture_control>(input, reader, inputmap,
                                            first_pass));
          }

          auto test = reader.release();
          REQUIRE(test.operator bool());

          REQUIRE(test->num_instances() == 2);
          REQUIRE(wanted[0].name == test->get_instance(0).identifier_);
          REQUIRE(wanted[1].name == test->get_instance(1).identifier_);
          REQUIRE(wanted[0].type == test->get_module(0).identifier);
          REQUIRE(wanted[1].type == test->get_module(1).identifier);
        }

        SECTION("Dependent modules : tb_dro + dro")
        {

          auto multi_module_input =
              fmt::format("{}\n\n{}", dro_example, tb_dro_example);

          for (auto &&pass : rsv::indices(2)) {

            tao::pegtl::memory_input<> input(multi_module_input,
                                             "multi_module_input");

            bool first_pass = pass == 0;
            REQUIRE(tao::pegtl::parse<
                    VerilogGrammar::grammar,
                    Parse::make_pegtl_template<GrammarAction>::type,
                    Parse::capture_control>(input, reader, inputmap,
                                            first_pass));
          }

          auto design_p = reader.release();
          REQUIRE(design_p.operator bool());

          VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
        }

        // SECTION("Dependent modules : tb_xor + xor")
        // {

        //   auto multi_module_input =
        //       fmt::format("{}\n\n{}", xor_module, tb_xor_module);

        //   for (auto &&pass : rsv::indices(2)) {

        //     tao::pegtl::memory_input<> input(multi_module_input,
        //                                      "multi_module_input");

        //     bool first_pass = pass == 0;
        //     REQUIRE(tao::pegtl::parse<
        //             VerilogGrammar::grammar,
        //             Parse::make_pegtl_template<GrammarAction>::type,
        //             Parse::capture_control>(input, reader, inputmap,
        //                                     first_pass));
        //   }

        //   auto design_p = reader.release();
        //   REQUIRE(design_p.operator bool());

        //   VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
        // }
      }
    }

    // SECTION("Multi input")
    // {
    //   SECTION("Multi Module")
    //   {
    //     SECTION("Unrelated modules : xor + dro")
    //     {
    //       //   std::vector<StringStringMapping> wanted{{"basic_xor",
    //       "DUT_1"},
    //       //                                           {"basic_xor",
    //       "DUT_2"}};

    //       //   // constexpr auto multi_module_input =
    //       //   // Parse::Util::static_string(tb_xor_module);
    //       //   std::string_view multi_module_input =
    //       //       fmt::format("{}\n\n{}", tb_xor_module, tb_dro_module);

    //       //   require_parse<__Grammar::grammar,
    //       //   GrammarAction>(multi_module_input,
    //       //                                                      reader);

    //       //   auto test = reader.release();
    //       //   REQUIRE(test.operator bool());
    //     }

    //     SECTION("Both tb_dro and dro")
    //     {
    //       std::string test_string{dro_example};
    //       const char *test_string_p = test_string.c_str();

    //       // inputmap.emplace("dro.v", // include_string
    //       //                  Verilog::Util::ParseInput{
    //       // Verilog::Util::InputTypeEnum::memory,
    //       //                      test_string_p});

    //       for (auto &&pass : rsv::indices(2)) {
    //         tao::pegtl::memory_input<> input_tb_dro(tb_dro_example,
    //                                                 "tb_dro_example");

    //         bool first_pass = pass == 0;

    //         REQUIRE(tao::pegtl::parse<
    //                 VerilogGrammar::grammar,
    //                 Parse::make_pegtl_template<GrammarAction>::type,
    //                 Parse::capture_control>(input_tb_dro, reader, inputmap,
    //                                         first_pass));
    //       }

    //       auto design_p = reader.release();
    //       REQUIRE(design_p.operator bool());
    //       // VerilogTest::catch_design(tb_dro_example_design_test,
    //       *design_p);
    //       // // Test::catch_test_design(*design_p, dro_example);
    //     }
    //   }
    // }
  }

  // SECTION("FROM FILE")
  // {
  //   SECTION("Single input")
  //   {
  //     SECTION("Single module")
  //     {
  //       SECTION("Only dro")
  //       {

  //         for (auto &&pass : rsv::indices(2)) {

  //           tao::pegtl::file_input<>
  //           input(dro_file_path_abs_.to_string_view());

  //           bool first_pass = pass == 0;

  //           REQUIRE(tao::pegtl::parse<
  //                   VerilogGrammar::grammar,
  //                   Parse::make_pegtl_template<GrammarAction>::type,
  //                   Parse::capture_control>(input, reader, inputmap,
  //                                           first_pass));
  //         }

  //         auto design_p = reader.release();
  //         REQUIRE(design_p.operator bool());
  //         // Test::catch_test_design(*design_p, dro_example);
  //         // VerilogTest::catch_design(tb_dro_example_design_test,
  //         *design_p);
  //       }

  //       SECTION("Only dro testbench ")
  //       {
  //         StringStringMapping wanted{"basic_dro", "DUT"};

  //         tao::pegtl::file_input<> input(
  //             tb_dro_file_path_abs_.to_string_view());

  //         REQUIRE(
  //             tao::pegtl::parse<VerilogGrammar::grammar,
  //                               Parse::make_pegtl_template<GrammarAction>::type,
  //                               Parse::capture_control>(input, reader,
  //                               inputmap,
  //                                                       1));
  //         input.restart();

  //         REQUIRE_THROWS( // WONT FIND 'basic_dro'
  //             tao::pegtl::parse<VerilogGrammar::grammar,
  //                               Parse::make_pegtl_template<GrammarAction>::type,
  //                               Parse::capture_control>(input, reader,
  //                               inputmap,
  //                                                       0));

  //         auto test = reader.release();
  //         REQUIRE(test.operator bool());

  //         REQUIRE(test->num_instances() == 1);
  //         // REQUIRE(wanted.type == test->get_instance(0).type_);
  //         REQUIRE(wanted.name == test->get_instance(0).identifier_);
  //       }
  //     }
  //   }

  //   SECTION("Multi input")
  //   {

  //     SECTION("Both tb_dro and dro")
  //     {

  //       tao::pegtl::file_input<> input_tb_dro(
  //           tb_dro_file_path_abs_.to_string_view());
  //       tao::pegtl::file_input<>
  //       input_dro(dro_file_path_abs_.to_string_view());

  //       REQUIRE(
  //           tao::pegtl::parse<VerilogGrammar::grammar,
  //                             Parse::make_pegtl_template<GrammarAction>::type,
  //                             Parse::capture_control>(input_dro, reader,
  //                                                     inputmap, 1));

  //       REQUIRE(
  //           tao::pegtl::parse<VerilogGrammar::grammar,
  //                             Parse::make_pegtl_template<GrammarAction>::type,
  //                             Parse::capture_control>(input_tb_dro, reader,
  //                                                     inputmap, 1));

  //       input_dro.restart();
  //       input_tb_dro.restart();

  //       REQUIRE(
  //           tao::pegtl::parse<VerilogGrammar::grammar,
  //                             Parse::make_pegtl_template<GrammarAction>::type,
  //                             Parse::capture_control>(input_dro, reader,
  //                                                     inputmap, 0));

  //       REQUIRE(
  //           tao::pegtl::parse<VerilogGrammar::grammar,
  //                             Parse::make_pegtl_template<GrammarAction>::type,
  //                             Parse::capture_control>(input_tb_dro, reader,
  //                                                     inputmap, 0));

  //       auto design_p = reader.release();
  //       REQUIRE(design_p.operator bool());

  //       VerilogTest::catch_design(tb_dro_example_design_test, *design_p);
  //     }
  //   }
  // }
  // void catch_test_design()
}

// Verilog::CatchDesign::test()
