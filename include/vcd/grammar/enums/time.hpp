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

#ifndef LIBVCD_GRAMMAR_ENUMS_TIME_HPP
#define LIBVCD_GRAMMAR_ENUMS_TIME_HPP

#include "../../types/enums.hpp"

#include <parse/grammar/base.h>

namespace VCD::Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

/// Time units
struct time_s : string<'s'> {
  static constexpr auto value = TimeUnit::s;
};

struct time_ms : string<'m','s'> {
  static constexpr auto value = TimeUnit::ms;
};

struct time_us : string<'u','s'> {
  static constexpr auto value = TimeUnit::us;
};

struct time_ns : string<'n','s'> {
  static constexpr auto value = TimeUnit::ns;
};

struct time_ps : string<'p','s'> {
  static constexpr auto value = TimeUnit::ps;
};

struct time_fs : string<'f','s'> {
  static constexpr auto value = TimeUnit::fs;
};

struct time_unit : sor<time_s, time_ms, time_us, time_ns, time_ps, time_fs> {
  static constexpr auto error() { return "Expected time unit"; }
};

struct time_number : seq<
  one<'1'>,
  opt<
    one<'0'>,
    opt<
      one<'0'>
    >
  >
> {};

// clang-format on

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_ENUMS_TIME_HPP
