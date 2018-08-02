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

#ifndef LIBSDF_TYPES_VALUES_HPP
#define LIBSDF_TYPES_VALUES_HPP

#include <sdf/types/enums.hpp>
// #include <sdf/types/base.hpp>
#include <array>
#include <variant>
#include <optional>

namespace SDF {

// struct Number {
//   double value;
//   bool operator==(const Number& t) const noexcept{
//     return value == t.value;
//   }
// };

// using NumberValue = double;
using Number = std::optional<double>;

// struct Number : NumberValue{
//   bool operator==(const Number& t) const noexcept{
//     return value == t.value;
//   }
// };

// // choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  Number min;
  Number typ;
  Number max;
  int places = 0;

  bool operator==(const Triple &t) const noexcept {
    return ((min == t.min) && (typ == t.typ) && (max == t.max));
  }
};
using ValueVariant = std::variant<Triple, Number>;

struct Value : public ValueVariant {
  using ValueVariant::ValueVariant;

  bool operator==(const Value &other) const noexcept {
    if (std::holds_alternative<Triple>(*this) &&
        std::holds_alternative<Triple>(other)) {
      return (std::get<Triple>(*this) == std::get<Triple>(other));
    } else if (std::holds_alternative<Number>(*this) &&
               std::holds_alternative<Number>(other)) {
      return (std::get<Number>(*this) == std::get<Number>(other));
    } else {
      return false;
    }
  }

  std::optional<double> content(MinTypMax proc = MinTypMax::unspecified) const noexcept;

};

} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_HPP
