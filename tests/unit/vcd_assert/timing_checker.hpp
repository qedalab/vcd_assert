#ifndef TEST_VCDADSSERT_TIMING_CHECKER_HPP
#define TEST_VCDADSSERT_TIMING_CHECKER_HPP

#include "vcd_assert/timing_checker.hpp"

#include "../vcd/test/header.hpp"

#include <verilog/types/design_reader.hpp>
#include <verilog/types/design.hpp>

#include <sdf/types/delayfile.hpp>
#include <sdf/types/timing.hpp>
#include <sdf/types/timing_spec.hpp>
#include <sdf/types/timing_check.hpp>
#include <sdf/types/enums.hpp>


#include <catch2/catch.hpp>

using namespace VCDAssert;
using namespace Verilog;
using namespace VCD;
using namespace SDF;



// constexpr auto basic_dro_vcd_output = R"###($date
// 	Sun Jul 29 13:25:32 2018
// $end
// $version
// 	Icarus Verilog
// $end
// $timescale
// 	100fs
// $end
// $scope module tb_basic_dro $end
// $var wire 1 ! out $end
// $var reg 1 " reset $end
// $var reg 1 # set $end
// $scope module DUT $end
// $var wire 1 " reset $end
// $var wire 1 # set $end
// $var wire 1 $ internal_state_3 $end
// $var wire 1 % internal_state_2 $end
// $var wire 1 & internal_state_1 $end
// $var wire 1 ' internal_state_0 $end
// $var reg 1 ( out $end
// $var integer 32 ) state [31:0] $end
// $upscope $end
// $upscope $end
// $enddefinitions $end)###";

inline VCD::Test::TestHeader basic_dro_vcd_header {
  VCD::TimeScale {VCD::TimeNumber::_100, VCD::TimeUnit::fs},
  "Jul 29, 2018 13:25:32",
  "Icarus Verilog" ,
  VCD::Test::TestScope {
    VCD::ScopeType::module,
    "tb_basic_dro",
    {
        VCD::Test::TestScope {
          VCD::ScopeType::module,
          "DUT",
          {
            // No modules in m1
          },
          {
              {VCD::VarType::wire,    1,  "\"", "reset"},
              {VCD::VarType::wire,    1,  "#",  "set"},
              {VCD::VarType::wire,    1,  "$",  "internal_state_3"},
              {VCD::VarType::wire,    1,  "%",  "internal_state_2"},
              {VCD::VarType::wire,    1,  "&",  "internal_state_1"},
              {VCD::VarType::wire,    1,  "'",  "internal_state_0"},
              {VCD::VarType::reg,     1,  "(",  "out"},
              {VCD::VarType::integer, 32, ")",  "state3"}
          }
        }
    },
    {
      {VCD::VarType::wire, 1, "!", "out"},
      {VCD::VarType::reg, 1, "\"", "reset"},
      {VCD::VarType::reg, 1, "#", "set"}
    }
  }
};


// (DELAYFILE
//     (SDFVERSION "4.0")
//     (DESIGN "tb_dro")
//     (DATE "Tuesday MAy 29 10:37:33 GMT 2018")
//     (VENDOR "voldemort")        //This is fake btw.
//     (PROGRAM "TimeEx")          //The program that create this file
//     (VERSION "x.y.z")
//     (DIVIDER .)
//     (PROCESS "typical")         // For documentation purposes only.
//     (TEMPERATURE 1:2:4)         // For documentation purposes only.
//     (TIMESCALE 100fs) 
//     /* LRM allows 1, 10, 100, 1.0, 10.0, or 100.0 
//         followed by a unit : s, ms, us, ns, ps, or fs; 
//         But both simulators will round up based on first term used in
//         the `timescale command. 
//         */
//     (CELL
//         (CELLTYPE "basic_dro")
//         (INSTANCE DUT)
//         (DELAY
//             (ABSOLUTE
//                 /*Conditional delays not supported by iverilog */
//                 (COND internal_state_1
//                     (IOPATH reset out (55))
//                 )
//             )
//         )
//         /* iVerilog does not support built-in timing checks (yet) */ 
//         (TIMINGCHECK
//             (HOLD reset (COND internal_state_0 (posedge set)) (25)) 
//             (HOLD reset (COND internal_state_0 (negedge set)) (25)) 

