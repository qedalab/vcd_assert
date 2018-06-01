#include "vcd/types/header.hpp"

#include <cassert>

using namespace VCD;

std::optional<TimeScale> VCDHeader::get_time_scale()
{
  return time_scale_;
}

bool VCDHeader::has_time_scale()
{
  return time_scale_.has_value();
}

std::optional<std::string_view> VCDHeader::get_date()
{
  return date_;
}

bool VCDHeader::has_date()
{
  return date_.has_value();
}

std::optional<std::string_view> VCDHeader::get_version()
{
  return version_;
}

bool VCDHeader::has_version()
{
  return version_.has_value();
}

VCDVariable& VCDHeader::get_variable(std::size_t index)
{
  assert(variables_.size() > index);
  return variables_.at(index);
}

VCDScope& VCDHeader::get_scope(std::size_t index)
{
  assert(scopes_.size() > index);
  return scopes_.at(index);
}

VCDScope& VCDHeader::get_root_scope()
{
  assert(!scopes_.empty());
  return scopes_.at(0);
}

std::size_t VCDHeader::get_reference_index(std::string &reference)
{
  assert(has_reference(reference));
  return reference_lookup_.get_index(reference);
}

bool VCDHeader::has_reference(std::string &reference)
{
  return reference_lookup_.has_name(reference);
}

std::size_t VCDHeader::num_scopes()
{
  return scopes_.size();
}

std::size_t VCDHeader::num_variables()
{
  return variables_.size();
}