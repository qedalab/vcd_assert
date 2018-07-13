#ifndef TEST_SDF_TYPES_TIMING_SPEC_HPP
#define TEST_SDF_TYPES_TIMING_SPEC_HPP

#include "./timing_check.hpp"

#include <catch2/catch.hpp>

#include <sdf/types/timing_spec.hpp>
#include <sdf/types/timing_check.hpp>

#include <variant>

#include <string_view>
using std::literals::string_view_literals::operator""sv;

// #include <ak_toolkit/static_string.hpp>
// namespace sstr = ak_toolkit::static_str;


namespace SDF::Test {

void catch_test_timingspec(TimingSpec wanted,TimingSpec test);

}
#endif //TEST_SDF_TYPES_TIMING_SPEC_HPP