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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_ITEM_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_ITEM_HPP

#include "./base.hpp"
#include "./keywords.hpp"
//#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct block_reg_declaration;
struct event_declaration;
struct integer_declaration;
struct local_parameter_declaration;
struct parameter_declaration;
struct real_declaration;
struct realtime_declaration;
struct time_declaration;

// struct block_variable_type : opt_sep_seq< 
//   variable_identifier, plus<dimension>
// > {};

struct block_variable_type : opt_sep_seq<
  variable_identifier, opt<list< dimension, blank, plus_sep>>
> {};

struct list_of_block_variable_identifiers : list<
  block_variable_type, one<','>, plus_sep
> {};

struct block_reg_declaration : opt_sep_seq<
  reg_keyword, 
  opt<signed_keyword, sep>, 
  opt<range, sep>,
  list_of_block_variable_identifiers, 
  one<';'>
> {};

struct block_item_declaration : seq<
  star<attribute_instance>, 
  sor<
    block_reg_declaration,
    event_declaration,
    integer_declaration,
    local_parameter_declaration,
    parameter_declaration,
    real_declaration,
    realtime_declaration,
    time_declaration
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_ITEM_HPP
