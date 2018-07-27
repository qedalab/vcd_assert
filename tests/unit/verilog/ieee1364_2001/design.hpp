#ifndef UNIT_VERILOG_TEST_DESIGN_HPP
#define UNIT_VERILOG_TEST_DESIGN_HPP

namespace Verilog::Test{
namespace Verilog::IEEE1364_2001{


// Test::Design dro_example_design_test {
//   { //vector
//     { //module
//       "dro",   // identifier
//       {},      // instances
//       {},      // variable
//       {}       // attributes
//     }
//   },
//   {},
//   {},
//   {},

//   Test::Net { 
//       NetType::module, //type_
//       "dro",           //identifier_    //what to name root net ?
//       (std::size_t)0   //definition_index_ 
//       {
//           // No child nets
//       },
//       {
//           // No variables 
//       }
//   }
// };

// Test::Design tb_dro_example_design_test {
//   { //vector
//     { //module
//       "dro",   // identifier
//       {},      // instances
//       {},      // variable
//       {}       // attributes
//     }
//   },
//   {},
//   {},
//   {},

//   Test::Net { 
//       NetType::module, //type_
//       "dro",           //identifier_    //what to name root net ?
//       (std::size_t)0   //definition_index_ 
//       {
//           // No child nets
//       },
//       {
//           // No variables 
//       }
//   }
// };



constexpr auto include_statement = "include \"to_be_included\"";
constexpr auto include_statement_no_qstring = "include to_be_included";
constexpr auto compiler_directive = "`include \"to_be_included\"";

constexpr auto module_keyword = "module";
constexpr auto module_declaration_1 = "module dro; endmodule";
constexpr auto module_declaration_2 = "module dro(); endmodule";
constexpr auto module_declaration_3 = "module dro (); endmodule";
constexpr auto module_declaration_4 = "module dro (set, reset, out);endmodule";
constexpr auto module_declaration_5 = "module  dro (set, reset, out);endmodule";
constexpr auto module_declaration_6 = "module dro  (set, reset, out);\nendmodule";
constexpr auto module_declaration_7 = "module dro (set, reset, out);endmodule";

constexpr auto module_example_1 = "\nmodule dro;\nendmodule";

constexpr auto module_example_2 = "\nmodule dro (set, reset, out);\nendmodule\n";

constexpr auto module_example_3 = R"####(
module dro (set, reset, out);
endmodule
)####";

constexpr auto sdf_annotate_example = R"####($sdf_annotate("../../dro.sdf", tb_dro);)####";


constexpr auto begin_end_example_1 = "begin dro;\nend";
constexpr auto begin_end_example_2 = "begin \n\t a = 1;\n\n\tend";
constexpr auto begin_end_example_3 = "begin \n\t a = 1;\n\n\tend";
constexpr auto begin_end_example_4 = "begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";
constexpr auto begin_end_example_5 = "begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";

constexpr auto initial_block_example_1 = "initial begin dro;\nend";
constexpr auto initial_block_example_2 = "initial \n\tbegin \n\t a = 1;\n\n\tend";
constexpr auto initial_block_example_3 = "initial \n\tbegin \n\t a = 1;\n\n\tend\n";
constexpr auto initial_block_example_4 = "initial begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";
constexpr auto initial_block_example_5 = "initial begin\n\tif(a == 1) begin\n\t\ta=0;\n\tend\nend";

constexpr auto initial_block_with_sdf_example_1 = 
R"####(initial
      begin
         $sdf_annotate("../../dro.sdf", tb_dro);
         $dumpfile("tb_dro_example_1.vcd");
         $dumpvars;

         #10 set = !set;
         #10 set = !set;
         #2.4 reset = !reset; //should cause timing violation
         #10 reset = !reset;
      end)####";

constexpr auto dro_example = R"####(
// ---------------------------------------------------------------------------
// Automatically extracted verilog file, created with TimEx v1.01.00
// Timing description and structural design for IARPA-BAA-14-03.
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// (c) 2016-2017 Stellenbosch University
// ---------------------------------------------------------------------------
`timescale 1ps/100fs
module dro (set, reset, out);

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

constexpr auto basic_annotation_example = R"####(
`timescale 1ps/100fs
module dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_dro);
         $dumpfile("tb_dro_example_1.vcd");
         $dumpvars;

         #10 set = !set;
      end

endmodule
)####";

constexpr auto tb_dro_example = R"####(
// ---------------------------------------------------------------------------
// Verilog testbench file, created with TimEx v1.00.02
// For questions about TimEx, contact CJ Fourie, coenrad@sun.ac.za
// ---------------------------------------------------------------------------
`include "dro.v"
`timescale 1ps/100fs
module tb_dro;
   reg set = 0;
   reg reset = 0;

   initial
      begin
         $sdf_annotate("../../dro.sdf", tb_dro);
         $dumpfile("tb_dro_example_1.vcd");
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

   dro DUT (set, r$sdf_annotate("../../dro.sdf", tb_dro);

   initial
      #50 $finish;$sdf_annotate("../../dro.sdf", tb_dro);
endmodule

)####";


} // namespace Test::Verilog::IEEE1364_2001
}


#endif // UNIT_VERILOG_TEST_DESIGN_HPP
