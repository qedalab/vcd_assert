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
