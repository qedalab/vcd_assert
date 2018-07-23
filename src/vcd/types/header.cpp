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
