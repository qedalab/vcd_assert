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

#ifndef LIBVERILOG_IEEE1364_2001_TYPES_BASE_HPP
#define LIBVERILOG_IEEE1364_2001_TYPES_BASE_HPP

#include "enums.hpp"

#include <fmt/format.h>
#include <fmt/printf.h>
#include <range/v3/algorithm/equal.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace Verilog {

struct Star {
  bool operator==(const Star & /*unused*/) const noexcept { return true; }
};

using Identifier = std::string;
using IdentifierArray = std::vector<Identifier>;

// struct HierarchicalIdentifier : IdentifierArray{
//   using IdentifierArray::IdentifierArray;
//   HChar sep;
//   bool operator==(const HierarchicalIdentifier& other) const noexcept{
//     const HierarchicalIdentifier& t = *this; <<<<<
// };

struct HierarchicalIdentifier {
  HChar sep{}; // should maybe make global/design to hold this?
  std::vector<Identifier> value = {}; // should make this contiguous?

  bool operator==(const HierarchicalIdentifier &other) const noexcept
  {
    return ranges::equal(value, other.value);
  }
};

} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_TYPES_BASE_HPP
