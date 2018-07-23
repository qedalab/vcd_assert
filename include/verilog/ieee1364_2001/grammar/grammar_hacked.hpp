
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

struct module_item_hack : sor<
  op_sep_ignored,
  until<eol>
> {};

struct module_identifier : alias<identifier> {};

struct module_declaration_hack : if_must<
  until< module_keyword >,
  plus_blank,
  module_identifier,
  until<endmodule_keyword>,
  opt<separator>
> {};


struct description_hack : seq<
  module_declaration_hack //,
  // udp_declaration
> {};

/* The top-level grammar allows one or more desciptions 
   block and then expects eof. */
struct source_text_hack : seq<
  list< description_hack, opt<separator> >
> {};


struct grammar_hack : must<
  opt<separator>,
  source_text_hack,
  opt<separator>  
  // opt<eof>
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_GRAMMAR_HPP
