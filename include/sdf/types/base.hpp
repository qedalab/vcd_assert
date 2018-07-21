#ifndef LIBSDF_TYPES_BASE_HPP
#define LIBSDF_TYPES_BASE_HPP

#include <sdf/types/enums.hpp>

#include <fmt/format.h>
#include <fmt/printf.h>
#include <range/v3/algorithm/equal.hpp>

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
};

} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP
