#ifndef LIBVCD_GRAMMAR_GRAMMAR_HPP
#define LIBVCD_GRAMMAR_GRAMMAR_HPP

#include "./base.hpp"
#include "./commands.hpp"
#include "./enums/scope_type.hpp"
#include "./enums/time.hpp"
#include "./enums/value.hpp"
#include "./enums/var_type.hpp"
#include "./keywords.hpp"
#include "./value.hpp"

#include <parse/grammar/base.h>

namespace VCD::Grammar {

using namespace Parse::Grammar;

// clang-format off

struct simulation_time : seq<one<'#'>, decimal_number, command_separator> {};

struct simulation_command : sor<
  dumpall_command,
  dumpoff_command,
  dumpon_command,
  dumpvars_command,
  comment_command,
  simulation_time,
  value_change
> {};

struct declaration_command : sor<
  comment_command,
  date_command,
  scope_command,
  timescale_command,
  upscope_command,
  var_command,
  version_command
> {};

struct header_commands : seq<
  star<declaration_command>,
  end_definitions_command
> {};

struct value_change_dump : seq<
  header_commands,
  star<simulation_command>,
  eof
> {};

// clang-format on

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_GRAMMAR_HPP
