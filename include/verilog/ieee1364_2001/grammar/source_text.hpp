
#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_SOURCE_TEXT_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_SOURCE_TEXT_HPP

#include "./base.hpp"
#include "./module.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct description : sor<
  module_declaration,
  udp_declaration
> {};

/* The top-level grammar allows one or more desciptions 
   block and then expects eof. */
struct source_text : must<
  star< 
    description
  >, 
  eof
> {};

// clang-format on
} // namespace IEEE1364_2001
} // namespace Grammar
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
