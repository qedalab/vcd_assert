#include <sdf/types/delayfile.hpp>
#include <sdf/serialize/delayfile.hpp>
// #include "sdf/serialize/time_scale.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace SDF;
static const int zero = 0;

TEST_CASE("SDF.Serialize.SDFVERSION", "[Serialize]") {
  std::string output;
  serialize_sdf_version(ranges::back_inserter(output),zero, "my_sdf_version");
  CHECK(output == "(SDFVERSION \"my_sdf_version\")\n");
}

TEST_CASE("SDF.Serialize.TIMESCALE", "[Serialize]") {
  std::string output;
  serialize_timescale(ranges::back_inserter(output),zero,  {TimeScaleNumber::_1, TimeScaleUnit::ns} );
  CHECK(output == "(TIMESCALE 1ns)\n");
}

TEST_CASE("SDF.Serialize.DESIGN", "[Serialize]") {
  std::string output;
  serialize_design_name(ranges::back_inserter(output),zero, "my_design");
  CHECK(output == "(DESIGN \"my_design\")\n");
}

TEST_CASE("SDF.Serialize.DATE", "[Serialize]") {
  std::string output;
  serialize_date(ranges::back_inserter(output),zero, "my_date");
  CHECK(output == "(DATE \"my_date\")\n");
}

TEST_CASE("SDF.Serialize.VENDOR", "[Serialize]") {
  std::string output;
  serialize_vendor(ranges::back_inserter(output),zero, "my_vendor");
  CHECK(output == "(VENDOR \"my_vendor\")\n");
}

TEST_CASE("SDF.Serialize.PROGRAM", "[Serialize]") {
  std::string output;
  serialize_program_name(ranges::back_inserter(output),zero, "my_program");
  CHECK(output == "(PROGRAM \"my_program\")\n");
}

TEST_CASE("SDF.Serialize.VERSION", "[Serialize]") {
  std::string output;
  serialize_program_version(ranges::back_inserter(output),zero, "my_program_version");
  CHECK(output == "(VERSION \"my_program_version\")\n");
}

TEST_CASE("SDF.Serialize.DIVIDER", "[Serialize]") {
  std::string output;
  serialize_hierarchy_divider(ranges::back_inserter(output),zero, HChar::slash);
  CHECK(output == "(DIVIDER /)\n");
}

TEST_CASE("SDF.Serialize.VOLTAGE", "[Serialize]") {
  std::string output;
  serialize_voltage(ranges::back_inserter(output),zero, Triple{5.4,5,4.5});
  CHECK(output == "(VOLTAGE 5.4:5.0:4.5)\n");
}

TEST_CASE("SDF.Serialize.PROCESS", "[Serialize]") {
  std::string output;
  serialize_process(ranges::back_inserter(output),zero, "my_process");
  CHECK(output == "(PROCESS \"my_process\")\n");
}

TEST_CASE("SDF.Serialize.TEMPERATURE", "[Serialize]") {
  std::string output;
  serialize_temperature(ranges::back_inserter(output),zero, Triple{55,85,125});
  CHECK(output == "(TEMPERATURE 55:85:125)\n");
}
