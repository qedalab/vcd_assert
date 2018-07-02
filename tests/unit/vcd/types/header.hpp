#ifndef TEST_VCD_TYPES_HEADER_HPP
#define TEST_VCD_TYPES_HEADER_HPP

#include "./scope.hpp"

#include "vcd/types/enums.hpp"
#include "vcd/types/header_reader.hpp"

namespace VCD::Test {

struct TestHeader {
  std::optional<VCD::TimeScale> time_scale;
  std::optional<std::string> date;
  std::optional<std::string> version;

  std::optional<TestScope> root_scope;
};

void read_in_test_header(VCD::HeaderReader &reader, TestHeader &test);
void catch_test_header(VCD::Header &header, TestHeader &test);

} // namespace VCD::Test

#endif // TEST_VCD_TYPES_HEADER_HPP
