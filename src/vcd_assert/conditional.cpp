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

#include "vcd_assert/conditional.hpp"

using namespace VCDAssert;

// clang-format off
VCD::Value ConditionalValuePointer::value() const noexcept {
  return std::visit([](auto&& value) -> VCD::Value {
    using T = typename std::decay<decltype(value)>::type;

    if constexpr (std::is_same_v<T, VCD::Value>) {
      return value;
    } else if constexpr (std::is_same_v<T, VCD::Value*>) {
      return *value;
    } else {
      return value->call();
    }
  }, value_);
}

// clang-format on

ConditionalValuePointer::ConditionalValuePointer(
    ConditionalValuePointer &&other)
{
  value_ = std::move(other.value_);
}

ConditionalValuePointer &ConditionalValuePointer::
operator=(ConditionalValuePointer &&other)
{
  value_ = std::move(other.value_);
  return *this;
}

ConditionalValuePointer::~ConditionalValuePointer() = default;

const ConditionalValuePointerVariant& ConditionalValuePointer::inner() const noexcept {
  return value_;
}
