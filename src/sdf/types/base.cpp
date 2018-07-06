#include <sdf/types/base.hpp>

#include <cassert>

using namespace SDF;
using namespace ranges;

bool HierarchicalIdentifier::operator==(const HierarchicalIdentifier& other) const noexcept{
  if(value.size() == other.value.size()){
    if(value.size() == 0){
      return true;
    }else{
      view::zip_with(
        [](auto s0, auto s1) -> bool { 
          if(!s0.compare(s1)) {
            return false;
          };
        },
        value, other.value 
      );        
      return true;
    }
  }else{
    return false;
  }
}