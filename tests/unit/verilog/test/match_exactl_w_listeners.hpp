
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

using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;
using namespace antlr4::tree;

namespace Verilog::Test {
using namespace Verilog;
template <typename TListener>
void match_exactly_w_listeners(std::shared_ptr<Design> wanted_design_sp,
                               std::shared_ptr<DesignReader> test_reader_sp,
                               std::vector<Verilog::Util::ParseInput> parse_input_v,
                               bool debug_output = false)
{
  using namespace Verilog::Util;
  
  for (auto && parse_input : parse_input_v) {

    INFO(fmt::format("Parse input with listener : ({})", parse_input.name));

    if (parse_input.type == Util::InputTypeEnum::memory) {   

      auto start = std::get<const char *>(parse_input.value);
      parse_w_listener<TListener>(test_reader_sp,
                                  std::string(start),
                                  parse_input.name);
    } else {
      //  parse_w_listener<TListener>(test_reader_sp, parse_input,
      //  parse_source);
    }
  }

  auto test_design = test_reader_sp->release();
  REQUIRE(test_design.operator bool());

  REQUIRE(test_design->num_modules() == wanted_design_sp->num_modules());
  REQUIRE(test_design->num_sdf_commands() ==
          wanted_design_sp->num_sdf_commands());
  REQUIRE(test_design->num_instances() == wanted_design_sp->num_instances());
  catch_design(*wanted_design_sp, *test_design);
  // FAIL();
}

} // namespace Verilog::Test

#endif // UNIT_VERILOG_TEST_MATCH_EXACTLY_ANTLR_HPP
