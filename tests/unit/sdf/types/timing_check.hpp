#ifndef TEST_SDF_TYPES_TIMINGCHECK_HPP
#define TEST_SDF_TYPES_TIMINGCHECK_HPP

#include "./timing.hpp"
#include "./values.hpp"


#include <sdf/types/timing_check.hpp>
#include <ak_toolkit/static_string.hpp>
#include <catch2/catch.hpp>
#include <fmt/format.h>

namespace sstr = ak_toolkit::static_str;

namespace SDF::Test {

using namespace SDF;
using namespace Parse::Util;

constexpr auto test_invertednode_1_str = "~" + port_1_str;
constexpr std::string_view test_invertednode_1_sv(
  test_invertednode_1_str, std::size(test_invertednode_1_str));
static const InvertedNode test_invertednode_1{
  port_1
};

constexpr auto test_nodescalarequality_1_str =  port_1_str + "==1";
constexpr std::string_view test_nodescalarequality_1_sv(
  test_nodescalarequality_1_str, std::size(test_nodescalarequality_1_str));
static const NodeScalarEquality test_nodescalarequality_1{
  port_1,
  EqualityOperator::logic_equal,
  true
};

constexpr auto test_invertednode_2_str = "~" + port_3_str;
constexpr std::string_view test_invertednode_2_sv(
  test_invertednode_2_str, std::size(test_invertednode_2_str));
static const InvertedNode test_invertednode_2{
  port_3
};

constexpr auto test_nodescalarequality_2_str = port_3_str + "===1";
constexpr std::string_view test_nodescalarequality_2_sv(
  test_nodescalarequality_2_str, std::size(test_nodescalarequality_2_str));
static const NodeScalarEquality test_nodescalarequality_2{
  port_3,
  EqualityOperator::case_equal,
  true
};

constexpr auto test_invertednode_3_str = "~" + node_3_str;
constexpr std::string_view test_invertednode_3_sv(
  test_invertednode_3_str, std::size(test_invertednode_3_str));
static const InvertedNode test_invertednode_3{
  node_3
};

constexpr auto test_nodescalarequality_3_str = port_4_str + "!==1";
constexpr std::string_view test_nodescalarequality_3_sv(
  test_nodescalarequality_3_str, std::size(test_nodescalarequality_3_str));
static const NodeScalarEquality test_nodescalarequality_3{
  port_4,
  EqualityOperator::case_inv,
  true
};

constexpr auto test_timingcheckcondition_1_str = 
  test_invertednode_1_str;
constexpr std::string_view test_timingcheckcondition_1_sv(
  test_timingcheckcondition_1_str, std::size(test_timingcheckcondition_1_str));
static const TimingCheckCondition test_timingcheckcondition_1{
  test_invertednode_1
};

constexpr auto test_timingcheckcondition_2_str = 
  test_nodescalarequality_1_str;
constexpr std::string_view test_timingcheckcondition_2_sv(
  test_timingcheckcondition_2_str, std::size(test_timingcheckcondition_2_str));
static const TimingCheckCondition test_timingcheckcondition_2{
  test_nodescalarequality_1 
};

constexpr auto test_timingcheckcondition_3_str = 
  test_invertednode_2_str;
constexpr std::string_view test_timingcheckcondition_3_sv(
  test_timingcheckcondition_3_str, std::size(test_timingcheckcondition_3_str));
static const TimingCheckCondition test_timingcheckcondition_3{
  test_invertednode_2
};

constexpr auto test_timingcheckcondition_4_str = 
  test_nodescalarequality_2_str;
constexpr std::string_view test_timingcheckcondition_4_sv(
  test_timingcheckcondition_4_str, std::size(test_timingcheckcondition_4_str));
static const TimingCheckCondition test_timingcheckcondition_4{
  test_nodescalarequality_2 
};

constexpr auto test_porttimingcheck_1_str = 
  "(COND " + node_1_str + " " + port_1_str + ")";
constexpr std::string_view test_porttimingcheck_1_sv(
  test_porttimingcheck_1_str, std::size(test_porttimingcheck_1_str));
static const PortTimingCheck test_porttimingcheck_1{
  port_1_posedge,
  node_1
};

constexpr auto test_porttimingcheck_2_str = 
  port_1_posedge_str;
constexpr std::string_view test_porttimingcheck_2_sv(
  test_porttimingcheck_2_str, std::size(test_porttimingcheck_2_str));
static const PortTimingCheck test_porttimingcheck_2{
  port_1_posedge
};

constexpr auto test_porttimingcheck_3_str = 
  "(COND " + test_invertednode_3_str + " " + port_1_negedge_str + ")";
constexpr std::string_view test_porttimingcheck_3_sv(
  test_porttimingcheck_3_str, std::size(test_porttimingcheck_3_str));
static const PortTimingCheck test_porttimingcheck_3{
  port_1_negedge,
  test_invertednode_3
};

constexpr auto test_porttimingcheck_4_str = 
  port_4_str;
constexpr std::string_view test_porttimingcheck_4_sv(
  test_porttimingcheck_4_str, std::size(test_porttimingcheck_4_str));
static const PortTimingCheck test_porttimingcheck_4{
  port_4
};

constexpr auto test_hold_1_str = 
  "(HOLD " + port_2_str 
  + " " + test_porttimingcheck_1_str 
  + " " + test_triple_value_2_str
  + ")";
constexpr std::string_view test_hold_1_sv(
  test_hold_1_str, std::size(test_hold_1_str));
static const Hold test_hold_1{
  {port_2},
  test_porttimingcheck_1,
  test_triple_value_2
};

constexpr auto test_hold_2_str = 
  "(HOLD " + port_3_str 
  + " " + test_porttimingcheck_2_str 
  + " " + test_triple_value_2_str
  + ")";
constexpr std::string_view test_hold_2_sv(
  test_hold_2_str, std::size(test_hold_2_str));
static const Hold test_hold_2{
  {port_3},
  test_porttimingcheck_2,
  test_triple_value_2
};

constexpr auto test_hold_3_str = 
  "(HOLD " + port_4_str 
  + " " + test_porttimingcheck_3_str 
  + " " + test_triple_value_2_str
  + ")";
constexpr std::string_view test_hold_3_sv(
  test_hold_3_str, std::size(test_hold_3_str));
static const Hold test_hold_3{
  {port_4},
  test_porttimingcheck_3,
  test_triple_value_2
};

constexpr auto test_timingcheck_1_str = 
  test_hold_1_str;
constexpr std::string_view test_timingcheck_1_sv(
  test_timingcheck_1_str, std::size(test_timingcheck_1_str));
static const TimingCheck test_timingcheck_1{
  test_hold_1
};

constexpr auto test_timingcheck_2_str = 
  test_hold_2_str;
constexpr std::string_view test_timingcheck_2_sv(
  test_timingcheck_2_str, std::size(test_timingcheck_2_str));
static const TimingCheck test_timingcheck_2{
  test_hold_2
};

constexpr auto test_timingcheck_3_str = 
  test_hold_3_str;
constexpr std::string_view test_timingcheck_3_sv(
  test_timingcheck_3_str, std::size(test_timingcheck_3_str));
static const TimingCheck test_timingcheck_3{
  test_hold_3
};

constexpr auto test_timingcheckspec_1_str = 
    "(TIMINGCHECK \n  " + test_timingcheck_1_str 
    + "\n  " + test_timingcheck_2_str 
    + "\n  " + test_timingcheck_3_str
    + "\n)"; 
constexpr std::string_view test_timingcheckspec_1_sv(
  test_timingcheckspec_1_str, std::size(test_timingcheckspec_1_str));
static const TimingCheckSpec test_timingcheckspec_1{
  test_timingcheck_1,
  test_timingcheck_2,
  test_timingcheck_3
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_TIMINGCHECK_HPP
