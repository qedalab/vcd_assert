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

#ifndef LIBSDF_SERIALIZE_TIMINGSPEC_HPP
#define LIBSDF_SERIALIZE_TIMINGSPEC_HPP

#include <sdf/types/timing_spec.hpp>

#include <sdf/serialize/base.hpp>
#include <sdf/serialize/timing_check.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {


/// Serialize SDF timing spec
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The SDF file timing specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_spec(OutputIterator oi, int indent,
                     TimingSpec ts) noexcept(noexcept(*oi++ = '!')) {
  //only timing checks supported at the moment.
  assert(ts.get_enum_type() == TimingSpecType::timing_check);
  serialize_indent(oi, indent);

  switch (ts.get_enum_type()) {
    case TimingSpecType::delay:
      throw std::runtime_error("InternalError : Delays Unimplemented");  
      ranges::copy(std::string_view("(DELAY \n"), oi);
      // serialize_delay_spec(oi, indent + 1, ts);
      break;
    case TimingSpecType::timing_check:
      ranges::copy(std::string_view("(TIMINGCHECK \n"), oi);
      serialize_timing_check_spec(oi, indent + 1, std::get<TimingCheckSpec>(ts.value));
      break;
    case TimingSpecType::timing_env:
      throw std::runtime_error("InternalError : TimingEnvs Unimplemented");  
      ranges::copy(std::string_view("(TIMINGENV \n"), oi);
      // serialize_timing_env_spec(oi, indent + 1, ts);
      break;
    case TimingSpecType::label:
      throw std::runtime_error("InternalError : Labels Unimplemented");  
      ranges::copy(std::string_view("(LABEL \n"), oi);
      // serialize_timing_label_spec(oi, indent + 1, ts);
      break;
    default:
      throw std::runtime_error("InternalError");
    }

  serialize_indent(oi, indent);
  ranges::copy(std::string_view(")\n"), oi);

}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_TIMINGSPEC_HPP

