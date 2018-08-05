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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP

#include "./base.hpp"
#include "./constants.hpp"
#include "./expressions.hpp"
#include "./identifiers.hpp"
#include "./operators.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include <tao/pegtl.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct net_type : sor<
  supply0_keyword,
  supply1_keyword,
  tri_keyword,
  triand_keyword,
  trior_keyword,
  tri0_keyword,
  tri1_keyword,
  wire_keyword,
  wand_keyword,
  wor_keyword
> {};

struct output_variable_type : sor<
  integer_keyword, 
  time_keyword
> {};

struct real_type : sor<
seq<real_identifier, opt< one<'='>, constant_expression >>,
seq<real_identifier, list<dimension, one<','>, plus_sep>>
> {};

struct list_of_real_identifiers : list<real_type, one<','>, plus_sep> {};


struct variable_type : sor<
seq<variable_identifier, opt< one<'='>, constant_expression >>,
seq<variable_identifier, list<dimension, one<','>, plus_sep>>
> {};

struct list_of_variable_identifiers : list<variable_type, one<','>, plus_sep> {};


struct strength0 : sor<supply0_keyword, strong0_keyword, pull0_keyword, weak0_keyword> {};
struct strength1 : sor<supply1_keyword, strong1_keyword, pull1_keyword, weak1_keyword> {};

struct drive_strength_value : sor<
  strength0,
  strength1,
  highz0_keyword,
  highz1_keyword
> {};

struct drive_strength_0 : alias<drive_strength_value> {};
struct drive_strength_1 : alias<drive_strength_value> {};

struct drive_strength : sor<
  one<'('>, drive_strength_0 , drive_strength_1, one<')'>
> {};

struct charge_strength : sor<
  opt_sep_seq<one<'('>, small_keyword, one<')'>>, 
  opt_sep_seq<one<'('>, medium_keyword, one<')'>>, 
  opt_sep_seq<one<'('>, large_keyword, one<')'>>
> {};

struct delay_value : sor<
  unsigned_number, 
  real_number, 
  parameter_identifier, 
  specparam_identifier, 
  mintypmax_expression
> {};

struct delay2 : opt_sep_seq<
  one<'#'>, 
  one<'('>, 
  delay_value, 
  opt< 
    one<','>, 
    delay_value 
  >, 
  one<')'>
> {};

struct delay3 : opt_sep_seq<
  one<'#'>, 
  one<'('>, 
  delay_value,
  opt< 
    one<','>, 
    delay_value, 
    opt< 
      one<','>, 
      delay_value>
      >, 
  one<')'>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_DATA_HPP
