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

#include "vcd/types/header.hpp"

#include <cassert>
#include <vcd/types/header_reader.hpp>

using namespace VCD;

std::optional<TimeScale> Header::get_time_scale() const noexcept
{
  return time_scale_;
}

bool Header::has_time_scale() const noexcept { return time_scale_.has_value(); }

std::optional<std::string_view> Header::get_date() const noexcept
{
  return date_;
}

bool Header::has_date() const noexcept { return date_.has_value(); }

std::optional<std::string_view> Header::get_version() const noexcept
{
  return version_;
}

bool Header::has_version() const noexcept { return version_.has_value(); }

const Variable &Header::get_var(std::size_t index) const
{
  assert(variables_.size() > index);
  return variables_.at(index);
}

const Scope &Header::get_scope(std::size_t index) const
{
  assert(scopes_.size() > index);
  return scopes_.at(index);
}

const Scope &Header::get_root_scope() const
{
  assert(!scopes_.empty());
  return scopes_.at(0);
}

std::size_t Header::get_var_id_code_index(std::string &id_code) const
{
  assert(has_var_id_code(id_code));
  return var_id_code_map_.get_index(id_code);
}

const VarIdCode &Header::get_var_id_code(std::size_t index) const
{
  assert(index < num_id_codes());
  return id_codes_.at(index);
}

bool Header::has_var_id_code(std::string &id_code) const noexcept
{
  return var_id_code_map_.has_name(id_code);
}

std::size_t Header::num_scopes() const noexcept { return scopes_.size(); }

std::size_t Header::num_variables() const noexcept { return variables_.size(); }

std::size_t Header::num_id_codes() const noexcept { return id_codes_.size(); }


