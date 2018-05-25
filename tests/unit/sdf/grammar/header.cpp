#include "./header.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Header", "[SDF][Grammar][Header]") {

  SECTION(fmt::format(
      "Testing \"sdf_version\" header line : \n{}\n",
        sdf_version_ex1_str)) {

      CHECK(match_exactly<sdf_version>(sdf_version_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"design_name\" header line : \n{}\n",
        design_name_ex1_str)) {

      CHECK(match_exactly<design_name>(design_name_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"date\" header line : \n{}\n",
        date_ex1_str)) {

      CHECK(match_exactly<date>(date_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"vendor\" header line : \n{}\n",
        vendor_ex1_str)) {

      CHECK(match_exactly<vendor>(vendor_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"program_name\" header line : \n{}\n",
        program_name_ex1_str)) {

      CHECK(match_exactly<program_name>(program_name_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"program_version\" header line : \n{}\n",
        program_version_ex1_str)) {

      CHECK(match_exactly<program_version>(program_version_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"hierarchy_divider\" header line : \n{}\n",
        hierarchy_divider_ex1_str)) {

      CHECK(match_exactly<hierarchy_divider>(hierarchy_divider_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"voltage\" header line : \n{}\n",
        voltage_ex1_str)) {

      CHECK(match_exactly<voltage>(voltage_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"process\" header line : \n{}\n",
        process_ex1_str)) {

      CHECK(match_exactly<process>(process_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"timescale_number\" header line : \n{}\n",
        timescale_number_ex1_str)) {

      CHECK(match_exactly<timescale_number>(timescale_number_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"timescale_unit\" header line : \n{}\n",
        timescale_unit_ex1_str)) {

      CHECK(match_exactly<timescale_unit>(timescale_unit_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"time_scale\" header line : \n{}\n",
        time_scale_ex1_str)) {

      CHECK(match_exactly<time_scale>(time_scale_ex1_str));
  }
  
  SECTION(fmt::format(
      "Testing \"temperature\" header line : \n{}\n",
        temperature_ex1_str)) {

      CHECK(match_exactly<temperature>(temperature_ex1_str));
  }
  SECTION(fmt::format(
      "Testing \"temperature\" header line : \n{}\n",
        temperature_ex1_str)) {

      CHECK(match_exactly<temperature>(fmt::format("(TEMPERATURE 1:1:1)")));
  }
 
  for(auto&& a : sdf_header_str_ex_arr){ 
    SECTION(fmt::format("Full Header Example : \n\"{}\"\n",a)) {
      CHECK(match_exactly<sdf_header>(fmt::format("{}",a)));
  }
    //   SECTION(fmt::format("Checking : {}",a)){
    //     CHECK(match_exactly<decimal_digit>(a));
    //   }
    }
  

//   SECTION("Decimals") {
//     for(auto&& a : decimal_range_str){ 
//       SECTION(fmt::format("Checking : {}",a)){
//         CHECK(match_exactly<decimal_digit>(fmt::format("{}",a)));
//       }
//     }
//   }
  
}