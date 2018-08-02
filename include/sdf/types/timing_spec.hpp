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

#ifndef LIBSDF_TYPES_TIMINGSPEC_HPP
#define LIBSDF_TYPES_TIMINGSPEC_HPP

#include "./enums.hpp"
#include "./timing_check.hpp"

#include <parse/util/dependent_value.hpp>

#include <type_traits>

namespace SDF {
 
namespace Unsupported{
  struct TimingDelaySpec{};
  struct TimingEnvSpec{};
  struct TimingLabelSpec{};
} // namespace Unsupported

// clang-format off
using TimingSpecVariant = std::variant<
  Unsupported::TimingDelaySpec,
  TimingCheckSpec,
  Unsupported::TimingEnvSpec,
  Unsupported::TimingLabelSpec
>;
// clang-format on

struct TimingSpec {
  TimingSpecVariant value;

  TimingSpecType get_enum_type() const {
    return std::visit([](auto&& param) -> TimingSpecType {
      using T = typename std::decay<decltype(param)>::type;
      if constexpr (std::is_same_v<T, Unsupported::TimingDelaySpec>) {
          return TimingSpecType::delay;
      } else if constexpr (std::is_same_v<T, TimingCheckSpec>) {
          return TimingSpecType::timing_check;
      } else if constexpr (std::is_same_v<T, Unsupported::TimingEnvSpec>) {
          return TimingSpecType::timing_env;
      } else if constexpr (std::is_same_v<T, Unsupported::TimingLabelSpec>) {
          return TimingSpecType::label;
      } else {
          static_assert(Parse::Util::dependent_value<false, T>);
      }
    }, value);
  }
};

} // namespace SDF


#endif // LIBSDF_TYPES_TIMINGSPEC_HPP
