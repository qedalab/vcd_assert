#ifndef LIBSDF_TYPES_BASE_HPP
#define LIBSDF_TYPES_BASE_HPP

#include <sdf/types/enums.hpp>

#include <string>
#include <vector>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/zip_with.hpp>

namespace SDF {
 

struct Star{
  bool operator==(const Star& s) const noexcept{
    return true;
  }
};

struct HierarchicalIdentifier {
  std::vector<std::string> value; //should make this contiguous?
  HChar sep; //should make this contiguous?

  bool operator==(const HierarchicalIdentifier& other) const noexcept;

  // bool operator==(const HierarchicalIdentifier& other) const noexcept{
  //   using namespace ranges;
  //   if(value.size() == other.value.size()){
  //     if(value.size() == 0){
  //       return true;
  //     }else{
  //       view::zip_with(
  //         [](auto s0, auto s1) -> bool { 
  //           if(!s0.compare(s1)) {
  //             return false;
  //           };
  //         },
  //         value, other.value 
  //       );        
  //       return true;
  //     }
  //   }else{
  //     return false;
  //   }
  // }  
};

} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP

