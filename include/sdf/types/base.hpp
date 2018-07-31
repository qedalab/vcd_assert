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
