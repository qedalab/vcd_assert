#include "vcd_assert/conditional.hpp"

using namespace VCDAssert;

// clang-format off
VCD::Value ConditionalValuePointer::value() const noexcept {
  return std::visit([](auto&& value) -> VCD::Value {
    using T = typename std::decay<decltype(value)>::type;

    if constexpr (std::is_same_v<T, VCD::Value>) {
      return value;
    } else if constexpr (std::is_same_v<T, VCD::Value*>) {
      return *value;
    } else {
      return value->call();
    }
  }, value_);
}

// clang-format on

ConditionalValuePointer::ConditionalValuePointer(
    ConditionalValuePointer &&other)
{
  value_ = std::move(other.value_);
}

ConditionalValuePointer &ConditionalValuePointer::
operator=(ConditionalValuePointer &&other)
{
  value_ = std::move(other.value_);
  return *this;
}

ConditionalValuePointer::~ConditionalValuePointer() = default;
