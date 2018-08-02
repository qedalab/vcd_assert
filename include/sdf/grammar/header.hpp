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

#ifndef LIBSDF_GRAMMAR_HEADER_HPP 
#define LIBSDF_GRAMMAR_HEADER_HPP 

#include <sdf/grammar/base.hpp>

#include <sdf/grammar/keywords.hpp>
#include <sdf/grammar/values.hpp>

#include "./time_scale.hpp"

namespace SDF {
namespace Grammar {

// clang-format off

struct sdf_version : block< 
  key_sdfversion,
  qstring
>{};

struct design_name : block< 
  key_design,
  qstring
>{};

struct date : block< 
  key_date,
  qstring
>{};

struct vendor : block< 
  key_vendor,
  qstring
>{};

struct program_name : block< 
  key_program,
  qstring
>{};

struct program_version : block< 
  key_version,
  qstring
>{};

struct hierarchy_divider : block< 
  key_divider,
  hchar
>{};

struct voltage : block< 
  key_voltage,
  sor< rtriple, signed_real_number>
>{};

struct process : block< 
  key_process,
  qstring    
>{};

struct temperature : block<
  key_temperature,
  sor< rtriple, signed_real_number>
>{};


struct sdf_header : op_sep_seq< 
  must<sdf_version>,
  opt<design_name>,
  opt<date>,
  opt<vendor>,
  opt<program_name>,
  opt<program_version>,
  opt<hierarchy_divider>,
  opt<voltage>,
  opt<process>,
  opt<temperature>,
  opt<timescale>
>{};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_HEADER_HPP 

