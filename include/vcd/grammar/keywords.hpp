// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBVCD_GRAMMAR_KEYWORDS_HPP
#define LIBVCD_GRAMMAR_KEYWORDS_HPP

#include "../types/enums.hpp"
#include "parse/grammar/base.h"

namespace VCD::Grammar {

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

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_KEYWORDS_HPP
