
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP

// #include <verilog/ieeel1364_2005/grammar/source_text.hpp>
// #include "./source_text.hpp"
// #include "./attribute.hpp"
#include "./base.hpp"
#include "./keywords.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

struct ignored;

struct ignored_content : 
  sor<
    qstring,
    plus<character>,
    plus_blank,
    // hierarchical_identifier,
    special_character_without_brackets,
    ignored
> {};

struct ignored : seq<
  star<ignored_content>
> {};

struct op_sep_ignored : plus<
  opt<sps>,
  tao::pegtl::list<ignored,opt<sps>>
> {};

struct unimplemented : if_must<
  open,
  star<ignored>,
  star<ignored_content>,
  star<ignored>,
  until<close>
> {};

struct unimplemented_brackets : if_must<
  seq<open>,
  star<bracket_contents>,
  star<bracket_pairs>,
  star<bracket_contents>,
  until<close>
> {};

// struct _module_item_ : sor<
//   op_sep_ignored,
//   until<eol>
// > {};


struct net_declaration : seq<
  net_keyword,
  until<one<';'>>
>{};
struct reg_declaration : seq<
  reg_keyword,
  until<one<';'>>
>{};
struct integer_declaration : seq<
  integer_keyword,
  until<one<';'>>
>{};
struct real_declaration : seq<
  real_keyword,
  until<one<';'>>
>{};
struct time_declaration : seq<
  time_keyword,
  until<one<';'>>
>{};
struct realtime_declaration : seq<
  realtime_keyword,
  until<one<';'>>
>{};
struct event_declaration : seq<
  event_keyword,
  until<one<';'>>
>{};
struct genvar_declaration : seq<
  genvar_keyword,
  until<one<';'>>
>{};
struct task_declaration : seq<
  task_keyword,
  until<one<';'>>
>{};
struct function_declaration : seq<
  function_keyword,
  until<one<';'>>
>{};

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

struct module_instance_identifier : alias<identifier>{};

struct fake_bus_range : seq<
  one<'['>,
  until<one<']'>>
>{};

struct name_of_instance : seq < 
  module_instance_identifier, 
  opt<fake_bus_range>
>{};

struct module_instance : seq<
  name_of_instance, seq<one<'('>, /*opt<list_of_port_connections>,*/ until<one<')'>>>
>{};

struct module_identifier : alias<identifier> {};

struct module_instantiation : seq<
  // opt< parameter_value_assignment> 
  module_identifier,
  plus_blank,
  // opt<separator>,
  opt< list<module_instance, one<','> > >,
  opt<until<one<';'>>>
> {};


struct _module_declaration_ : seq<
  module_keyword,
  plus_blank,
  module_identifier,
  until<one<';'>>,
  star<module_instantiation>,
    // star<
    //   // until<at<module_identifier>>
    //   until<at<module_instantiation>>,
    //   module_instantiation
    // >,
  // opt<until<at<endmodule_keyword>>>,
  must<until<endmodule_keyword>>,
  opt<separator>
> {};

struct _module_description_ : sor<
  _module_declaration_ //,
  // udp_declaration
> {};

struct _include_statement_ : seq< 
  include_keyword,
  sor<
    seq<
      one<'<'>, 
      file_path_spec, 
      one<'>'>
    >,
    seq<
      one<'"'>, 
      file_path_spec, 
      one<'"'>
    >
  >
>{};


struct compiler_directive : sor<
  // _library_declaration_,
  _include_statement_
  // _config_declaration_
> {};

struct _grammar_ : must<
  list<
    opt<separator>,
    sor<
      until<seq<one<'`'>,compiler_directive>>,
      until<_module_description_>
    >
  >
  // opt<eof>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
