#ifndef UNIT_VERILOG_TEST_DESIGN_HPP
#define UNIT_VERILOG_TEST_DESIGN_HPP

#include "parse/util/static_string.hpp"
#include "verilog/types/design.hpp"

using namespace Verilog;

namespace Verilog::Test::Verilog::IEEE1364_2001 {

inline auto sdf_annotation_command =
    SDFAnnotateCommand{"../../dro.sdf", "tb_basic_dro", {}, {}, {}, {}, {}};

// imported from CMAKE ENVIRONMENT
constexpr auto project_source_dir =
    Parse::Util::static_string(PROJECT_SOURCE_DIR);
constexpr auto input_path_ =
    "" + project_source_dir + "/examples/basic_dro_success/";

constexpr auto dro_file_path_abs_ = input_path_ + "dro.v";
constexpr auto tb_dro_file_path_abs_ = input_path_ + "tb_dro.v";

// clang-format off
inline DesignView dro_example_design_test {
  { //vector of module
    { //module
      "basic_dro",   // identifier
      dro_file_path_abs_.to_string(), // path
      {}       // instances lookup
    }
  },
  {}, //vector of instances
  { //module lookup
    {"basic_dro", 0}
  },
  {}, //sdf_commands
  {}  //sdf_commands_lookup_
};
// clang-format on

// clang-format off
inline DesignView tb_dro_example_design_test {
  { //vector of modules
    { //module (INCLUDED BEFORE MAIN MODULE)
      "basic_dro",   // identifier
      dro_file_path_abs_.to_string(), // path      
      {}       // instances lookup
    },
    { //module
      "tb_basic_dro",   // identifier
      tb_dro_file_path_abs_.to_string(), // path
      {// instances lookup
        {"DUT",0}
      }   
    }
  },
  { //vector of instances
    {
      NetType::module, //type_
      "DUT",            //identifier_    //what to name root net ?
      0 // index of dro module in module list
    }
  },
  { //module lookup
    {"basic_dro", 0},
    {"tb_basic_dro", 1}
  },
  { //sdf_commands total
    { // sdf_commands for tb_dro module
      SDFAnnotateCommand{
        "../../dro.sdf", "tb_basic_dro", {}, {}, {}, {}, {}
      }
    }
  }, 
  { //sdf_commands_lookup_
    {0,0} // chooses tb_dro's sdf annotation command vector
  }  
};
// clang-format on

// clang-format off
constexpr auto include_statement = "include \"to_be_included\"";
constexpr auto include_statement_no_qstring = "include to_be_included";
constexpr auto compiler_directive = "`include \"to_be_included\"";

constexpr auto module_keyword = "module";
constexpr auto module_declaration_1 = "module basic_dro; endmodule";
constexpr auto module_declaration_2 = "module basic_dro(); endmodule";
constexpr auto module_declaration_3 = "module basic_dro (); endmodule";
constexpr auto module_declaration_4 = "module basic_dro (set, reset, out);endmodule";
constexpr auto module_declaration_5 = "module  basic_dro (set, reset, out);endmodule";
constexpr auto module_declaration_6 = "module basic_dro  (set, reset, out);\nendmodule";
constexpr auto module_declaration_7 = "module basic_dro (set, reset, out);endmodule";

constexpr auto module_example_1 = "\nmodule basic_dro;\nendmodule";

constexpr auto module_example_2 = "\nmodule basic_dro (set, reset, out);\nendmodule\n";


constexpr auto integer_delay = "#10";
constexpr auto real_delay = "#2.4";
constexpr auto bracketed_delay = "#(2.4)";

constexpr auto non_block_assign_0 = "set = !set;";
constexpr auto non_block_assign_1 = "#2.4 reset = !reset";
constexpr auto non_block_assign_2 = "#10 reset = !reset;";


constexpr auto sdf_annotate_example = R"####($sdf_annotate("../../dro.sdf", tb_basic_dro);)####";
constexpr auto module_instantiation_example = R"####(basic_dro DUT (set, reset, out);)####";

constexpr auto begin_end_example_1 = "begin basic_dro;\nend";
constexpr auto begin_end_example_2 = "begin \n\t a = 1;\n\n\tend";
constexpr auto begin_end_example_3 = "begin \n\t a = 1;\n\n\tend";
constexpr auto begin_end_example_4 = "begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";
constexpr auto begin_end_example_5 = "begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";

constexpr auto initial_construct_example_1 = "initial begin basic_dro;\nend";
constexpr auto initial_construct_example_2 = "initial \n\tbegin \n\t a = 1;\n\n\tend";
constexpr auto initial_construct_example_3 = "initial \n\tbegin \n\t a = 1;\n\n\tend\n";
constexpr auto initial_construct_example_4 = "initial begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";

// clang-format on

constexpr auto initial_construct_with_sdf_example_1 =
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

constexpr auto basic_annotation_example = R"####(module basic_dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_basic_dro);
         $dumpfile("tb_basic_dro.vcd");
         $dumpvars;

