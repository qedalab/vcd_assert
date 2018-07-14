#include "vcd/test/scope.hpp"

#include "vcd/test/variable.hpp"
#include "vcd/types/header_reader.hpp"

using namespace VCD::Test;

void VCD::Test::read_in_test_scope(VCD::HeaderReader &reader, TestScope &test)
{
  reader.scope(test.type, test.identifier);

  for (auto &scope : test.scopes) {
    read_in_test_scope(reader, scope);
  }

  for (auto &var : test.variables) {
    read_in_test_var(reader, var);
  }

  reader.upscope();
}
