#ifndef PARSE_GRAMMAR_PART_H_
#define PARSE_GRAMMAR_PART_H_

#include "./base.h"

namespace Parse {
namespace Grammar {

struct sign : one<'-', '+'> {
  static constexpr auto error() { return "Expected sign value"; }
};

struct non_zero : range<'1', '9'> {
  static constexpr auto error() { return "Excepted non-zero value"; }
};

struct digit : range<'0', '9'> {
  static constexpr auto error() { return "Excepted digit"; }
};

struct int_part : sor<seq<non_zero, star<digit>>, string<'0'>> {
  static constexpr auto error() { return "Expected integer part"; }
};

struct whitespace : one<' ', '\t'> {
  static constexpr auto error() { return "Expected whitespace"; }
};

struct plus_whitespace : plus<whitespace> {
  static constexpr auto error() { return "Expected at least one whitespace"; }
};

struct star_whitespace : star<whitespace> {
  static constexpr auto error() {
    return "Internal error: Failed parsing StarWhitespace";
  }
};

struct line_end : seq<star_whitespace, eolf> {
  static constexpr auto error() { return "Expected line ending"; }
};

struct imaginary_unit : one<'i', 'j'> {
  static constexpr auto error() {
    return R"(Expected imaginary unit: 'i' or 'j')";
  }
};

} // namespace Grammar
} // namespace Parse

#endif // PARSE_GRAMMAR_PART_H_
