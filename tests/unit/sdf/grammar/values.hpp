#ifndef LIBSDF_TEST_SDF_VALUES_H
#define LIBSDF_TEST_SDF_VALUES_H


#include "base.hpp"
#include <sdf/grammar/values.hpp>

namespace Test {
namespace SDF {
namespace Grammar {

using namespace Parse::Test;
using namespace SDF::Grammar;

constexpr auto small_pos_exp_str = "e1";
constexpr auto small_neg_exp_str = "e-1";
constexpr auto large_pos_exp_str = "e100";
constexpr auto large_neg_exp_str = "e-100";

constexpr auto unsigned_int_number = "1234";
constexpr auto signed_int_number = "+1234";

constexpr auto single_number_unsigned_float_1 = "1.1234";
constexpr auto single_number_unsigned_float_2 = "1.1234e1";
constexpr auto single_number_unsigned_float_3 = "1.1234e-1";
constexpr auto single_number_unsigned_float_4 = "123.1234";
constexpr auto single_number_unsigned_float_5 = "123.1234e1";
constexpr auto single_number_unsigned_float_6 = "123.1234e-1";
constexpr auto single_number_unsigned_float_7 = ".1234";
constexpr auto single_number_unsigned_float_8 = ".1234e1";
constexpr auto single_number_unsigned_float_9 = ".1234e-1";

constexpr auto single_number_inverted_float_1 = "-1.1234";
constexpr auto single_number_inverted_float_2 = "-1.1234e1";
constexpr auto single_number_inverted_float_3 = "-1.1234e-1";
constexpr auto single_number_inverted_float_4 = "-123.1234";
constexpr auto single_number_inverted_float_5 = "-123.1234e1";
constexpr auto single_number_inverted_float_6 = "-123.1234e-1";
constexpr auto single_number_inverted_float_7 = "-.1234";
constexpr auto single_number_inverted_float_8 = "-.1234e1";
constexpr auto single_number_inverted_float_9 = "-.1234e-1";

constexpr auto empty_triple = " :: ";

constexpr auto triple_number_int_full = "1:1:1";
constexpr auto triple_number_int_single_1 = "1::";
constexpr auto triple_number_int_single_2 = ":1:";
constexpr auto triple_number_int_single_3 = "::1";
constexpr auto triple_number_int_dual_1 = "1:1:";
constexpr auto triple_number_int_dual_2 = "1::1";
constexpr auto triple_number_int_dual_3 = ":1:1";

constexpr auto triple_number_float_full_1 = "1.1:1.3:1.2";
constexpr auto triple_number_float_full_2 = "1.1e1:1.3:1.2";
constexpr auto triple_number_float_full_3 = "1.1e1:1.3e22:1.2e-13";
constexpr auto triple_number_float_full_4 = "1.111123:-1.332:1.2e123";

constexpr auto triple_number_float_single_1_1 = "1.4::";
constexpr auto triple_number_float_single_1_2 = "1.4e12::";
constexpr auto triple_number_float_single_1_3 = "1.4e-2::";
constexpr auto triple_number_float_single_1_4 = ".4e-2::";
constexpr auto triple_number_float_single_1_5 = "-1.4e-2::";

constexpr auto triple_number_float_single_2_1 = ":1.123:";
constexpr auto triple_number_float_single_2_2 = ":1.123e6:";
constexpr auto triple_number_float_single_2_3 = ":1.123e-6:";
constexpr auto triple_number_float_single_2_4 = ":-1.123e-6:";
constexpr auto triple_number_float_single_2_5 = ":.123e-6:";
constexpr auto triple_number_float_single_2_6 = ":-.123e-6:";

constexpr auto triple_number_float_single_3_1 = "::1.633";
constexpr auto triple_number_float_single_3_2 = "::1.6e123";
constexpr auto triple_number_float_single_3_3 = "::.6e123";
constexpr auto triple_number_float_single_3_4 = "::1.6e123";

constexpr auto triple_number_float_dual_1_1 = "1.7:1.8:";
constexpr auto triple_number_float_dual_1_2 = "1.7e1:1.8e-1:";
constexpr auto triple_number_float_dual_1_3 = ".7e1:.8e-1:";
constexpr auto triple_number_float_dual_1_4 = "-1.7:1.8:";
constexpr auto triple_number_float_dual_1_5 = "-1.7:-1.8:";


constexpr auto triple_number_float_dual_2_1 = ".9::.10";
constexpr auto triple_number_float_dual_2_2 = "1.9::1.10";
constexpr auto triple_number_float_dual_2_3 = "1.9e0::1.10e12";
constexpr auto triple_number_float_dual_2_4 = "1.9::-1.10";
constexpr auto triple_number_float_dual_2_5 = "-1.9::-1.10";

constexpr auto triple_number_float_dual_3_1 = ":.11e11:1.12";
constexpr auto triple_number_float_dual_3_2 = ":.11e11:1.12e-1";
constexpr auto triple_number_float_dual_3_3 = ":-.11e11:1.12e-1";
constexpr auto triple_number_float_dual_3_4 = ":-.11e11:-1.12e-1";





// auto constexpr triples_keywords = 
//   std::array{

//   };

// auto constexpr rtriples_int = 
//   std::array{

//   };

// auto constexpr rtriples = 
//   std::array{

//   };


// constexpr auto triple_number = "1::1"
// constexpr auto triple_number = "1::1"
// constexpr auto triple_number = ":1:"
// constexpr auto triple_number = "+1:-1:+1"
// constexpr auto triple_number = ":+1:+1"
// constexpr auto triple_number = ""
// constexpr auto triple_number = ""
// constexpr auto define_triple = ""
// constexpr auto triple = ""
// constexpr auto rtriple = ""
// constexpr auto define_value = ""
// constexpr auto value = ""
// constexpr auto rvalue = ""
// constexpr auto delval = ""
// constexpr auto retval_list = ""
// constexpr auto delval_list = ""


}
}
}

#endif //LIBSDF_TEST_SDF_VALUES_H