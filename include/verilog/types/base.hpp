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
