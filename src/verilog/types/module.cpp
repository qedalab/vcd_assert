#include "verilog/types/module.hpp"

#include <cassert>

using namespace Verilog;

std::optional<TimeScale> Attributes::get_time_scale() const noexcept
{
  return time_scale_;
}

bool Attributes::has_time_scale() const noexcept
{
  return time_scale_.has_value();
}

