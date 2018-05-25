#ifndef LIBSDF_TEST_SDF_VALUES_H
#define LIBSDF_TEST_SDF_VALUES_H


#include "./base.hpp"
#include <sdf/grammar/values.h>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

constexpr auto small_pos_exp_str = R"(e1)";
constexpr auto small_neg_exp_str = R"(e-1)";
constexpr auto large_pos_exp_str = R"(e100)";
constexpr auto large_neg_exp_str = R"(e-100)";

constexpr auto unsigned_int_triple_number = R"(1234)";
constexpr auto signed_int_triple_number = R"(+1234)";

constexpr auto unsigned_float_triple_number_1 = R"(1.1234)";
constexpr auto unsigned_float_triple_number_2 = R"(1.1234e1)";
constexpr auto unsigned_float_triple_number_3 = R"(1.1234e-1)";
constexpr auto unsigned_float_triple_number_4 = R"(123.1234)";
constexpr auto unsigned_float_triple_number_5 = R"(123.1234e1)";
constexpr auto unsigned_float_triple_number_6 = R"(123.1234e-1)";
constexpr auto unsigned_float_triple_number_7 = R"(.1234)";
constexpr auto unsigned_float_triple_number_8 = R"(.1234e1)";
constexpr auto unsigned_float_triple_number_9 = R"(.1234e-1)";

constexpr auto empty_triple = R"(::)";

constexpr auto triple_number_int_full = R"(1:1:1)";
constexpr auto triple_number_int_single_1 = R"(1::)";
constexpr auto triple_number_int_single_2 = R"(:1:)";
constexpr auto triple_number_int_single_3 = R"(::1)";
constexpr auto triple_number_int_dual_1 = R"(1:1:)";
constexpr auto triple_number_int_dual_2 = R"(1::1)";
constexpr auto triple_number_int_dual_3 = R"(:1:1)";

constexpr auto triple_number_float_full_1 = R"(1.1:1.3:1.2)";
constexpr auto triple_number_float_full_2 = R"(1.1e1:1.3:1.2)";
constexpr auto triple_number_float_full_3 = R"(1.1e1:1.3e22:1.2e-13)";
constexpr auto triple_number_float_full_4 = R"(1.111123:1.332:1.2e123)";

constexpr auto triple_number_float_single_1_1 = R"(1.4::)";
constexpr auto triple_number_float_single_1_2 = R"(1.4e12::)";
constexpr auto triple_number_float_single_1_3 = R"(1.4e-2::)";
constexpr auto triple_number_float_single_1_4 = R"(.4e-2::)"; //<

constexpr auto triple_number_float_single_2_1 = R"(:1.123e6:)";
constexpr auto triple_number_float_single_2_2 = R"(:1.5e-6:)";
constexpr auto triple_number_float_single_2_3 = R"(:.5e-6:)"; //<

constexpr auto triple_number_float_single_3_1 = R"(::1.633)";
constexpr auto triple_number_float_single_3_2 = R"(::1.6e123)";
constexpr auto triple_number_float_single_3_3 = R"(::.6e123)";

constexpr auto triple_number_float_dual_1_1 = R"(1.7:1.8:)";
constexpr auto triple_number_float_dual_1_2 = R"(1.7e1:1.8e-1:)";
constexpr auto triple_number_float_dual_1_3 = R"(.7e1:.8e-1:)";

constexpr auto triple_number_float_dual_2_1 = R"(.9::.10)";
constexpr auto triple_number_float_dual_2_2 = R"(1.9::1.10)";
constexpr auto triple_number_float_dual_2_3 = R"(1.9e0::1.10e12)";

constexpr auto triple_number_float_dual_3_1 = R"(:.11e11:1.12)";
constexpr auto triple_number_float_dual_3_2 = R"(:.11e11:1.12e-1)";





// auto constexpr triples_keywords = 
//   std::array{

//   };

// auto constexpr rtriples_int = 
//   std::array{

//   };

// auto constexpr rtriples = 
//   std::array{

//   };


// constexpr auto triple_number = R"(1::1)";
// constexpr auto triple_number = R"(1::1)";
// constexpr auto triple_number = R"(:1:)";
// constexpr auto triple_number = R"(+1:-1:+1)";
// constexpr auto triple_number = R"(:+1:+1)";
// constexpr auto triple_number = R"()";
// constexpr auto triple_number = R"()";
// constexpr auto define_triple = R"()";
// constexpr auto triple = R"()";
// constexpr auto rtriple = R"()";
// constexpr auto define_value = R"()";
// constexpr auto value = R"()";
// constexpr auto rvalue = R"()";
// constexpr auto delval = R"()";
// constexpr auto retval_list = R"()";
// constexpr auto delval_list = R"()";


}
}
}

#endif //LIBSDF_TEST_SDF_VALUES_H