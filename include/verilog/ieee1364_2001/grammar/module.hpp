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

#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP

#include "./attribute.hpp"
#include "./base.hpp"
#include "./block.hpp"
#include "./commands.hpp"
#include "./data.hpp"
#include "./function.hpp"
#include "./identifiers.hpp"
#include "./keywords.hpp"
#include "./net.hpp"
#include "./ports.hpp"
#include "./primitive.hpp"
#include "./statements.hpp"
#include "./task.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;
 

struct param_assignment : opt_sep_seq<
 parameter_identifier, one<'='>, constant_expression
> {};

struct list_of_param_assignments : list<param_assignment, one<','>, plus_sep> {};

struct parameter_declaration : sor<
  opt_sep_seq<
    parameter_keyword, 
    one<'['>, signed_keyword, one<']'>, 
    one<'['>, range, one<']'>, 
    list_of_param_assignments
  >,
  opt_sep_seq<
    parameter_keyword, 
    integer_keyword,
    list_of_param_assignments
  >,
  opt_sep_seq<
    parameter_keyword, 
    real_keyword,
    list_of_param_assignments
  >,
  opt_sep_seq<
    parameter_keyword, 
    realtime_keyword,
    list_of_param_assignments
  >,
  opt_sep_seq<
    parameter_keyword, 
    time_keyword,
    list_of_param_assignments
  >
> {};

/* module_parameter_port_list ::= # ( parameter_declaration { , parameter_declaration } ) */
struct module_parameter_port_list : seq<
  seq<one<'#'>, one<'('>>,
  list< 
    parameter_declaration, 
    one<','>,
    opt<plus_sep>
  >,
  one<')'>
> {};


// struct net_declaration : seq<
//   net_keyword,
//   until<one<';'>>
// > {};
// struct reg_declaration : seq<
//   reg_keyword,
//   until<one<';'>>
// > {};
// struct integer_declaration : seq<
//   integer_keyword,
//   until<one<';'>>
// > {};
// struct real_declaration : seq<
//   real_keyword,
//   until<one<';'>>
// > {};
// struct time_declaration : seq<
//   time_keyword,
//   until<one<';'>>
// > {};
// struct realtime_declaration : seq<
//   realtime_keyword,
//   until<one<';'>>
// > {};
// struct event_declaration : seq<
//   event_keyword,
//   until<one<';'>>
// > {};
// struct genvar_declaration : seq<
//   genvar_keyword,
//   until<one<';'>>
// > {};
// struct task_declaration : seq<
//   task_keyword,
//   until<one<';'>>
// > {};
// struct function_declaration : seq<
//   function_keyword,
//   until<one<';'>>
// > {};



struct name_of_instance : opt_sep_seq < 
  module_instance_identifier, 
  opt<
    bus_range
  >
> {};

struct list_of_port_connections;

struct ordered_port_connection : seq<
  star<attribute_instance>,  opt<expression>
> {};

struct named_port_connection : seq<
 star<attribute_instance>, one<'.'>, one<'('>, opt<expression> , one<')'>
> {};

struct list_of_port_connections : sor< 
  seq< ordered_port_connection, star<one<','>, ordered_port_connection>>, 
  seq< named_port_connection, star<one<','>, named_port_connection>>
> {};

struct module_instance : seq<
  name_of_instance, one<'('>, opt<list_of_port_connections>, one<')'>
> {};

struct ordered_parameter_assignment : alias<expression> {};

struct named_parameter_assignment :  seq<
  one<'.'>, 
  parameter_identifier, 
  opt_sep_seq<one<'('>, opt<expression>, one<')'>>
> {};

struct list_of_parameter_assignments : sor<
  seq<
    ordered_parameter_assignment, 
    star<one<','>, ordered_parameter_assignment>
  >,
  seq<
    named_parameter_assignment, 
    star<one<','>, named_parameter_assignment>
  > 
> {};

struct parameter_value_assignment : if_must<
  seq<one<'#'>, one<'('>>,
  list_of_parameter_assignments,
  one<')'>
> {};

struct module_instantiation : seq<
  module_identifier,
  opt< parameter_value_assignment>,
  plus_blank,
  opt<plus_sep>,
  list<module_instance, one<','>, plus_sep>,
  one<';'>
> {};

// struct initial_block : seq< //causes parse errors when if_must
//   initial_keyword,
//   tao::pegtl::if_must_else<
//     seq<plus_sep,begin_keyword>,
//     seq<
//       star<
//         tao::pegtl::until<
//           sor<
//             sdf_annotate_task,
//             unimplemented_begin_end
//           >,
//           seq<not_at<sdf_annotate_task>, tao::pegtl::any>
//         >
//       >,
//       // tao::pegtl::until<end_keyword, seq<not_at<sdf_annotate_task>, tao::pegtl::any>>//infinite compile 
//       // tao::pegtl::until<end_keyword, not_at<initial_keyword>>
//       tao::pegtl::until<end_keyword>
//     >,
//     statement
//   >
// > {};

