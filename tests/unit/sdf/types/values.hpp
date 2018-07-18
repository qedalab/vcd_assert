#ifndef TEST_SDF_TYPES_VALUES_HPP
#define TEST_SDF_TYPES_VALUES_HPP

#include <catch2/catch.hpp>

#include <sdf/types/values.hpp>
#include <fmt/format.h>

#include "parse/util/static_string.hpp"

namespace SDF::Test {

using namespace Parse::Util;

constexpr auto test_triple_1_str = static_string("0.0:0.5:1");
inline const Triple test_triple_1{
  0.0, 0.5, 1
};

constexpr auto test_triple_2_str = static_string("1:1:1");
inline const Triple test_triple_2{
  1, 1, 1
};

constexpr auto test_triple_3_str = static_string("1.0:2.0:3.0");
inline const Triple test_triple_3{
  1.0, 2.0, 3.0
};

constexpr auto test_triple_4_str = static_string("-1:-2:-3");
inline const Triple test_triple_4{
  -1, -2, -3
};

constexpr auto test_number_str = static_string("0.5");
inline const Number test_number{
  0.5
};

constexpr auto test_number_1_str = static_string("1.5");
inline const Number test_number_1{
  1.5
};

constexpr auto test_number_2_str = static_string("-10.5");
inline const Number test_number_2{
  -10.5
};

constexpr auto test_number_3_str = static_string(".5");
inline const Number test_number_3{
  .5
};

constexpr auto test_number_4_str = static_string("4");
inline const Number test_number_4{
  4
};

inline const Number test_number_value_0{
  test_number_1
};

constexpr auto test_number_value_1_str = "(" + test_number_1_str + ")";
inline const Number test_number_value_1{
  test_number_1
};

constexpr auto test_number_value_2_str = "(" + test_number_2_str + ")";
inline const Number test_number_value_2{
  Number{test_number_2}
};

constexpr auto test_number_value_3_str = "(" + test_number_3_str + ")";
inline const Number test_number_value_3{
  Number{test_number_3}
};

constexpr auto test_number_value_4_str = "(" + test_number_4_str + ")";
inline const Number test_number_value_4{
  test_number_4
};

constexpr auto test_triple_value_1_str = "(" + test_triple_1_str + ")";
inline const Triple test_triple_value_1{
  Triple{test_triple_1.min, test_triple_1.typ, test_triple_1.max}
};

constexpr auto test_triple_value_2_str = "(" + test_triple_2_str + ")";
inline const Triple test_triple_value_2{
  Triple{test_triple_2.min, test_triple_2.typ, test_triple_2.max}
};

constexpr auto test_triple_value_3_str = "(" + test_triple_3_str + ")";
inline const Triple test_triple_value_3{
  Triple{test_triple_3.min, test_triple_3.typ, test_triple_3.max}
};

constexpr auto test_triple_value_4_str = "(" + test_triple_4_str + ")";
inline const Triple test_triple_value_4{
  Triple{test_triple_4.min, test_triple_4.typ, test_triple_4.max}
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);
void catch_test_triple(SDF::Triple wanted, SDF::Triple test);
} // SDF::Test

#endif // TEST_SDF_TYPES_VALUES_HPP
