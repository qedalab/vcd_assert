#include "vcd/serialize/value_change.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.ValueChange", "[Serialize]") {
  SECTION("Scalar") {
    std::string output;
    VCD::serialize_value_change(ranges::back_inserter(output),
                                ScalarValueChangeView{Value::z, "my_id_code"} );
    CHECK(output == "Zmy_id_code\n");
  }

  SECTION("Vector") {
    std::string output;
    Value data[] = {Value::z, Value::x, Value::one, Value::zero};
    VCD::serialize_value_change(ranges::back_inserter(output),
                                VectorValueChangeView{data, "my_id_code"} );
    CHECK(output == "bZX10 my_id_code\n");
  }

  SECTION("Real") {
    std::string output;
    double value = 3.14;
    std::string expected = std::string("r") + std::to_string(value) + std::string(" my_id_code\n");

    VCD::serialize_value_change(ranges::back_inserter(output),
                                RealValueChangeView{value, "my_id_code"} );
    CHECK(output == expected);
  }
}
