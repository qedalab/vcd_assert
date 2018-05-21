#ifndef LIBVCD_GRAMMAR_KEYWORDS_H_
#define LIBVCD_GRAMMAR_KEYWORDS_H_

#include "../enums.h"
#include "parse/grammar/base.h"

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

/// Keywords
// auto comment_keyword = "$comment"_str;
struct comment_keyword : string<'$','c','o','m','m','e','n','t'> {};
struct date_keyword : string<'$','d','a','t','e'> {};
struct dumpall_keyword : string<'$','d','u','m','p','a','l','l'> {};
struct dumpoff_keyword : string<'$','d','u','m','p','o','f','f'> {};
struct dumpon_keyword : string<'$','d','u','m','p','o','n'> {};
struct dumpvars_keyword : string<'$','d','u','m','p','v','a','r','s'> {};
struct end_keyword : string<'$','e','n','d'> {};
struct end_definitions_keyword
  : string<'$','e','n','d','d','e','f','i','n','i','t','i','o','n','s'> {};
struct scope_keyword : string<'$','s','c','o','p','e'> {};
struct timescale_keyword : string<'$','t','i','m','e','s','c','a','l','e'> {};
struct upscope_keyword : string<'$','u','p','s','c','o','p','e'> {};
struct var_keyword : string<'$','v','a','r'> {};
struct version_keyword : string<'$','v','e','r','s','i','o','n'> {};

// auto simulation_command_keyword = sor(dumpall_keyword, dumpoff_keyword,...);
struct simulation_command_keyword : sor<
  dumpall_keyword, dumpoff_keyword, dumpon_keyword, dumpvars_keyword
> {};

// clang-format on

} // namespace Grammer
} // namespace VCD

#endif // LIBVCD_GRAMMER_ENUMS_H_
