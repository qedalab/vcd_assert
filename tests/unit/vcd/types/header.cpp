#include "vcd/types/header.hpp"

#include "vcd/types/header_reader.hpp"
#include "./header.hpp"
#include "./scope.hpp"

#include <catch.hpp>

using namespace VCD::Test;

void VCD::Test::read_in_test_header(VCD::HeaderReader &reader, TestHeader &test)
{
  if(test.time_scale) {
    auto ts = test.time_scale.value();
    reader.timescale(ts.get_number(), ts.get_unit());
  }

  if(test.date) {
    auto d = test.date.value();
    reader.date(d);
  }

  if(test.version) {
    auto v = test.version.value();
    reader.version(v);
  }

  if(test.root_scope)
    read_in_test_scope(reader, test.root_scope.value());
}

void VCD::Test::catch_test_header(VCD::Header &header, TestHeader &test)
{
  SECTION("TimeScale") {
    if(test.time_scale) {
      auto ts_test = test.time_scale.value();
      CHECK(header.has_time_scale());
      auto ts = header.get_time_scale();
      REQUIRE(ts);
      CHECK(ts.value().get_unit() == ts_test.get_unit());
      CHECK(ts.value().get_number() == ts_test.get_number());
    } else {
      CHECK_FALSE(header.has_time_scale());
      CHECK_FALSE(header.get_time_scale());
    }
  }

  SECTION("Date") {
    if(test.date) {
      auto d_test = test.date.value();
      CHECK(header.has_date());
      auto d = header.get_date();
      REQUIRE(d);
      CHECK(d_test == d.value());
    } else {
      CHECK_FALSE(header.has_date());
      CHECK_FALSE(header.get_date());
    }
  }

  SECTION("Version") {
    if(test.version) {
      auto v_test = test.version.value();
      CHECK(header.has_version());
      auto v = header.get_version();
      REQUIRE(v);
      CHECK(v_test == v.value());
    } else {
      CHECK_FALSE(header.has_version());
      CHECK_FALSE(header.get_version());
    }
  }

  SECTION("Root Scope") {
    if(test.root_scope) {
      REQUIRE(header.num_scopes() > 0);
      catch_test_scope(header, header.get_root_scope(), test.root_scope.value());
    } else {
      CHECK(header.num_scopes() == 0);
    }
  }
}
