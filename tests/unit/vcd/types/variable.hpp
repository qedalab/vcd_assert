#ifndef TEST_VCD_TYPES_VARIABLE_HPP
#define TEST_VCD_TYPES_VARIABLE_HPP

#include "vcd/types/enums.hpp"
#include "vcd/types/header.hpp"
#include "vcd/types/scope.hpp"

namespace VCD::Test {

struct TestVar {
  VarType type;
  std::size_t size;
  std::string id_code;
  std::string ref;
};

void read_in_test_var(VCD::HeaderReader &reader, TestVar &test);
void catch_test_var(VCD::Header &header, VCD::Scope &scope,
                            VCD::Variable &variable, TestVar test);

}

#endif // TEST_VCD_TYPES_VARIABLE_HPP
