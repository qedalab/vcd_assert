#ifndef PARSE_UTIL_NAME_INDEX_MAP_HPP
#define PARSE_UTIL_NAME_INDEX_MAP_HPP

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>

namespace Parse {

class NameIndexMap {
public:
  using index_t = std::size_t;

  index_t get_index(std::string &name);
  bool has_index(index_t index) noexcept;

  std::string_view get_name(index_t index);
  bool has_name(std::string &index) noexcept;

  index_t add_name(std::string name);
  index_t add_new_name(std::string name);

  index_t num_elements() noexcept;
private:

  // Unordered map can't search with string_view (C++17)
  // SSO in std::string can invalidate string_view so use string
  std::unordered_map<std::string, index_t> index_lookup_;

  // Store view of the strings in the map
  // Map elements don't invalidate
  std::vector<std::string> names_;
};

}

#endif //PARSE_UTIL_NAME_INDEX_MAP_HPP
