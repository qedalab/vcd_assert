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

#ifndef LIBVCD_GRAMMAR_VALUE_HPP
#define LIBVCD_GRAMMAR_VALUE_HPP

#include "./base.hpp"
#include "./numbers.hpp"

#include <parse/grammar/base.h>
#include <parse/grammar/part.h>
#include <parse/grammar/marker.hpp>

namespace VCD::Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

struct scalar_value_change : seq<
  Parse::Grammar::marker,
  value,
  identifier_code,
  command_separator
> {};

/// Used binary_value instead of binary_number
///   binary_number has a 'b' inside it and there is clearly not
///   a double 'b' in the VCD examples
struct binary_value_change : seq<
  Parse::Grammar::marker,
  one<'b','B'>,
  must<
    binary_value,
    plus_blank,
    identifier_code,
    command_separator
  >
> {};

/// TODO: investigate if real_number is correct since binary_number
///       was not.
struct real_value_change : seq<
  Parse::Grammar::marker,
  one<'r','R'>,
  must<
    real_number,
    plus_blank,
    identifier_code,
    command_separator
  >
> {};

struct vector_value_change : sor<
  binary_value_change,
  real_value_change
> {};

struct value_change : sor<
  vector_value_change,
  scalar_value_change
> {};

// clang-format on

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_VALUE_HPP
