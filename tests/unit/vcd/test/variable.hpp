#ifndef UNIT_LIBVCD_TEST_VARIABLE_HPP
#define UNIT_LIBVCD_TEST_VARIABLE_HPP

#include "vcd/test/variable.hpp"
#include "vcd/types/variable.hpp"

namespace VCD::Test {

void catch_test_var(VCD::Header &header,
                    VCD::Variable &variable, TestVar test);

} // namespace VCD

#endif // UNIT_LIBCD_TEST_HEADER_HPP
