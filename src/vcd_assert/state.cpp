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

#include "vcd_assert/state.hpp"
#include "parse/util/dependent_value.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <range/v3/view/indices.hpp>

using namespace VCDAssert;
using namespace ranges::view;

State::State(VCD::Header &header)
{
  auto size = header.num_id_codes();

  values_ = std::vector<StateValue>(size);
  std::size_t vector_size = 0;

  // Handle real and scalar while counting vector values
  for (auto i : indices(size)) {
    auto var_id_code_view = header.get_var_id_code(i);
    auto var_size = var_id_code_view.get_size();
    auto var_type = var_id_code_view.get_type();

    // Real value
    if (var_type == VCD::VarType::real) {
      values_.at(i) = 0.0;
      continue;
    }

    // Scalar Value
    if (var_size == 1) {
      values_.at(i) = VCD::Value::x;
      continue;
    }

    // Else Vector
    vector_size += var_size;
  }

  // No vector values
  if (vector_size == 0)
    return;

  // Construct packed vector object
  packed_vector_values_ = std::vector<VCD::Value>{vector_size, VCD::Value::x};

  auto *pointer = &packed_vector_values_.front();

  // Fill in Vector StateValue's with range values
  for (auto i : indices(size)) {
    auto var_id_code_view = header.get_var_id_code(i);
    auto var_size = var_id_code_view.get_size();
    auto var_type = var_id_code_view.get_type();

    // Real value or scalar
    if (var_type == VCD::VarType::real || var_size == 1) {
      continue;
    }

    // Else Vector
    values_.at(i) = ranges::span<VCD::Value>(pointer, var_size);
    pointer += var_size;
  }

  assert(pointer == (&packed_vector_values_.back()) + 1);
}

StateValuePointer State::get_value_pointer(std::size_t index)
{ 
  if(values_.size() > index){
    StateValue &state_value = values_.at(index);

    // Return the StateValuePointer where the data is stored
    return std::visit(
        [](auto &value) -> StateValuePointer {
          using T = std::decay_t<decltype(value)>;

          if constexpr (std::is_same_v<T, VCD::Value>)
            return &value;
          else if constexpr (std::is_same_v<T, ranges::span<VCD::Value>>)
            return value;
          else if constexpr (std::is_same_v<T, double>)
            return &value;
          else
            static_assert(Parse::Util::dependent_value<false, T>);
        },
        state_value);
  }else{
    throw std::runtime_error("InternalError: index out of range");
  }
}

VCD::Value State::get_scalar_value(std::size_t index) const
{
  const StateValue &state_value = values_.at(index);
  return std::get<VCD::Value>(state_value);
}

ranges::span<const VCD::Value> State::get_vector_value(std::size_t index) const
{
  const StateValue &state_value = values_.at(index);
  return std::get<ranges::span<VCD::Value>>(state_value);
}

double State::get_real_value(std::size_t index) const
{
  const StateValue &state_value = values_.at(index);
  return std::get<double>(state_value);
}

void State::internal_set_value(std::size_t index, VCD::Value value)
{
  StateValue &state_value = values_.at(index);
  std::get<VCD::Value>(state_value) = value;
}

void State::internal_set_value(std::size_t index, double value)
{
  StateValue &state_value = values_.at(index);
  std::get<double>(state_value) = value;
}

void State::internal_set_value(std::size_t index, ranges::span<VCD::Value> values)
{
  StateValue &state_value = values_.at(index);
  auto old_values = std::get<ranges::span<VCD::Value>>(state_value);

  if (values.size() != old_values.size())
    throw std::runtime_error("State: Vector value size mismatch");

  ranges::copy(values, ranges::begin(old_values));
}

void State::set_value(std::size_t index, VCD::Value value) {
  scalar_buffer_.emplace_back(ScalarValueChange{index, value});
}

void State::set_value(std::size_t index, double value) {
  real_buffer_.emplace_back(RealValueChange{index, value});
}

void State::set_value(std::size_t index, ranges::span<VCD::Value> values) {
  vector_buffer_.emplace_back(VectorValueChange{index, std::vector<VCD::Value>(values)});
}

void State::update_sim_time() noexcept {
  while(!scalar_buffer_.empty()) {
    auto& back = scalar_buffer_.back();
    internal_set_value(back.index, back.value);
    scalar_buffer_.pop_back();
  }

  while(!real_buffer_.empty()) {
    auto& back = real_buffer_.back();
    internal_set_value(back.index, back.value);
    real_buffer_.pop_back();
  }

  while(!vector_buffer_.empty()) {
    auto& back = vector_buffer_.back();
    internal_set_value(back.index, back.values);
    vector_buffer_.pop_back();
  }
}

std::size_t State::num_values() { return values_.size(); }

std::size_t State::num_packed_vector_values()
{
  return packed_vector_values_.size();
}

std::size_t State::num_total_values()
{
  return num_values() + num_packed_vector_values();
}
