
#ifndef LIBVERILOG_GRAMMAR_IEEE1364_2001_PORTS_HPP
#define LIBVERILOG_GRAMMAR_IEEE1364_2001_PORTS_HPP

#include "../base.hpp"
#include "./module.hpp"

namespace Verilog {
namespace Grammar {
namespace IEEE1364_2001 {
// clang-format off

 

struct module_keyword sor<
   tao::pegtl::STRING("module"),
   tao::pegtl::STRING("macromodule")
> {}; 

struct endmodule_keyword sor<
   tao::pegtl::STRING("endmodule")
> {}; 

module_parameter_port_list

struct module_identifier : alias<identifier> {};

struct module_declaration : must<
  star<attribute_instance>,
  module_keyword,
  module_identifier,
  opt<module_parameter_port_list>,
  opt<list_of_ports>,
  one<';'>,
  star<module_item>,
  endmodule_keyword
> {};


// clang-format on
} // namespace IEEE1364_2001
} // namespace Grammar
} // namespace Verilog

#endif // LIBVERILOG_GRAMMAR_IEEE1364_2001_PORTS_HPP
