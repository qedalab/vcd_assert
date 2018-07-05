#include "vcd_assert/conditional.hpp"

using namespace VCDAssert;

VCD::Value ConditionalValuePointer::value() {
  return std::visit([](auto&& value) -> VCD::Value {
    using T = typename std::decay<decltype(value)>::type;

    if constexpr (std::is_same_v<T, VCD::Value>) {
      return value;
    } else if constexpr(std::is_same_v<T, VCD::Value*>) {
      return *value;
    } else {
      return value->call();
    }
  }, value_);
}