//             (HOLD reset (COND internal_state_1 (posedge set)) (25)) 
//             (HOLD reset (COND internal_state_1 (negedge set)) (25)) 

//             (HOLD set (COND internal_state_0 (posedge reset)) (25)) 
//             (HOLD set (COND internal_state_0 (negedge reset)) (25)) 
//         )
//     )
// )

inline TimingCheckSpec basic_dro_delayfile_tcs{ //timing check spec
  { /*TimingCheck 1*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"reset"},
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"set", SDF::EdgeType::posedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_0"}
        },
        {}
      },
      Number{25}
    }
  },
  { /*TimingCheck 2*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"reset"}, 
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"set", SDF::EdgeType::negedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_0"}
        },
        {}
      },
      Number{25}
    }
  },
  { /*TimingCheck 3*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"reset"},
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"set", SDF::EdgeType::posedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_1"}
        },
        {}
      },
      Number{25}
    }
  },
  { /*TimingCheck 4*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"reset"},
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"set", SDF::EdgeType::negedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_1"}
        },
        {}
      },
      Number{25}
    }
  },
  { /*TimingCheck 5*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"set"},
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"reset", SDF::EdgeType::posedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_0"}
        },
        {}
      },
      Number{25}
    }
  },
  { /*TimingCheck 6*/
    Hold{ //Hold
      { //PortTimingCheck
        {SDF::NodeType::port,"set"},
        {},
        {}
      },
      { //PortTimingCheck
        {SDF::NodeType::port,"reset", SDF::EdgeType::negedge},
        TimingCheckCondition{
          Node{SDF::NodeType::unspecified,"internal_state_0"}
        },
        {}
      },
      Number{25}
    }
  }
};

inline DelayFileView basic_dro_delayfile {
  "4.0",                                // sdf_version;
  "tb_basic_and",                       // design_name;
  "Tuesday MAy 29 10:37:33 GMT 2018",   // date;
  "voldemort",                          // vendor;
  "TimeEx",                             // program_name;
  "x.y.z",                              // program_version;
  "typical",                            // process;
  SDF::HChar::dot,                      // hierarchy_divider;
  {},                                   // voltage;
  SDF::Triple{1,2,4},                   // temperature;
  SDF::TimeScale {                      // timescale;
    SDF::TimeScaleNumber::_100, 
    SDF::TimeScaleUnit::fs
  },  
  { //cell array
    { //cell #1                        
      "basic_dro", 
      SDF::HierarchicalIdentifier{
        SDF::HChar::dot,
        {"DUT"}
      },
      { //timing_spec array
        {basic_dro_delayfile_tcs}
      }
    }
  }
};

// // clang-format off
// inline DesignView tb_dro_example_design_test {
//   { //vector of modules
//     { //module (INCLUDED BEFORE MAIN MODULE)
//       "basic_dro",   // identifier
//       dro_file_path_abs_.to_string(), // path      
//       {}       // instances lookup
//     },
//     { //module
//       "tb_basic_dro",   // identifier
//       tb_dro_file_abs_.to_string(), // path
//       {// instances lookup
//         {"DUT",0}
//       }   
//     }
//   },
//   { //vector of instances
//     {
//       NetType::module, //type_
//       "DUT",            //identifier_    //what to name root net ?
//       0 // index of dro module in module list
//     }
//   },
//   { //module lookup
//     {"basic_dro", 0},
//     {"tb_basic_dro", 1}
//   },
//   { //sdf_commands total
//     { // sdf_commands for tb_dro module
//       SDFAnnotateCommand{
//         "../../dro.sdf", "tb_basic_dro", {}, {}, {}, {}, {}
//       }
//     }
//   }, 
//   { //sdf_commands_lookup_
//     {0,0} // chooses tb_dro's sdf annotation command vector
//   }  
// };
// // clang-format on


#endif // TEST_VCDADSSERT_TIMING_CHECKER_HPP
