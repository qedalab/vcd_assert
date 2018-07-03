#include "sdf/serialize/header.hpp"
// #include "sdf/serialize/time_scale.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace SDF;

TEST_CASE("SDF.Serialize.SDFVERSION", "[Serialize]") {
  std::string output;
  SDF::serialize_sdf_version(ranges::back_inserter(output), "my_sdf_version");
  CHECK(output == "(SDFVERSION \"my_sdf_version\" )\n");
}

TEST_CASE("SDF.Serialize.TIMESCALE", "[Serialize]") {
  std::string output;
  SDF::serialize_time_scale(ranges::back_inserter(output),  {TimeNumber::_1, TimeUnit::ns} );
  CHECK(output == "(TIMESCALE 1ns )\n");
}

TEST_CASE("SDF.Serialize.DESIGN", "[Serialize]") {
  std::string output;
  SDF::serialize_design(ranges::back_inserter(output), "my_design");
  CHECK(output == "(DESIGN \"my_design\" )\n");
}

TEST_CASE("SDF.Serialize.DATE", "[Serialize]") {
  std::string output;
  SDF::serialize_date(ranges::back_inserter(output), "my_date");
  CHECK(output == "(DATE \"my_date\" )\n");
}

TEST_CASE("SDF.Serialize.VENDOR", "[Serialize]") {
  std::string output;
  SDF::serialize_vendor(ranges::back_inserter(output), "my_vendor");
  CHECK(output == "(VENDOR \"my_vendor\" )\n");
}

TEST_CASE("SDF.Serialize.PROGRAM", "[Serialize]") {
  std::string output;
  SDF::serialize_program(ranges::back_inserter(output), "my_program");
  CHECK(output == "(PROGRAM \"my_program\" )\n");
}

TEST_CASE("SDF.Serialize.VERSION", "[Serialize]") {
  std::string output;
  SDF::serialize_program_version(ranges::back_inserter(output), "my_program_version");
  CHECK(output == "(VERSION \"my_program_version\" )\n");
}

TEST_CASE("SDF.Serialize.DIVIDER", "[Serialize]") {
  std::string output;
  SDF::serialize_divider(ranges::back_inserter(output), "my_divider");
  CHECK(output == "(DIVIDER \"my_divider\" )\n");
}

TEST_CASE("SDF.Serialize.VOLTAGE", "[Serialize]") {
  std::string output;
  SDF::serialize_voltage(ranges::back_inserter(output), "my_voltage");
  CHECK(output == "(VOLTAGE \"my_voltage\" )\n");
}

TEST_CASE("SDF.Serialize.PROCESS", "[Serialize]") {
  std::string output;
  SDF::serialize_process(ranges::back_inserter(output), "my_process");
  CHECK(output == "(PROCESS \"my_process\" )\n");
}

TEST_CASE("SDF.Serialize.TEMPERATURE", "[Serialize]") {
  std::string output;
  SDF::serialize_temperature(ranges::back_inserter(output), {1,1,1});
  CHECK(output == "(TEMPERATURE 1:1:1 )\n");
}