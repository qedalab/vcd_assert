#include "vcd/serialize/variable.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Variable", "[Serialize]") {
  std::string output;
  VCD::serialize_variable(ranges::back_inserter(output), {VarType::reg, 32, "my_id_code", "my_reference"});
  CHECK(output == "$var reg 32 my_id_code my_reference $end\n");
}
