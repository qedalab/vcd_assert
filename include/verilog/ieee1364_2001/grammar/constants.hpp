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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP

#include "./attribute.hpp"
#include "./base.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;
// clang-format off


struct scalar_constant_b_prefix : one<'b','B'> {};
struct scalar_constant_1b_prefix : seq<one<'1'>, one<'b','B'>> {};
struct scalar_constant_0 : one<'0'> {};
struct scalar_constant_b0 : seq<scalar_constant_b_prefix, scalar_constant_0> {};
struct scalar_constant_1b0 : seq<scalar_constant_1b_prefix, scalar_constant_0> {};
struct scalar_constant_1 : one<'1'> {};
struct scalar_constant_b1 : seq<scalar_constant_b_prefix, scalar_constant_1> {};
struct scalar_constant_1b1 : seq<scalar_constant_1b_prefix, scalar_constant_1> {};

struct scalar_constant : sor<
  scalar_constant_1b0,
  scalar_constant_1b1,
  scalar_constant_b0,
  scalar_constant_b1,
  scalar_constant_0,
  scalar_constant_1
> {};

struct constant_primary : sor<
  constant_concatenation
  // constant_function_call,
  // op_sep_seq< one<'('>, constant_mintypmax_expression, one<')'>>,
  // constant_multiple_concatenation,
  // genvar_identifier,
  // number,
  // parameter_identifier,
  // specparam_identifier
> {};

struct constant_expression : sor<
  constant_primary,
  op_sep_seq<
    unary_operator, 
    star< attribute_instance >, 
    constant_primary
  >,
  op_sep_seq<
    constant_expression, 
    binary_operator, 
    star<attribute_instance>, 
    constant_expression
  >,
  op_sep_seq<
    constant_expression, 
    one<'?'>, 
    star< attribute_instance >, 
    constant_expression
  >, 
  constant_expression,
  qstring
> {};


// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_CONSTANTS_HPP
