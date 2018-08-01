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

#ifndef LIBSDF_GRAMMAR_CONDITIONS_HPP 
#define LIBSDF_GRAMMAR_CONDITIONS_HPP 

#include <sdf/grammar/base.hpp>
#include <sdf/grammar/constants.hpp>
#include <sdf/grammar/operators.hpp>
#include <sdf/grammar/timing.hpp>


namespace SDF {
namespace Grammar {
// clang-format off

// forward
struct simple_expression;
struct concat_expression;
struct timing_check_condition;
struct scalar_node;

// extern
struct scalar_port;
struct scalar_net;
struct port;


struct conditional_port_expr : sor<
  simple_expression,
  op_sep_seq<
    one<'('>, opt<unary_operator>, conditional_port_expr, one<')'>
  >,
  seq< conditional_port_expr, binary_operator, conditional_port_expr >
>{};

struct simple_expression : sor<
  op_sep_seq<
    one<'('>, opt<unary_operator>, simple_expression, one<')'>
  >,
  op_sep_seq<
    opt<unary_operator>,
    port
  >,
  op_sep_seq<
    opt<unary_operator>, 
    scalar_constant
  >,
  op_sep_seq< 
    simple_expression,
    one< '?'>,
    simple_expression,
    one< ':'>,
    simple_expression
  >,
  star< 
    op_sep_seq< 
      simple_expression,
      star< 
        simple_expression,
        opt< concat_expression >
      >
    >
  >
>{};

struct concat_expression : op_sep_seq<
  one< ',' >,
  simple_expression
>{};

struct inversion_condition : seq< 
  inversion_operator, 
  scalar_node
>{};

struct node_constant_equality_condition : seq< 
  scalar_node, 
  equality_operator, 
  scalar_constant
>{};

struct timing_check_condition : sor<
  inversion_condition,
  node_constant_equality_condition,
  scalar_node
>{};


// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_CONDITIONS_HPP 
