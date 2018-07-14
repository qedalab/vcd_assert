#include "vcd/test/header.hpp"

using namespace VCD::Test;

void VCD::Test::read_in_test_header(VCD::HeaderReader &reader, TestHeader &test)
{
  if (test.time_scale) {
    auto ts = test.time_scale.value();
    reader.timescale(ts.get_number(), ts.get_unit());
  }

  if (test.date) {
    auto d = test.date.value();
    reader.date(d);
  }

  if (test.version) {
    auto v = test.version.value();
    reader.version(v);
  }

  if (test.root_scope)
    read_in_test_scope(reader, test.root_scope.value());
}
