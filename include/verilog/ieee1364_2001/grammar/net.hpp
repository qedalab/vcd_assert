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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_NET_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_NET_HPP

#include "./assignments.hpp"
#include "./base.hpp"
#include "./keywords.hpp"
#include "./module.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct net_decl_assignment; //in assignments

struct list_of_event_identifiers : list< 
  opt_sep_seq< 
    event_identifier, 
    opt< star<dimension> >
  >,
  one<','>,
  plus_sep
> {};

struct event_declaration : seq< 
  event_keyword, 
  list_of_event_identifiers,
  one<';'>
> {};

struct list_of_genvar_identifiers : list<genvar_identifier, one<','>, plus_sep> {};


struct genvar_declaration : seq< 
  genvar_keyword, 
  list_of_genvar_identifiers,
  one<';'>
> {};

struct integer_declaration : seq< 
  integer_keyword, 
  list_of_variable_identifiers,
  one<';'>
> {};


struct list_of_net_identifiers : list< 
  opt_sep_seq< 
    net_identifier, 
    opt< star<dimension> > 
  >, 
  one<','>, 
  plus_sep 
> {};

struct list_of_net_decl_assignments : list<net_decl_assignment, one<','>, plus_sep> {};


struct scalar_net_net_declaration : sor<
  seq< 
    net_type, 
    opt< signed_keyword > , 
    opt< delay3 >, 
    list_of_net_identifiers, 
    one<';'> 
  >,
  seq< 
    net_type, 
    opt< drive_strength >, 
    opt< signed_keyword >, 
    opt< delay3 >, 
    list_of_net_decl_assignments, 
    one<';'>
  >
> {};

struct ranged_net_net_declaration : sor<
  seq< 
    net_type, 
    sor< vectored_keyword, scalared_keyword >, 
    opt< signed_keyword >, 
    range, 
    opt< delay3 >, 
    list_of_net_identifiers, 
    one<';'>
  >,
  seq< 
    net_type, 
    opt< drive_strength >, 
    sor< vectored_keyword, scalared_keyword >, 
    opt< signed_keyword >, 
    range, 
    opt< delay3 >, 
    list_of_net_decl_assignments, 
    one<';'>
  >
> {};

struct scalar_trireg_net_declaration : sor <
  seq< 
    trireg_keyword, 
    opt< charge_strength >, 
    opt< signed_keyword >, 
    opt< delay3 >, 
    list_of_net_identifiers, 
    one<';'>
  >,
  seq< 
    trireg_keyword, 
    opt< drive_strength >, 
    opt< signed_keyword >, 
    opt< delay3 >,
    list_of_net_decl_assignments, 
    one<';'>
  >
> {};

struct ranged_trireg_net_declaration : sor <
  seq< 
    trireg_keyword, 
    opt< charge_strength >, 
    sor< vectored_keyword, 
    scalared_keyword >,
    opt< signed_keyword >, 
    range, 
    opt< delay3 >, 
    list_of_net_identifiers, 
    one<';'>
  >,
  seq< 
    trireg_keyword, 
    opt< drive_strength >, 
    sor< vectored_keyword, scalared_keyword >, 
    opt< signed_keyword >, 
    range, 
    opt< delay3 >, 
    list_of_net_decl_assignments, 
    one<';'>
  >
> {};

struct net_declaration : sor<
  scalar_net_net_declaration,
  ranged_net_net_declaration,
  scalar_trireg_net_declaration,
  ranged_trireg_net_declaration
> {};

struct real_declaration : seq< 
  real_keyword, 
  list_of_real_identifiers,
  one<';'>
> {};

struct realtime_declaration : seq< 
  realtime_keyword, 
  list_of_real_identifiers, 
  one<';'>
> {};

struct reg_declaration : seq< 
  reg_keyword, 
  opt<signed_keyword>, 
  opt<range>, 
  list_of_variable_identifiers,
  one<';'>
> {};

struct time_declaration : seq< 
  time_keyword, 
  list_of_variable_identifiers, 
  one<';'>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_VARIABLES_HPP
