#include "./variable.hpp"

#include <catch2/catch.hpp>

void VCD::Test::catch_test_var(VCD::Header &header,
                               VCD::Variable &variable, TestVar test)
{
  CHECK(variable.get_reference() == test.ref);
  auto id_code_index = variable.get_id_code_index();
  REQUIRE(id_code_index < header.num_id_codes());
  auto &id_code = header.get_var_id_code(id_code_index);
  CHECK(id_code.get_type() == test.type);
  CHECK(id_code.get_size() == test.size);
  CHECK(id_code.get_id_code() == test.id_code);
}
