#ifndef PARSE_TEST_ERROR_H_
#define PARSE_TEST_ERROR_H_

#include "parse/internal/detected.h"

namespace Parse {
namespace Test {

template<class Rule>
using member_static_fun_error_t = decltype(Rule::error());

template<class Rule>
constexpr bool has_member_static_fun_error =
  Parse::Internal::is_detected<member_static_fun_error_t, Rule>;

}
}

#endif //PARSE_TEST_ERROR_H_
