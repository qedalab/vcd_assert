#include "vcd/types/header_reader.hpp"

#include "vcd/test/variable.hpp"

using namespace VCD::Test;

void VCD::Test::read_in_test_var(VCD::HeaderReader &reader, TestVar &test)
{
  reader.var(test.type, test.size, test.id_code, test.ref);
}
