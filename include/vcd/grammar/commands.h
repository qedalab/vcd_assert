#ifndef LIBVCD_GRAMMAR_COMMANDS_H_
#define LIBVCD_GRAMMAR_COMMANDS_H_

#include "../enums.h"

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

struct comment_command : seq<
  comment_keyword,
  plus<blank>,
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

struct date_command : seq<
  date_keyword,
  plus<blank>,
  must<date_end>
> {};

struct end_definitions_command : seq<
  end_definitions_keyword,
  plus<blank>,
  must<end_command>
> {};

struct scope_command : seq<
  scope_keyword,
  plus<blank>,
  must<
    scope_type,
    plus<blank>,
    scope_identifier,
    plus<blank>,
    end_command
  >
> {};

struct timescale_command : seq<
  timescale_keyword,
  plus<blank>,
  must<
    time_number,
    plus<blank>,
    time_unit,
    plus<blank>,
    end_command
  >
> {};

struct upscope_command : seq<
  upscope_keyword,
  plus<blank>,
  must<end_command>
> {};

struct var_command : seq<
  var_keyword,
  plus<blank>,
  must<
    var_type,
    plus_blank,
    size,
    plus_blank,
    identifier_code,
    reference,
    plus_blank,
    end_command
  >
> {};

struct version_end: until<blank_end_command> {
  static constexpr auto error() { return "Unterminated version end"; }
};

struct version_command : seq<
  version_keyword,
  plus<blank>,
  until<end_command>
> {};


// clang-format on

} // namespace Grammer
} // namespace VCD

#endif // LIBVCD_GRAMMER_ENUMS_H_
