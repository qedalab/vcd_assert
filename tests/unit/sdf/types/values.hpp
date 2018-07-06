#ifndef TEST_SDF_TYPES_VALUES_HPP
#define TEST_SDF_TYPES_VALUES_HPP

#include <sdf/types/values.hpp>

namespace SDF::Test {

static const Triple test_triple_1{
  0.0, 0.5, 1
};

static const Triple test_triple_2{
  1, 1, 1
};

static const Triple test_triple_3{
  1.0, 2.0, 3.0
};

static const Triple test_triple_4{
  1, 2, 3
};

static const Number test_number{
  0.5
};

static const Number test_number_1{
  1.5
};

static const Number test_number_2{
  10.5
};

static const Number test_number_3{
  .5
};

static const Number test_number_4{
  4
};

static const Value test_number_value_1{
  Number{test_number_1}
};

static const Value test_number_value_2{
  Number{test_number_2}
};

static const Value test_number_value_3{
  Number{test_number_3}
};

static const Value test_number_value_4{
  Number{test_number_4}
};

static const Value test_triple_value_1{
  Triple{test_triple_1.min, test_triple_1.typ, test_triple_1.max}
};

static const Value test_triple_value_2{
  Triple{test_triple_2.min, test_triple_2.typ, test_triple_2.max}
};

static const Value test_triple_value_3{
  Triple{test_triple_3.min, test_triple_3.typ, test_triple_3.max}
};

static const Value test_triple_value_4{
  Triple{test_triple_4.min, test_triple_4.typ, test_triple_4.max}
};

// void read_in_test_timing(SDF::DelayFileReader &reader, TestCell &test);
// void catch_test_timing(SDF::DelayFile &header, SDF::Cell &scope, TestCell &test);

} // SDF::Test

#endif // TEST_SDF_TYPES_VALUES_HPP
