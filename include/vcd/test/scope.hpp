#ifndef LIBVCD_TEST_SCOPE_HPP
#define LIBVCD_TEST_SCOPE_HPP

#include "./variable.hpp"
#include "vcd/types/enums.hpp"

namespace VCD::Test {

struct TestScope {
  ScopeType type;
  std::string identifier;

  std::vector<TestScope> scopes;
  std::vector<TestVar> variables;
};

void read_in_test_scope(VCD::HeaderReader &reader, TestScope &test);
void catch_test_scope(VCD::Header &header, VCD::Scope &scope, TestScope &test);

} // namespace VCD::Test

#endif // TEST_VCD_TYPES_SCOPE_HPP
