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
  struct ScalarValueChange {
    std::size_t index;
    VCD::Value value;
  };

  struct RealValueChange {
    std::size_t index;
    double value;
  };

  struct VectorValueChange {
    std::size_t index;
    std::vector<VCD::Value> values;
  };

  std::vector<VCD::Value> packed_vector_values_;
  std::vector<StateValue> values_;

  std::vector<ScalarValueChange> scalar_buffer_;
  std::vector<RealValueChange> real_buffer_;
  std::vector<VectorValueChange> vector_buffer_;

  void internal_set_value(std::size_t index, VCD::Value value);
  void internal_set_value(std::size_t index, double value);
  void internal_set_value(std::size_t index, ranges::span<VCD::Value> values);

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

  void update_sim_time() noexcept;

  // Size
  std::size_t num_values();
  std::size_t num_packed_vector_values();
  std::size_t num_total_values();
};

} // namespace VCDAssert

#endif // VCD_ASSERT_STATE_HPP
