#ifndef TEST_SDF_TYPES_VALUES_HPP
#define TEST_SDF_TYPES_VALUES_HPP

#include <catch2/catch.hpp>

#include <sdf/types/values.hpp>
#include <fmt/format.h>

#include <ak_toolkit/static_string.hpp>
namespace sstr = ak_toolkit::static_str;

namespace SDF::Test {

constexpr auto test_triple_1_str = sstr::literal("0.0:0.5:1");
constexpr std::string_view test_triple_1_sv(
  test_triple_1_str,std::size(test_triple_1_str));
static const Triple test_triple_1{
  0.0, 0.5, 1
};

constexpr auto test_triple_2_str = sstr::literal("1:1:1");
constexpr std::string_view test_triple_2_sv(
  test_triple_2_str,std::size(test_triple_2_str));
static const Triple test_triple_2{
  1, 1, 1
};

constexpr auto test_triple_3_str = sstr::literal("1.0:2.0:3.0");
constexpr std::string_view test_triple_3_sv(
  test_triple_3_str,std::size(test_triple_3_str));
static const Triple test_triple_3{
  1.0, 2.0, 3.0
};

constexpr auto test_triple_4_str = sstr::literal("-1:-2:-3");
constexpr std::string_view test_triple_4_sv(
  test_triple_4_str,std::size(test_triple_4_str));
static const Triple test_triple_4{
  -1, -2, -3
};

constexpr auto test_number_str = sstr::literal("0.5");
constexpr std::string_view test_number_sv(
  test_number_str,std::size(test_number_str));
static const Number test_number{
  0.5
};

constexpr auto test_number_1_str = sstr::literal("1.5");
constexpr std::string_view test_number_1_sv(
  test_number_1_str,std::size(test_number_1_str));
static const Number test_number_1{
  1.5
};

constexpr auto test_number_2_str = sstr::literal("-10.5");
constexpr std::string_view test_number_2_sv(
  test_number_2_str,std::size(test_number_2_str));
static const Number test_number_2{
  -10.5
};

constexpr auto test_number_3_str = sstr::literal(".5");
constexpr std::string_view test_number_3_sv(
  test_number_3_str,std::size(test_number_3_str));
static const Number test_number_3{
  .5
};

constexpr auto test_number_4_str = sstr::literal("4");
constexpr std::string_view test_number_4_sv(
  test_number_4_str,std::size(test_number_4_str));
static const Number test_number_4{
  4
};

static const Number test_number_value_0{
  test_number_1
};

constexpr auto test_number_value_1_str = "(" + test_number_1_str + ")";
constexpr std::string_view test_number_value_1_sv(
  test_number_value_1_str,std::size(test_number_value_1_str));
static const Number test_number_value_1{
  test_number_1
};

constexpr auto test_number_value_2_str = "(" + test_number_2_str + ")";
constexpr std::string_view test_number_value_2_sv(
  test_number_value_2_str,std::size(test_number_value_2_str));
static const Number test_number_value_2{
  Number{test_number_2}
};

constexpr auto test_number_value_3_str = "(" + test_number_3_str + ")";
constexpr std::string_view test_number_value_3_sv(
  test_number_value_3_str,std::size(test_number_value_3_str));
static const Number test_number_value_3{
  Number{test_number_3}
};

constexpr auto test_number_value_4_str = "(" + test_number_4_str + ")";
constexpr std::string_view test_number_value_4_sv(
  test_number_value_4_str,std::size(test_number_value_4_str));
static const Number test_number_value_4{
  test_number_4
};

constexpr auto test_triple_value_1_str = "(" + test_triple_1_str + ")";
constexpr std::string_view test_triple_value_1_sv(
  test_triple_value_1_str,std::size(test_triple_value_1_str));
static const Triple test_triple_value_1{
  Triple{test_triple_1.min, test_triple_1.typ, test_triple_1.max}
};

constexpr auto test_triple_value_2_str = "(" + test_triple_2_str + ")";
constexpr std::string_view test_triple_value_2_sv(
  test_triple_value_2_str,std::size(test_triple_value_2_str));
static const Triple test_triple_value_2{
  Triple{test_triple_2.min, test_triple_2.typ, test_triple_2.max}
};

constexpr auto test_triple_value_3_str = "(" + test_triple_3_str + ")";
constexpr std::string_view test_triple_value_3_sv(
  test_triple_value_3_str,std::size(test_triple_value_3_str));
static const Triple test_triple_value_3{
  Triple{test_triple_3.min, test_triple_3.typ, test_triple_3.max}
};

constexpr auto test_triple_value_4_str = "(" + test_triple_4_str + ")";
constexpr std::string_view test_triple_value_4_sv(
  test_triple_value_4_str,std::size(test_triple_value_4_str));
static const Triple test_triple_value_4{
  Triple{test_triple_4.min, test_triple_4.typ, test_triple_4.max}
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);
void catch_test_triple(SDF::Triple wanted, SDF::Triple test);
} // SDF::Test

#endif // TEST_SDF_TYPES_VALUES_HPP