// struct initial_construct : alias<initial_block> {};

// struct module_or_generate_item : seq<
//   star<attribute_instance>, 
//   sor<
//     module_or_generate_item_declaration,
//     module_instantiation,
//     initial_construct,
//     // udp_instantiation,
//     until<one<';'>>
//     // star<
//     //   not_at<
//     //     sor<
//     //       module_or_generate_item_declaration,
//     //       module_instantiation,
//     //       initial_construct
//     //     >
//     //   >,
//     //   tao::pegtl::any
//     // >
//     // until<
//     //   at<one<';'>, 
//     //   seq<
//     //     not_at<
//     //       sor<
//     //         module_or_generate_item_declaration,
//     //         module_instantiation,
//     //         initial_construct
//     //       >
//     //     >,
//     //     tao::pegtl::any
//     //   >
//     // >
//     // parameter_override,
//     // continuous_assign,
//     // gate_instantiation,
//     // always_construct
//   >
// > {};

struct module_or_generate_item_declaration : sor< 
  net_declaration,
  reg_declaration,
  integer_declaration,
  real_declaration,
  time_declaration,
  realtime_declaration,
  event_declaration,
  genvar_declaration,
  task_declaration,
  function_declaration
> {};

struct parameter_override : opt_sep_seq<
  defparam_keyword, 
  blank, 
  list_of_param_assignments, 
  one<';'>
> {};

struct initial_key                  : TAO_PEGTL_STRING("initial"){};

struct initial_construct : sep_seq<initial_key, statement> {};
struct always_construct : sep_seq<always_keyword, statement> {};

// struct gate_instantiation_hack : 

struct module_or_generate_item : opt_sep_seq<
  star<attribute_instance>, 
  sor<
    module_or_generate_item_declaration,
    parameter_override,
    continuous_assign,
    gate_instantiation,
    // udp_instantiation,
    module_instantiation,
    initial_construct,
    always_construct
  >
> {};

// struct module_item : sor<
//   module_or_generate_item, 
//   opt_sep_seq<port_declaration, one<';'>>,
//   opt_sep_seq<
//     star<attribute_instance>, 
//     sor<
//       generated_instantiation,
//       local_parameter_declaration,
//       parameter_declaration,
//       specify_block,
//       specparam_declaration
//     >
//   >
// > {};

struct generated_instantiation : if_must<
  generate_keyword, 
  /*star<generate_item>,*/ 
  tao::pegtl::until<at<endgenerate_keyword>, not_at<generate_keyword>>,
  endgenerate_keyword
> {};

struct local_parameter_declaration : if_must<
  localparam_keyword, 
  opt_sep_seq<
    sor<
      seq<opt<signed_keyword>, opt<bus_range>>,
      integer,
      real_keyword,
      realtime_keyword,
      time_keyword
    >,
    list_of_param_assignments
  >,
  one<';'>
> {};

struct specify_block : if_must< 
  specify_keyword, 
  tao::pegtl::until<
    at<endspecify_keyword>, 
    tao::pegtl::not_at<specify_keyword>, 
    tao::pegtl::any
  >, 
  endspecify_keyword
> {};

struct specparam_declaration : if_must<
  specparam_keyword, opt_sep_seq<opt<bus_range>, until<one<';'>>>
> {};


struct module_item : sor<
  module_or_generate_item,
  seq<port_declaration, one<';'>>,
  seq<
    star<attribute_instance>, 
    sor<
      // generated_instantiation,
      local_parameter_declaration,
      parameter_declaration,
      specify_block,
      specparam_declaration
    >
  >
> {};

struct module_declaration : if_must<
  seq<
    star<attribute_instance>,
    module_keyword
  >,
  plus_blank,
  opt_sep_seq<
    module_identifier,
    opt<module_parameter_port_list>,
    opt<list_of_ports>,
    one<';'>,
    star<module_item>
  >,
  endmodule_keyword
> {};


// struct module_declaration : if_must<
//   seq<
//     star<attribute_instance>,
//     module_keyword
//   >,
//   plus_blank,
//   module_identifier,
//   until<one<';'>>,
//   opt<plus_sep>,
//   star<module_item>,

//   star<
//     tao::pegtl::until<
//       sor<
//         initial_block,
//         module_instantiation
//       >//,
//       // seq<not_at<initial_block, module_instantiation>, tao::pegtl::any>
//     >
//   >,
//   // until<endmodule_keyword>
//   tao::pegtl::until<
//     endmodule_keyword, 
//     must<
//       not_at<endmodule_keyword>, 
//       tao::pegtl::any>
//     >
// > {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_MODULE_HPP
