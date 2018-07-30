#ifndef TEST_VCDADSSERT_TIMING_CHECKER_HPP
#define TEST_VCDADSSERT_TIMING_CHECKER_HPP

#include "../sdf/types/delayfile.hpp"

// #include <sdf/types/base.hpp>
// #include <sdf/types/enums.hpp>
#include <sdf/types/delayfile.hpp>

// #include "sdf/types/delayfile_reader.hpp"
// #include "sdf/types/delayfile.hpp"

#include <catch2/catch.hpp>

//  inline const VCD::Test::TestHeader vcd_4_state_example_header {
//     VCD::TimeScale {VCD::TimeNumber::_1, VCD::TimeUnit::ns},
//     "June 26, 1989 10:05:41",
//     "VERILOG-SIMULATOR 1.0a",
//     VCD::Test::TestScope {
//       ScopeType::module,
//       "top",
//       {
//           VCD::Test::TestScope {
//             ScopeType::module,
//             "m1",
//             {
//               // No modules in m1
//             },
//             {
//                 {VarType::trireg, 1, "*@", "net1"},
//                 {VarType::trireg, 1, "*#", "net2"},
//                 {VarType::trireg, 1, "*$", "net3"}
//             }
//           },
//           VCD::Test::TestScope {
//             ScopeType::task,
//             "t1",
//             {
//               // modules in t1
//             },
//             {
//                 {VarType::reg, 32, "(k", "accumulator[31:0]"},
//                 {VarType::integer, 32, "{k", "index"}
//             }
//           }
//       },
//       {
//         // No variables in top
//       }
//     }
//   };



inline const DelayFileView minimal_delayfile {
  "4.0",                                             
  "system",                                          
  "Saturday September 30 08:30:33 PST 1990",         
  "Yosemite Semiconductor",                          
  "delay_calc",                                      
  "1.5",                                             
  "worst",                                           
  SDF::HChar::slash,                                      
  SDF::Triple{5.5,5.0,4.5},                               
  SDF::Triple{55.0,85.0,125.0},                           
  SDF::TimeScale {SDF::TimeScaleNumber::_1, SDF::TimeScaleUnit::ns},
  {{}}                                               
};

inline const DelayFileView basic_delayfile {
  "4.0",                                             
  "system",                                          
  "Saturday September 30 08:30:33 PST 1990",         
  "Yosemite Semiconductor",                          
  "delay_calc",                                      
  "1.5",                                             
  "worst",                                           
  SDF::HChar::slash,                                      
  SDF::Triple{5.5,5.0,4.5},                               
  SDF::Triple{55.0,85.0,125.0},                           
  SDF::TimeScale {SDF::TimeScaleNumber::_1, SDF::TimeScaleUnit::ns},
  {test_cell_1}                                      
};

// void catch_test_delayfile(DelayFileView wanted, DelayFile &test);


#endif // TEST_VCDADSSERT_TIMING_CHECKER_HPP
