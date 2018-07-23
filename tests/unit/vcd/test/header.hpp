#ifndef UNIT_LIBVCD_TEST_HEADER_HPP
#define UNIT_LIBVCD_TEST_HEADER_HPP

#include "vcd/test/header.hpp"
#include "vcd/types/header.hpp"

namespace VCD::Test {

void catch_test_header(const VCD::Header &header, TestHeader &test);

} // namespace VCD

#endif // LIBCD_TEST_HEADER_HPP
