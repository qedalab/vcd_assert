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

#ifndef LIBSDF_GRAMMAR_TIME_SCALE_HPP
#define LIBSDF_GRAMMAR_TIME_SCALE_HPP

#include "../types/time_scale.hpp"
#include "./block.hpp"
#include "./keywords.hpp"

namespace SDF::Grammar {

// clang-format off
struct timescale_number_1 : sor<
    TAO_PEGTL_ISTRING( "1.0" ),
    TAO_PEGTL_ISTRING( "1" )
> {
  static constexpr auto value = TimeScaleNumber::_1;
};

struct timescale_number_10 : sor<
    TAO_PEGTL_ISTRING( "10.0" ),
    TAO_PEGTL_ISTRING( "10" )
> {
  static constexpr auto value = TimeScaleNumber::_10;
};

struct timescale_number_100 : sor<
    TAO_PEGTL_ISTRING( "100.0" ),
    TAO_PEGTL_ISTRING( "100" )
> {
  static constexpr auto value = TimeScaleNumber::_100;
};

struct timescale_number : sor< 
    timescale_number_100,
    timescale_number_10,
    timescale_number_1
> {};

struct timescale_unit_fs : TAO_PEGTL_ISTRING("fs") {
  static constexpr auto value = TimeScaleUnit::fs;
};

struct timescale_unit_ps : TAO_PEGTL_ISTRING("ps") {
  static constexpr auto value = TimeScaleUnit::ps;
};

struct timescale_unit_ns : TAO_PEGTL_ISTRING("ns") {
  static constexpr auto value = TimeScaleUnit::ns;
};

struct timescale_unit_us : TAO_PEGTL_ISTRING("us") {
  static constexpr auto value = TimeScaleUnit::us;
};

struct timescale_unit_ms : TAO_PEGTL_ISTRING("ms") {
  static constexpr auto value = TimeScaleUnit::ms;
};

struct timescale_unit_s : TAO_PEGTL_ISTRING("s") {
  static constexpr auto value = TimeScaleUnit::s;
};

struct timescale_unit : sor< 
    timescale_unit_fs,
    timescale_unit_ps,
    timescale_unit_ns,
    timescale_unit_us,
    timescale_unit_ms,
    timescale_unit_s
> {};

struct timescale : block< 
  key_timescale,
  timescale_number,
  timescale_unit
> {};
// clang-format on

} // namespace SDF::Grammar

#endif // LIBSDF_GRAMMAR_TIME_SCALE_HPP
