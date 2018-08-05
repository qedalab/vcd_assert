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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_VARIABLES_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_VARIABLES_HPP

#include "./base.hpp"
#include "./keywords.hpp"
#include "./module.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct integer_declaration : 
  integer_keyword, list_of_variable_identifiers ;
> {};
struct real_declaration : 
  real_keyword, list_of_real_identifiers ;
> {};
struct realtime_declaration : 
  realtime_keyword, list_of_real_identifiers ;
> {};
struct reg_declaration : 
  reg_keyword, opt<signed_keyword>,  opt<range>, list_of_variable_identifiers ;
> {};
struct time_declaration : 
  time list_of_variable_identifiers ;
> {};
struct real_type : 
  real_identifier [ = constant_expression ]
| real_identifier dimension { dimension }
> {};
struct variable_type : 
  variable_identifier [ = constant_expression ]
| variable_identifier dimension { dimension }
> {};
struct list_of_real_identifiers : 
  real_type { , real_type }
> {};
struct list_of_variable_identifiers : 
  variable_type { , variable_type }
> {};
struct dimension : 
  [ dimension_constant_expression : dimension_constant_expression ]
> {};
struct range : 
  [ msb_constant_expression : lsb_constant_expression ]
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_VARIABLES_HPP
