#ifndef VCD_ASSERT_STATE_HPP
#define VCD_ASSERT_STATE_HPP

#include "vcd/types/header.hpp"

#include <range/v3/span.hpp>

#include <variant>


namespace VCDAssert {

using StateValuePointer = std::variant<
  VCD::Value*,
  ranges::span<VCD::Value>,
  double*>;

using StateValue = std::variant<
  VCD::Value,
  ranges::span<VCD::Value>,
  double>;

class State {
  std::vector<VCD::Value> packed_vector_values_;
  std::vector<StateValue> values_;

public:
  State(VCD::Header& header);

  // Get General Pointer
  StateValuePointer get_value_pointer(std::size_t index);

  // Getters
  VCD::Value get_scalar_value(std::size_t index) const;
  ranges::span<const VCD::Value> get_vector_value(std::size_t index) const;
  double get_real_value(std::size_t index) const;

  // Setters
  void set_value(std::size_t index, VCD::Value value);
  void set_value(std::size_t index, double value);
  void set_value(std::size_t index, ranges::span<VCD::Value> values);

  // Size
  std::size_t num_values();
};

} // namespace VCDAssert

#endif // VCD_ASSERT_STATE_HPP
