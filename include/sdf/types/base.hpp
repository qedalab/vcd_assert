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

#ifndef LIBSDF_TYPES_BASE_HPP
#define LIBSDF_TYPES_BASE_HPP

#include <sdf/types/enums.hpp>

#include <fmt/format.h>
#include <fmt/printf.h>
#include <range/v3/algorithm/equal.hpp>
#include <range/v3/algorithm/copy.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace SDF {
 
struct Star {
  bool operator==(const Star& /*unused*/) const noexcept{
    return true;
  }
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
  HChar sep {}; //should maybe make global/header to hold this?
  std::vector<Identifier> value = {}; //should make this contiguous?
  
  bool operator==(const HierarchicalIdentifier& other) const noexcept{
    return ranges::equal(value, other.value);
  }

  std::string to_string() const {
    std::string output;
    auto sep_str = sep == HChar::dot ? std::string_view(".") : std::string_view("/");
    auto size =  value.size();
    for(auto&& section : value){
      --size;
      ranges::copy(section, ranges::back_inserter(output));
      if(size > 0)
        ranges::copy(sep_str, ranges::back_inserter(output));    
    }
    // serialize_hierarchical_identifier(ranges::back_inserter(output), 0, value);
    return output;
  }
};

} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP
