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
  HChar sep; 
  std::vector<std::string> value; //should make this contiguous?

  bool operator==(const HierarchicalIdentifier& other) const noexcept;
};

} // namespace SDF

#endif // LIBSDF_TYPES_BASE_HPP

