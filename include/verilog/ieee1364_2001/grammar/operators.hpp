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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_OPERATORS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_OPERATORS_HPP

#include "../../types/enums.hpp"
#include <parse/grammar/base.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct case_inequality : string<'!','=','='> {
  static constexpr auto value = EqualityOperator::case_inv;
};

struct case_equality : string<'=','=','='> {
  static constexpr auto value = EqualityOperator::case_equal;
};

struct logical_inequality : string<'!','='> {
  static constexpr auto value = EqualityOperator::logic_inv;
};

struct logical_equality : string<'=','='> {
  static constexpr auto value = EqualityOperator::logic_equal;
};

struct equality_operator : sor<
  case_inequality,
  case_equality,
  logical_inequality,
  logical_equality
> {};

struct logical_negation : one<'!'> {};
struct bitwise_unary_negation : one<'~'> {};

struct inversion_operator : sor<
  logical_negation,
  bitwise_unary_negation
> {};

struct arithmetic_identity : one<'+'> {};
struct arithmetic_negation : one<'-'> {};
struct reduction_unary_and : one<'&'> {};
struct reduction_unary_nand : string<'~','&'> {};
struct reduction_unary_or : one<'|'> {};
struct reduction_unary_nor : string<'~','|'> {};
struct reduction_unary_xor : one<'^'> {};
struct reduction_unary_xnor : string<'^','~'> {};
struct reduction_unary_xnor_alt : string<'~','^'> {};

struct unary_operator : sor<
  reduction_unary_xnor_alt,
  reduction_unary_xnor,
  reduction_unary_xor,
  reduction_unary_nor,
  reduction_unary_or,
  reduction_unary_nand,
  reduction_unary_and,
  inversion_operator,
  arithmetic_negation,
  arithmetic_identity
> {};

struct arithmetic_sum : one<'+'> {};
struct arithmetic_difference : one<'-'> {};
struct arithmetic_product : one<'+'> {};
struct arithmetic_quotient : one<'/'> {};
struct modulus : one<'%'> {};
struct logical_and : string<'&','&'> {};
struct logical_or : string <'|','|'> {};
struct lt_relation : one<'<'> {};
struct lte_relation : string<'<','='> {};
struct gt_relation : one<'>'> {};
struct gte_relation : one<'>','='> {};
struct bitwise_binary_and : one<'&'> {};
struct bitwise_binary_or : one<'|'> {};
struct bitwise_binary_xor : one<'^'> {};
struct bitwise_binary_xnor : string<'^','~'> {};
struct bitwise_binary_xnor_alt : string<'~','^'> {};
struct right_shift : string<'<','<'> {};
struct left_shift : string<'>','>'> {};

struct binary_operator : sor<
  equality_operator,
  left_shift,
  right_shift,
  bitwise_binary_xnor_alt,
  bitwise_binary_xnor,
  logical_and,
  logical_or,
  gte_relation,
  lte_relation,
  gt_relation,
  lt_relation,
  bitwise_binary_and,
  bitwise_binary_or,
  bitwise_binary_xor,
  modulus,
  arithmetic_sum,
  arithmetic_difference,
  arithmetic_product,
  arithmetic_quotient
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace SDF

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_OPERATORS_HPP
