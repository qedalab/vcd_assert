
#ifndef UNIT_VERILOG_TEST_MATCH_EXACTLY_ANTLR_HPP
#define UNIT_VERILOG_TEST_MATCH_EXACTLY_ANTLR_HPP

#include "./parse_w_listener.hpp"
#include "./test_design.hpp"

#include "verilog/types/design.hpp"
#include "verilog/types/design_reader.hpp"

#include "verilog/util/parse_input.hpp"

#include "parse/util/static_string.hpp"

#include <catch2/catch.hpp>
#include <string>
#include <string_view>

#include <range/v3/view/indices.hpp>
#include <range/v3/view/zip.hpp>


using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;
using namespace antlr4::tree;

namespace rsv = ranges::view;

namespace Verilog::Test {
using namespace Verilog;
template <typename TListener>
void match_exactly_w_listeners(std::shared_ptr<Design> wanted_design_sp,
                               std::shared_ptr<DesignReader> test_reader_sp,
                               std::vector<Verilog::Util::ParseInput> parse_input_v,
                               bool debug_output = false)
{
  using namespace Verilog::Util;

  INFO(fmt::format("Input vec size : ({})", parse_input_v.size()));

  // Find file containing top module
  auto temp_test_reader_sp = std::make_shared<DesignReader>(*test_reader_sp);
  auto temp_design = temp_test_reader_sp->release();
  
  CAPTURE(temp_design->num_modules());
  CAPTURE(temp_design->num_sdf_commands());
  CAPTURE(temp_design->num_instances());

  for (auto && [i,parse_input] : rsv::zip(rsv::indices, parse_input_v)) {

    Parse::Util::debug_print("Parse Input : ({}:{})\n", i, parse_input_v.size());

    if (parse_input.type == Util::InputTypeEnum::memory) {   

      auto start = std::get<const char *>(parse_input.value);
      parse_w_listener<TListener>(test_reader_sp,
                                  std::string(start),
                                  parse_input.name,
                                  debug_output);
    } else {
      //  parse_w_listener<TListener>(test_reader_sp, parse_input,
      //  parse_source);
    }
  }

  std::shared_ptr<Design> test_design = test_reader_sp->release();
  
  REQUIRE(test_design.operator bool());

  REQUIRE(wanted_design_sp->num_modules() == test_design->num_modules());
  REQUIRE(test_design->num_sdf_commands() ==
          wanted_design_sp->num_sdf_commands());
  REQUIRE(wanted_design_sp->num_instances() == test_design->num_instances());
  catch_design(*wanted_design_sp, *test_design);
  // FAIL();
}

} // namespace Verilog::Test

#endif // UNIT_VERILOG_TEST_MATCH_EXACTLY_ANTLR_HPP
