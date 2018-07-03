#ifndef LIBSDF_TEST_SDF_HEADER_H
#define LIBSDF_TEST_SDF_HEADER_H


#include "base.hpp"
#include <sdf/grammar/header.hpp>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;


constexpr auto timescale_ex1_str_fmt    = "(TIMESCALE     1ns{})";

constexpr auto sdf_version_ex1_str       = R"((SDFVERSION "4.0" ))"; 
constexpr auto design_name_ex1_str       = R"((DESIGN "system" ))";
constexpr auto date_ex1_str              = R"((DATE "Saturday September 30 08:30:33 PST 1990"))";
constexpr auto vendor_ex1_str            = R"((VENDOR "Yosemite Semiconductor"))";
constexpr auto program_name_ex1_str      = R"((PROGRAM "delay_calc"))";
constexpr auto program_version_ex1_str   = R"((VERSION "1.5"))";
constexpr auto hierarchy_divider_ex1_str = R"((DIVIDER /))";
constexpr auto voltage_ex1_str           = R"((VOLTAGE 5.5:5.0:4.5))";
constexpr auto process_ex1_str           = R"((PROCESS "worst"))";
constexpr auto timescale_number_ex1_str  = R"(1)";
constexpr auto timescale_unit_ex1_str    = R"(ns)";
constexpr auto timescale_ex1_str        = R"((TIMESCALE     1ns))";
constexpr auto temperature_ex1_str       = R"((TEMPERATURE :25:))";


auto constexpr sdf_header_str_ex_arr = std::array{
R"###(
  (SDFVERSION "4.0")
  (DESIGN "system")
  (DATE "Saturday September 30 08:30:33 PST 1990")
  (VENDOR "Yosemite Semiconductor")
  (PROGRAM "delay_calc")
  (VERSION "1.5")
  (DIVIDER /)
  (VOLTAGE 5.5:5.0:4.5)
  (PROCESS "worst")
  (TEMPERATURE 55:85:125)
  (TIMESCALE 1ns))###",
R"###(
  (SDFVERSION "4.0")
  (DESIGN "top")
  (DATE "Feb 21, 1992 11:30:10")
  (VENDOR "Cool New Tools")
  (PROGRAM "Delay Obfuscator")
  (VERSION "v1.0")
  (DIVIDER .)
  (VOLTAGE :5:)
  (PROCESS "typical")
  (TEMPERATURE :25:)
  (TIMESCALE 1ns))###",
R"###(
  (SDFVERSION "4.0")
  (DESIGN "top")
  (DATE "Nov 25, 1991 17:25:18")
  (VENDOR "Slick Trick Systems")
  (PROGRAM "Viability Tester")
  (VERSION "v3.0")
  (DIVIDER .)
  (VOLTAGE :5:)
  (PROCESS "typical")
  (TEMPERATURE :25:)
  (TIMESCALE 1ns)
  )###",
R"###(
  (SDFVERSION "4.0")
  (DESIGN "testchip")
  (DATE "Dec 17, 1991 14:49:48")
  (VENDOR "Big Chips Inc.")
  (PROGRAM "Chip Analyzer")
  (VERSION "1.3b")
  (TEMPERATURE : 37:)
  (TIMESCALE 10ps ) 
)###"};


}
}
}

#endif //LIBSDF_TEST_SDF_HEADER_H