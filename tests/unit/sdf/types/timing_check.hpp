#ifndef TEST_SDF_TYPES_TIMINGCHECK_HPP
#define TEST_SDF_TYPES_TIMINGCHECK_HPP


// #include <sdf/types/base.hpp>
#include <sdf/types/timing_check.hpp>
// #include <parse/util/constexpr_concat.hpp>

#include "./timing.hpp"
#include "./values.hpp"

#include <catch2/catch.hpp>
#include <fmt/format.h>

#include <parse/util/static_string.hpp>


namespace SDF::Test {

using namespace SDF;

using namespace Parse::Util;
namespace sstr = ak_toolkit::static_str;



// auto const basic_example_delayfile = 
// R"####((DELAYFILE
//   (SDFVERSION "4.0")
//   (DESIGN "system")
//   (DATE "Saturday September 30 08:30:33 PST 1990")
//   (VENDOR "Yosemite Semiconductor")
//   (PROGRAM "delay_calc")
//   (VERSION "1.5")
//   (DIVIDER /)
//   (VOLTAGE 5.5:5.0:4.5)
//   (PROCESS "worst")
//   (TEMPERATURE 55:85:125)
//   (TIMESCALE 1ns)
//   (CELL
//     (CELLTYPE "DFF")
//     (CELLINSTANCE )
//     (TIMINGCHECK
//       (HOLD D (COND D_ENABLE (posedge CP)) (1:1:1))
//       (HOLD E (posedge CP) (1:1:1))
//       (HOLD F (COND ~F_ENABLE (negedge CP)) (1:1:1))
//     )
//   )
// )
// )####";

auto const test_invertednode_1_str = fmt::format("~",port_1_str);
static const InvertedNode test_invertednode_1{
  port_1
};

auto const test_nodescalarequality_1_str = fmt::format("{}==1",port_1_str);
static const NodeScalarEquality test_nodescalarequality_1{
  port_1,
  EqualityOperator::logic_equal,
  true
};

auto const test_invertednode_2_str = fmt::format("~{}",port_3_str);
static const InvertedNode test_invertednode_2{
  port_3
};

auto const test_nodescalarequality_2_str = fmt::format("{}===1",port_3_str);
static const NodeScalarEquality test_nodescalarequality_2{
  port_3,
  EqualityOperator::case_equal,
  true
};

auto const test_invertednode_3_str = fmt::format("~{}",node_3_str);
static const InvertedNode test_invertednode_3{
  node_3
};

auto const test_nodescalarequality_3_str = fmt::format("{}!==1",port_4_str);
static const NodeScalarEquality test_nodescalarequality_3{
  port_4,
  EqualityOperator::case_inv,
  true
};

auto const test_timingcheckcondition_1_str = test_invertednode_1_str;
static const TimingCheckCondition test_timingcheckcondition_1{
  test_invertednode_1
};

auto const test_timingcheckcondition_2_str = test_nodescalarequality_1_str;
static const TimingCheckCondition test_timingcheckcondition_2{
  test_nodescalarequality_1 
};

auto const test_timingcheckcondition_3_str = test_invertednode_2_str;
static const TimingCheckCondition test_timingcheckcondition_3{
  test_invertednode_2
};

auto const test_timingcheckcondition_4_str = test_nodescalarequality_2_str;
static const TimingCheckCondition test_timingcheckcondition_4{
  test_nodescalarequality_2 
};

auto const test_porttimingcheck_1_str = fmt::format("(COND {} (posedge {}))",
  node_1_str, port_1_str);
static const PortTimingCheck test_porttimingcheck_1{
  port_1,
  EdgeType::posedge,
  node_1
};

auto const test_porttimingcheck_2_str = fmt::format("(posedge {}))",
  port_1_str);
static const PortTimingCheck test_porttimingcheck_2{
  port_1,
  EdgeType::posedge
};

auto const test_porttimingcheck_3_str = fmt::format("(COND {} (negedge {}))",
  test_invertednode_3_str, port_1_str);

static const PortTimingCheck test_porttimingcheck_3{
  port_1,
  EdgeType::negedge,
  test_invertednode_3
};

auto const test_porttimingcheck_4_str = port_4_str;
static const PortTimingCheck test_porttimingcheck_4{
  port_4
};

auto const test_hold_1_str = fmt::format("(HOLD {} {} {})",
  port_2_str, test_porttimingcheck_1_str, test_triple_value_2_str);
static const Hold test_hold_1{
  {port_2},
  test_porttimingcheck_1,
  test_triple_value_2
};

auto const test_hold_2_str = fmt::format("(HOLD {} {} {})",
  port_3_str, test_porttimingcheck_2_str, test_triple_value_2_str);
static const Hold test_hold_2{
  {port_3},
  test_porttimingcheck_2,
  test_triple_value_2
};

auto const test_hold_3_str = fmt::format("(HOLD {} {} {})",
  port_4_str, test_porttimingcheck_3_str, test_triple_value_2_str);
static const Hold test_hold_3{
  {port_4},
  test_porttimingcheck_3,
  test_triple_value_2
};

auto const test_timingcheck_1_str = test_hold_1_str;
static const TimingCheck test_timingcheck_1{
  test_hold_1
};

auto const test_timingcheck_2_str = test_hold_2_str;
static const TimingCheck test_timingcheck_2{
  test_hold_2
};

auto const test_timingcheck_3_str = test_hold_3_str;
static const TimingCheck test_timingcheck_3{
  test_hold_3
};

auto const test_timingcheckspec_1_str = 
  fmt::format("(TIMINGCHECK \n  {}\n  {}\n  {}\n)",
    test_timingcheck_1_str, test_timingcheck_2_str, test_timingcheck_3_str);
static const TimingCheckSpec test_timingcheckspec_1{
  test_timingcheck_1,
  test_timingcheck_2,
  test_timingcheck_3
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_TIMINGCHECK_HPP