         #10 set = !set;
      end

endmodule
)####";

constexpr auto dro_example = R"####(
// ---------------------------------------------------------------------------
// Automatically extracted verilog file, created with TimEx v1.01.00
// Timing description and structural design for IARPA-BAA-14-03.
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// (c) 2016-2017 Stellenbosch University
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module basic_dro (set, reset, out);

input set, reset;
output out;
reg out_state;
integer state_state;
wire state, not_state;

assign state = state_state;
assign not_state = !state_state;

assign out = out_state;

specify
    specparam delay_state1_reset_out = 5.5;
    specparam ct_state0_set_reset    = 2.5;
    specparam ct_state0_reset_set    = 2.5;
    specparam ct_state1_set_reset    = 2.5;

    if (state == 1) (reset => out) = delay_state1_reset_out;
   
    $hold( posedge set &&& not_state , reset  , ct_state0_set_reset);
    $hold( negedge set &&& not_state , reset  , ct_state0_set_reset);

    $hold( posedge set &&& state , reset , ct_state1_set_reset);
    $hold( negedge set &&& state , reset , ct_state1_set_reset);

    $hold( posedge reset &&& not_state , set , ct_state0_reset_set);
    $hold( negedge reset &&& not_state , set , ct_state0_reset_set);

endspecify

// initial begin
//     state_state = 0;
//     out_state = 0;
// end

always @(posedge set or negedge set)
begin if ($time>2)
    case (state)
        0: begin 
            state_state = 1;
        end
    endcase
end

always @(posedge reset or negedge reset)
begin if ($time>2)
    case (state)
        1: begin 
            out_state = !out_state;
        end
    endcase
end

endmodule

)####";

constexpr auto xor_module = R"####(module basic_xor endmodule)####";

constexpr auto tb_xor_module =
    R"####(module tb_basic_xor;
   reg a = 0;
   reg b = 0;
   reg clk = 0;
   initial
      begin
         $dumpfile("tb_basic_xor.vcd");
         $dumpvars;

         #20 a = !a;
         #10 a = !a;
         #10 b = !b;
         #10 b = !b;
         #10 a = !a;
         #10 clk = !clk;
         #10 a = !a;
         #10 clk = !clk;
         #10 b = !b;
         #10 clk = !clk;
      end

   initial
      begin
         $display("\t\ttime,\ta,\tb,\tclk,\tout");
         $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,a,b,clk,out);
      end

   basic_xor DUT (a, b, clk, out);

   initial
      #120 $finish;
endmodule)####";

constexpr auto tb_dro_module = R"####(module tb_basic_dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_basic_dro);
         $dumpfile("tb_basic_dro.vcd");
         $dumpvars;

         #10 set = !set;
         #10 set = !set;
         #2.4 reset = !reset; //should cause timing violation
         #10 reset = !reset;
      end

   initial
      begin
         $display("\t\ttime,\tset,\treset,\tout");
         $monitor("\t\t%0t,\t%b,\t%b,\t%b",$realtime,set,reset,out);
      end

   basic_dro DUT (set, reset, out);

   initial
      #50 $finish;
endmodule)####";

constexpr auto tb_dro_example = R"####(
// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`include "dro.v"
`timescale 1ps/100fs
module tb_basic_dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_basic_dro);
         $dumpfile("tb_basic_dro.vcd");
         $dumpvars;

         #10 set = !set;
         #10 set = !set;
         #2.4 reset = !reset; //should cause timing violation
         #10 reset = !reset;
      end

   initial
      begin
         $display("\t\ttime,\tset,\treset,\tout");
         $monitor("\t\t%0t,\t%b,\t%b,\t%b",$realtime,set,reset,out);
      end

   basic_dro DUT (set, reset, out);

   initial
      #50 $finish;
endmodule

)####";

constexpr auto tb_and_example = R"####(
// Adapted from timEx generated files for vcd_assert testing
`timescale 1ps/100fs
module tb_basic_ndro;
  reg set = 0;
  reg reset = 0;
  reg clk = 0;

  initial begin
      `ifndef IVERILOG_WORKAROUND
      $sdf_annotate("../ndro.sdf", tb_basic_ndro);
      `endif
      $dumpfile("tb_basic_ndro.vcd");
      $dumpvars;

      #20 set = !set;
      #10 set = !set;
      #10 reset = !reset;
      #10 reset = !reset;
      #10 clk = !clk;
      #2 reset = !reset; // timing violation
  end

  initial begin
      $display("\t\ttime,\tset,\treset,\tclk,\tout");
      $monitor("%d,\t%b,\t%b,\t%b,\t%b",$time,set,reset,clk,out);
  end

  basic_ndro DUT (set, reset, clk, out);

  initial #70 $finish;
endmodule
)####";

void catch_design(DesignView wanted, Design test);
void catch_module(Module wanted, Module test);
void catch_instance(Instance wanted, Instance test);

} // namespace Verilog::Test::Verilog::IEEE1364_2001

#endif // UNIT_VERILOG_TEST_DESIGN_HPP
