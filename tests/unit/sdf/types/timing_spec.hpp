#ifndef TEST_SDF_TYPES_TIMING_SPEC_HPP
#define TEST_SDF_TYPES_TIMING_SPEC_HPP

#include "./timing_check.hpp"

#include <catch2/catch.hpp>

#include <sdf/types/timing_spec.hpp>
#include <sdf/types/timing_check.hpp>

#include <variant>

#include <string_view>

namespace SDF::Test {

constexpr auto test_timingspec_1_str = test_timingcheckspec_1_str;
constexpr std::string_view test_timingspec_1_sv(
  test_timingspec_1_str, std::size(test_timingspec_1_str));
static const TimingSpec test_timingspec_1{
  {test_timingcheckspec_1}
};

constexpr auto test_timingspec_array_1_str = 
  test_timingcheckspec_1_str;
constexpr std::string_view test_timingspec_array_1_sv(
  test_timingspec_array_1_str, std::size(test_timingspec_array_1_str));
static const std::vector<TimingSpec> test_timingspec_array_1{
  {test_timingcheckspec_1}
};

void catch_test_timingspec(TimingSpec wanted,TimingSpec test);

}
#endif //TEST_SDF_TYPES_TIMING_SPEC_HPP
