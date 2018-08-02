#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMENT_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMENT_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;

struct one_line_comment : if_must< 
    two< '/' >, until< eolf > 
> {};

struct block_comment_cont : until< 
  sor< eof, TAO_PEGTL_STRING( "*/" ) > 
> {};

struct block_comment : if_must<
  TAO_PEGTL_STRING( "/*" ), 
  block_comment_cont
> {};

struct comment : sor <
  one_line_comment,
  block_comment
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_COMMENT_HPP
