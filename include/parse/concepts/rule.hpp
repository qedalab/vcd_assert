// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBPARSE_CONCEPTS_RULE_HPP
#define LIBPARSE_CONCEPTS_RULE_HPP

#include "./complex_rule.hpp"
#include "./simple_rule.hpp"

#include <range/v3/utility/concepts.hpp>

namespace Parse::Concepts {

namespace Internal {

using namespace ranges::concepts;

struct Rule {
  // clang-format off

  // SimpleRule and not ComplexRule
  template <typename T>
  auto requires_() -> decltype(valid_expr(
      is_false(models<ComplexRule,T>{}),
      is_true(models<SimpleRule, T>{})
  ));

  // ComplexRule and not SimpleRule
  template <typename T>
  auto requires_() -> decltype(valid_expr(
      is_true(models<ComplexRule,T>{}),
      is_false(models<SimpleRule, T>{})
  ));

  // clang-format on
};

} // namespace Internal

template <typename T>
constexpr bool Rule = ranges::concepts::models<Internal::Rule, T>();

} // namespace Parse::Concepts

#endif // LIBPARSE_CONCEPTS_RULE_HPP
