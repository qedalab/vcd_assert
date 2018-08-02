// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
  if (auto it = index_lookup_.find(name); it != index_lookup_.end()) {
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
