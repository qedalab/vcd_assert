#ifndef LIBSDF_TYPES_BASE_HPP
#define LIBSDF_TYPES_BASE_HPP

#include <sdf/types/enums.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <range/v3/view/zip.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>

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
  HChar sep; //should maybe make global/header to hold this?
  std::vector<Identifier> value; //should make this contiguous?
  
  bool operator==(const HierarchicalIdentifier& other) const noexcept{
    if(value.size() == other.value.size()){
      if(value.size() == 0){
        return true;
      }else{
        for(auto&& [s0,s1] : ranges::view::zip( value, other.value)){
          if(!s0.compare(s1)) {
              return false;
          };
        }
        return true;
      }
    }else{
      return false;
    }
  }
};

} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP

