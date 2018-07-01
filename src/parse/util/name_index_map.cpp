#include "parse/util/name_index_map.hpp"

#include <cassert>

using namespace Parse::Util;

auto NameIndexMap::get_index(std::string &name) const -> index_t
{
  assert(has_name(name));
  return index_lookup_.at(name);
}

bool NameIndexMap::has_index(index_t index) const noexcept
{
  return names_.size() > index;
}

std::string_view NameIndexMap::get_name(index_t index) const
{
  assert(has_index(index));
  return names_.at(index);
}

bool NameIndexMap::has_name(std::string &name) const noexcept
{
  return index_lookup_.count(name) != 0;
}

auto NameIndexMap::num_elements() const noexcept -> index_t
{
  return names_.size();
}

auto NameIndexMap::add_name(std::string name) -> index_t
{
  if(auto it = index_lookup_.find(name); it != index_lookup_.end()) {
    return it->second;
  }

  auto new_index = num_elements();
  index_lookup_[name] = new_index;
  names_.emplace_back(std::move(name));
  return new_index;
}

auto NameIndexMap::add_new_name(std::string name) -> index_t
{
  assert(!has_name(name));

  auto new_index = num_elements();
  index_lookup_[name] = new_index;
  names_.emplace_back(std::move(name));
  return new_index;
}
