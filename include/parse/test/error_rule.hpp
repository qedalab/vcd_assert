#ifndef LIBPARSE_TEST_ERROR_RULE_HPP
#define LIBPARSE_TEST_ERROR_RULE_HPP

#include "../concepts/error_rule.hpp"
#include <string>

template <class Rule>
bool is_valid_error_rule() {
  if constexpr (!Parse::Concepts::ErrorRule<Rule>)
    return false;
  
  std::string error = std::string(Rule::error());

  return !error.empty();
}

#endif // LIBPARSE_TEST_ERROR_RULE_HPP
