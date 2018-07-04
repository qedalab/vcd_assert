#include <sdf/types/base.hpp>

// #include <cassert>

// using namespace SDF;

// bool HierarchicalIdentifier::operator==(const HierarchicalIdentifier& other) const noexcept{
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