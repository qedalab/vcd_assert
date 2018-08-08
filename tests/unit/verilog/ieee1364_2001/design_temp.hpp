#ifndef UNIT_VERILOG_TEST_DESIGN_TEMP_HPP
#define UNIT_VERILOG_TEST_DESIGN_TEMP_HPP

#include "parse/util/static_string.hpp"
#include "verilog/types/design.hpp"

using namespace Verilog;

namespace Verilog::Test::Verilog::IEEE1364_2001 {

constexpr auto module_content = R"####(
    // Start of clock tree: level 0
  basic_splitter clk_splitter_1 (clk, internal_clk_1, internal_clk_2);

  // Clock tree level 1
  basic_splitter clk_splitter_2 (internal_clk_1, internal_clk_3, internal_clk_4);
  basic_splitter clk_splitter_3 (internal_clk_2, internal_clk_5, internal_clk_6);

  // Clock tree level 2
  basic_splitter clk_splitter_4 (internal_clk_3, internal_clk_7, internal_clk_8);
  basic_splitter clk_splitter_5 (internal_clk_4, internal_clk_9, internal_clk_10);
  basic_splitter clk_splitter_6 (internal_clk_5, internal_clk_11, internal_clk_12);
  basic_splitter clk_splitter_7 (internal_clk_6, internal_clk_13, internal_clk_14);

  // Basic adder
  basic_dro dff_1 (cin, clk_1, internal_1);
  basic_dro dff_2 (internal_3, clk_7, sum);
  basic_dro dff_3 (internal_12, clk_6, internal_13);
  basic_splitter splitter_1 (internal_1, internal_2, internal_4);
  basic_splitter splitter_2 (a, internal_8, internal_10);
  basic_splitter splitter_3 (b, internal_9, internal_11);
  basic_splitter splitter_4 (internal_7, internal_5, internal_6);
  basic_xor xor_1 (internal_2, internal_5, clk_2, internal_3);
  basic_xor xor_2 (internal_8, internal_9, clk_3, internal_7);
  basic_and and_1 (internal_10, internal_11, clk_5, internal_12);
  basic_and and_2 (internal_4, internal_6, clk_4, internal_14);
  basic_or or_1 (internal_13, internal_14, clk_8, cout);)####";

constexpr auto test_module_keyword = "module";
constexpr auto test_module_identifier_example = "dro";
constexpr auto test_endmodule_keyword = "endmodule";

constexpr auto initial_block_example_1 = "initial begin basic_dro;\nend";
constexpr auto initial_block_example_2 =
    "initial \n\tbegin \n\t a = 1;\n\n\tend";
constexpr auto initial_block_example_3 =
    "initial \n\tbegin \n\t a = 1;\n\n\tend\n";
constexpr auto initial_block_example_4 =
    "initial begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";

constexpr auto initial_block_with_sdf_example_1 =
    R"####(initial
  begin
      $sdf_annotate("../../dro.sdf", tb_basic_dro);
      $dumpfile("tb_basic_dro.vcd");
      $dumpvars;

      #10 set = !set;
      #10 set = !set;
      #2.4 reset = !reset; //should cause timing violation
      #10 reset = !reset;
  end)####";

} // namespace Verilog::Test::Verilog::IEEE1364_2001

#endif // UNIT_VERILOG_TEST_DESIGN_TEMP_HPP
