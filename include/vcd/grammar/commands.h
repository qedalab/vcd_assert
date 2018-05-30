#ifndef LIBVCD_GRAMMAR_COMMANDS_H_
#define LIBVCD_GRAMMAR_COMMANDS_H_

#include "../types/enums.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>

#include "./keywords.h"
#include "./enums/scope_type.h"
#include "./enums/time.h"
#include "./enums/var_type.h"
#include "./base.h"
#include "./value.h"

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

// clang-format off


// TODO move into own header
struct bit_select_index : decimal_number {};
struct msb_index : decimal_number {};
struct lsb_index : decimal_number {};

struct reference_bit_select : seq<one<'['>, bit_select_index, one<']'>> {};
struct reference_msb_lsb_select : seq<one<'['>, msb_index, one<':'>, lsb_index, one<']'>> {};

struct reference : seq< identifier, sor<
  reference_bit_select,
  reference_msb_lsb_select,
  seq<>
>> {};
// end move into own header

struct scope_identifier : identifier {};

struct end_command : seq<end_keyword, command_separator> {};
struct blank_end_command : seq<blank, end_command> {};

struct comment_end : until<blank_end_command> {
  static constexpr auto error() { return "Unterminated comment command"; }
};

struct comment_command : delimited_seq<plus<blank>,
  comment_keyword,
  must<comment_end>
> {};

struct dump_end : end_command {
  static constexpr auto error() { return "Expected \'$end\' or value change"; }
};

template<class DumpRule>
struct dump_command : seq<
  DumpRule,
  plus_blank,
  star<value_change>,
  must<dump_end>
> {};

struct dumpall_command : dump_command<dumpall_keyword> {};
struct dumpon_command : dump_command<dumpon_keyword> {};
struct dumpoff_command : dump_command<dumpoff_keyword> {};
struct dumpvars_command : dump_command<dumpvars_keyword> {};

struct date_end : until<blank_end_command> {
  static constexpr auto error() { return "Unterminated date command"; }
};

struct date_command : delimited_seq<plus_blank,
  date_keyword,
  must<date_end>
> {};

struct end_definitions_command : delimited_seq<plus_blank,
  end_definitions_keyword,
  must<end_command>
> {};

struct scope_command : delimited_seq<plus_blank,
  scope_keyword,
  delimited_must<plus_blank,
    scope_type,
    scope_identifier,
    end_command
  >
> {};

struct timescale_command : delimited_seq<plus_blank,
  timescale_keyword,
  must<
    time_number,
    plus<blank>,
    time_unit,
    plus<blank>,
    end_command
  >
> {};

struct upscope_command : delimited_seq<plus_blank,
  upscope_keyword,
  must<end_command>
> {};

struct var_command : delimited_seq<plus_blank,
  var_keyword,
  delimited_must<plus<blank>,
    var_type,
    size,
    must<
        identifier_code,
        reference>,
    end_command
  >
> {};

struct version_end: until<blank_end_command> {
  static constexpr auto error() { return "Unterminated version end"; }
};

struct version_command : delimited_seq<plus_blank,
  version_keyword,
  until<end_command>
> {};


// clang-format on

} // namespace Grammar
} // namespace VCD

#endif // LIBVCD_GRAMMAR_ENUMS_H_
