#ifndef LIBVCD_GRAMMAR_BASE_H
#define LIBVCD_GRAMMAR_BASE_H

#include "parse/grammar/base.h"
#include "parse/grammar/part.h"

#include "./enums/value.h"
#include "./keywords.h"

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

struct blank : one<' ', '\n', '\r', '\t', '\v', '\f'> {};
struct plus_blank : plus<blank> {
  static constexpr auto error() { return "Expected whitespace"; }
};

struct command_separator : sor<
  eof,
  plus<blank>
> {};

struct printable_ascii_except_whitespace : range<33,126> {};

struct identifier_code : until<command_separator> {};

struct simple_identifier : seq<
  sor<
    range<'a','z'>,
    range<'A','Z'>,
    one<'_'>
  >,
  star<sor<
    range<'a','z'>,
    range<'A','Z'>,
    range<'0','9'>,
    one<'_','$'>
  >>
> {};

struct escaped_identifier : seq<
  one<'\\'>,
  plus<printable_ascii_except_whitespace>,
  must<blank>
> {};


struct identifier : sor<
  escaped_identifier,
  simple_identifier
> {};

}
}

#endif // VCD_GRAMMAR_BASE_H
