#include <sdf/types/values.hpp>

#include <cassert>

using namespace SDF;

std::optional<double>
Value::content(MinTypMax proc) const noexcept
{
  Number result;

  if (std::holds_alternative<Triple>(*this)) {
    switch (proc) {
    case MinTypMax::min:
      result = std::get<Triple>(*this).min;
      break;
    case MinTypMax::typ:
    case MinTypMax::unspecified:
      result = std::get<Triple>(*this).typ;
      break;
    case MinTypMax::max:
      result = std::get<Triple>(*this).max;
      break;
    default:
      result = {};
    }
  } else {
    result = std::get<Number>(*this);
  }

  if (result) {
    return static_cast<std::optional<double>>(result);
  } else {
    return {};
  }
}
