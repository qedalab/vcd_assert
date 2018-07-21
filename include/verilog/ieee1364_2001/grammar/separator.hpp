#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./comment.hpp"

namespace Verilog {
namespace IEEE1364_2001 {
namespace Grammar {
// clang-format off

using namespace Parse::Grammar::Base;
using namespace Parse::Grammar::Part;

struct separator : plus<
  sor<
    comment,
    plus<blank>
  >
> {};

// clang-format on
} // namespace Grammar
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_SEPARATOR_HPP
