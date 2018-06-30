#include "vcd/serialize/enums.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Enums", "[Serialize]") {
  SECTION("TimeUnit") {
    CHECK(time_unit_to_string(TimeUnit::s) == "s");
    CHECK(time_unit_to_string(TimeUnit::ms) == "ms");
    CHECK(time_unit_to_string(TimeUnit::us) == "us");
    CHECK(time_unit_to_string(TimeUnit::ns) == "ns");
    CHECK(time_unit_to_string(TimeUnit::ps) == "ps");
    CHECK(time_unit_to_string(TimeUnit::fs) == "fs");
  }

  SECTION("TimeNumber") {
    CHECK(time_number_to_string(TimeNumber::_1) == "1");
    CHECK(time_number_to_string(TimeNumber::_10) == "10");
    CHECK(time_number_to_string(TimeNumber::_100) == "100");
  }

  SECTION("ScopeType") {
    CHECK(scope_type_to_string(ScopeType::module) == "module");
    CHECK(scope_type_to_string(ScopeType::task) == "task");
    CHECK(scope_type_to_string(ScopeType::begin) == "begin");
    CHECK(scope_type_to_string(ScopeType::fork) == "fork");
    CHECK(scope_type_to_string(ScopeType::function) == "function");
  }

  SECTION("VarType") {
    CHECK(var_type_to_string(VarType::event) == "event");
    CHECK(var_type_to_string(VarType::integer) == "integer");
    CHECK(var_type_to_string(VarType::parameter) == "parameter");
    CHECK(var_type_to_string(VarType::real) == "real");
    CHECK(var_type_to_string(VarType::realtime) == "realtime");
    CHECK(var_type_to_string(VarType::reg) == "reg");
    CHECK(var_type_to_string(VarType::supply0) == "supply0");
    CHECK(var_type_to_string(VarType::supply1) == "supply1");
    CHECK(var_type_to_string(VarType::time) == "time");
    CHECK(var_type_to_string(VarType::tri) == "tri");
    CHECK(var_type_to_string(VarType::triand) == "triand");
    CHECK(var_type_to_string(VarType::trior) == "trior");
    CHECK(var_type_to_string(VarType::trireg) == "trireg");
    CHECK(var_type_to_string(VarType::tri0) == "tri0");
    CHECK(var_type_to_string(VarType::tri1) == "tri1");
    CHECK(var_type_to_string(VarType::wand) == "wand");
    CHECK(var_type_to_string(VarType::wire) == "wire");
    CHECK(var_type_to_string(VarType::wor) == "wor");
  }

  SECTION("ValueChar") {
    CHECK(value_to_char(Value::one) == '1');
    CHECK(value_to_char(Value::zero) == '0');
    CHECK(value_to_char(Value::z) == 'Z');
    CHECK(value_to_char(Value::x) == 'X');
  }

  SECTION("ValueString") {
    CHECK(value_to_string(Value::one) == "1");
    CHECK(value_to_string(Value::zero) == "0");
    CHECK(value_to_string(Value::z) == "Z");
    CHECK(value_to_string(Value::x) == "X");
  }
}

