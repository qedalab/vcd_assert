#ifndef TEST_SDF_TYPES_TIMINGCHECK_HPP
#define TEST_SDF_TYPES_TIMINGCHECK_HPP

#include "./timing.hpp"
#include "./values.hpp"

#include <catch2/catch.hpp>

#include <sdf/types/timing_check.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <range/v3/utility/iterator.hpp>

#include <variant>
#include <fmt/format.h>
#include <string>
#include <string_view>

#include "parse/util/static_string.hpp"

namespace SDF::Test {

using namespace SDF;
using namespace Parse::Util;

constexpr auto test_invertednode_1_str = "~" + port_1_str;
inline const InvertedNode test_invertednode_1{
  port_1
};

constexpr auto test_nodeconstantequality_1_str =  port_1_str + "==1";
inline const NodeConstantEquality test_nodeconstantequality_1{
  port_1,
  EqualityOperator::logic_equal,
  true
};

constexpr auto test_invertednode_2_str = "~" + port_3_str;
inline const InvertedNode test_invertednode_2{
  port_3
};

constexpr auto test_nodeconstantequality_2_str = port_3_str + "===1";
inline const NodeConstantEquality test_nodeconstantequality_2{
  port_3,
  EqualityOperator::case_equal,
  true
};

constexpr auto test_invertednode_3_str = "~" + node_3_str;
inline const InvertedNode test_invertednode_3{
  node_3
};

constexpr auto test_nodeconstantequality_3_str = port_4_str + "!==1";
inline const NodeConstantEquality test_nodeconstantequality_3{
  port_4,
  EqualityOperator::case_inv,
  true
};

constexpr auto test_timingcheckcondition_1_str = 
  test_invertednode_1_str;
inline const TimingCheckCondition test_timingcheckcondition_1{
  test_invertednode_1
};

constexpr auto test_timingcheckcondition_2_str = 
  test_nodeconstantequality_1_str;
inline const TimingCheckCondition test_timingcheckcondition_2{
  test_nodeconstantequality_1 
};

constexpr auto test_timingcheckcondition_3_str = 
  test_invertednode_2_str;
inline const TimingCheckCondition test_timingcheckcondition_3{
  test_invertednode_2
};

constexpr auto test_timingcheckcondition_4_str = 
  test_nodeconstantequality_2_str;
inline const TimingCheckCondition test_timingcheckcondition_4{
  test_nodeconstantequality_2 
};

constexpr auto test_porttimingcheck_1_str = 
  "(COND " + node_1_str + " " + port_1_posedge_str + ")";
inline const PortTimingCheck test_porttimingcheck_1{
  port_1_posedge,
  TimingCheckCondition{node_1}
};

constexpr auto test_porttimingcheck_2_str = 
  port_1_posedge_str;
inline const PortTimingCheck test_porttimingcheck_2{
  port_1_posedge
};

constexpr auto test_porttimingcheck_3_str = 
  "(COND " + test_invertednode_3_str + " " + port_1_negedge_str + ")";
inline const PortTimingCheck test_porttimingcheck_3{
  port_1_negedge,
  TimingCheckCondition{test_invertednode_3}
};

constexpr auto test_porttimingcheck_4_str = 
  port_4_str;
inline const PortTimingCheck test_porttimingcheck_4{
  port_4
};

constexpr auto test_hold_1_str = 
  "(HOLD " + port_2_str 
  + " " + test_porttimingcheck_1_str 
  + " " + test_triple_value_2_str
  + ")";
inline const Hold test_hold_1{
  {port_2},
  test_porttimingcheck_1,
  test_triple_value_2
};

constexpr auto test_hold_2_str = 
  "(HOLD " + port_3_str 
  + " " + test_porttimingcheck_2_str 
  + " " + test_triple_value_2_str
  + ")";
inline const Hold test_hold_2{
  {port_3},
  test_porttimingcheck_2,
  test_triple_value_2
};

constexpr auto test_hold_3_str = 
  "(HOLD " + port_4_str 
  + " " + test_porttimingcheck_3_str 
  + " " + test_triple_value_2_str
  + ")";
inline const Hold test_hold_3{
  {port_4},
  test_porttimingcheck_3,
  test_triple_value_2
};

constexpr auto test_timingcheck_1_str = 
  test_hold_1_str;
inline const TimingCheck test_timingcheck_1{
  test_hold_1
};

constexpr auto test_timingcheck_2_str = 
  test_hold_2_str;
inline const TimingCheck test_timingcheck_2{
  test_hold_2
};

constexpr auto test_timingcheck_3_str = 
  test_hold_3_str;
inline const TimingCheck test_timingcheck_3{
  test_hold_3
};

constexpr auto test_timingcheckspec_1_str = 
    "(TIMINGCHECK \n  " + test_timingcheck_1_str 
    + "\n  " + test_timingcheck_2_str 
    + "\n  " + test_timingcheck_3_str
    + "\n)"; 
inline const TimingCheckSpec test_timingcheckspec_1{
  test_timingcheck_1,
  test_timingcheck_2,
  test_timingcheck_3
};

void catch_test_invertednode(InvertedNode wanted, InvertedNode test);
void catch_test_nodeconstantequality(NodeConstantEquality wanted, 
                                    NodeConstantEquality test);
void catch_test_timingcheckcondition(TimingCheckCondition wanted, 
                                    TimingCheckCondition test);
void catch_test_porttimingcheck(PortTimingCheck wanted, 
                                PortTimingCheck test);
void catch_test_hold(Hold wanted, Hold test);
void catch_test_timingcheck(TimingCheck wanted, TimingCheck test);
void catch_test_timingcheckspec(TimingCheckSpec wanted, 
                                TimingCheckSpec test);
} // SDF::Test

#endif // TEST_SDF_TYPES_TIMINGCHECK_HPP
