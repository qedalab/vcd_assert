#ifndef UNIT_LIBVCD_TEST_SCOPE_HPP
#define UNIT_LIBVCD_TEST_SCOPE_HPP

#include "vcd/test/scope.hpp"
#include "vcd/types/scope.hpp"

namespace VCD::Test {

void catch_test_scope(VCD::Header &header, VCD::Scope &scope, TestScope &test);

} // namespace VCD

#endif // UNIT_LIBCD_TEST_SCOPE_HPP
