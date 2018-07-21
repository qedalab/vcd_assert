#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_HPP

#include "./separator.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

// Incomplete type !?
// template <typename T, typename... P>
// struct block : delimited_seq < opt<separator>,
//   one<'('>,
//   T,
//   delimited_must<opt<separator>,
//     seq<>, // required for weird template parameter pack rule
//     P...,
//     one<')'>
//   >
// > {};

struct open : seq <
  opt<separator>,
  one< '(' >,
  opt<separator>
> {};

struct close : seq <
  opt<separator>,
  one< ')' >,
  opt<separator>
> {};

template<typename T, typename... P>
struct block: if_must<
  seq< open, T >,
  seq< opt< separator >, P >...,
  close
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_BLOCK_HPP
