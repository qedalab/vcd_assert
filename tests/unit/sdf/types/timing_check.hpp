#ifndef TEST_SDF_TYPES_TIMINGCHECK_HPP
#define TEST_SDF_TYPES_TIMINGCHECK_HPP

#include <catch2/catch.hpp>

// #include <sdf/types/base.hpp>
#include <sdf/types/timing_check.hpp>

#include "./timing.hpp"
#include "./values.hpp"


namespace SDF::Test {

using namespace SDF;


static const InvertedNode test_invertednode_1{
  port_1
};

static const NodeScalarEquality test_nodescalarequality_1{
  port_1,
  EqualityOperator::logic_equal,
  true
};

static const InvertedNode test_invertednode_2{
  port_3
};

static const NodeScalarEquality test_nodescalarequality_2{
  port_3,
  EqualityOperator::case_equal,
  true
};

static const InvertedNode test_invertednode_3{
  node_3
};

static const NodeScalarEquality test_nodescalarequality_3{
  port_4,
  EqualityOperator::case_inv,
  true
};

static const TimingCheckCondition test_timingcheckcondition_1{
  test_invertednode_1
};

static const TimingCheckCondition test_timingcheckcondition_2{
  test_nodescalarequality_1 
};

static const TimingCheckCondition test_timingcheckcondition_3{
  test_invertednode_2
};

static const TimingCheckCondition test_timingcheckcondition_4{
  test_nodescalarequality_2 
};

static const PortTimingCheck test_porttimingcheck_1{
  port_1,
  EdgeType::posedge,
  node_1
};

static const PortTimingCheck test_porttimingcheck_2{
  port_1,
  EdgeType::posedge
};

static const PortTimingCheck test_porttimingcheck_3{
  port_1,
  EdgeType::negedge,
  test_invertednode_3
};

static const PortTimingCheck test_porttimingcheck_4{
  port_4
};

static const Hold test_hold_1{
  {port_2},
  test_porttimingcheck_1,
  test_triple_value_2
};

static const Hold test_hold_2{
  {port_3},
  test_porttimingcheck_2,
  test_triple_value_2
};

static const Hold test_hold_3{
  {port_4},
  test_porttimingcheck_3,
  test_triple_value_2
};

static const TimingCheck test_timingcheck_1{
  test_hold_1
};

static const TimingCheck test_timingcheck_2{
  test_hold_2
};

static const TimingCheck test_timingcheck_3{
  test_hold_3
};

static const TimingCheckSpec test_timingcheckspec_1{
  test_timingcheck_1,
  test_timingcheck_2,
  test_timingcheck_3
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_TIMINGCHECK_HPP
