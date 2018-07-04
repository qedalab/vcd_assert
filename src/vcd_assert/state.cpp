#include "vcd_assert/state.hpp"
#include "parse/util/dependant_value.hpp"

#include <range/v3/view/indices.hpp>
#include <range/v3/algorithm/copy.hpp>

using namespace VCDAssert;
using namespace ranges::view;

State::State(VCD::Header& header)
{
  auto size = header.num_id_codes();

  values_ = std::vector<StateValue>(size);
  std::size_t vector_size = 0;

  // Handle real and scalar while counting vector values
  for(auto i : indices(size)) {
    auto var_id_code_view = header.get_var_id_code(i);
    auto var_size = var_id_code_view.get_size();
    auto var_type = var_id_code_view.get_type();

    // Real value
    if(var_type == VCD::VarType::real) {
      values_.at(i) = 0.0;
      continue;
    }

    // Scalar Value
    if(var_size == 1) {
      values_.at(i) = VCD::Value::x;
      continue;
    }

    // Else Vector
    vector_size += var_size;
  }

  // No vector values
  if(vector_size == 0)
    return;

  // Construct packed vector object
  packed_vector_values_ = std::vector<VCD::Value>{vector_size, VCD::Value::x};

  auto* pointer = &packed_vector_values_.front();

  // Fill in Vector StateValue's with range values
  for(auto i : indices(size)) {
    auto var_id_code_view = header.get_var_id_code(i);
    auto var_size = var_id_code_view.get_size();
    auto var_type = var_id_code_view.get_type();

    // Real value or scalar
    if(var_type == VCD::VarType::real || var_size == 1) {
      continue;
    }

    // Else Vector
    values_.at(i) = ranges::span<VCD::Value>(pointer, var_size);
    pointer += var_size;
  }

  assert(pointer == (&packed_vector_values_.back())+1);
}

StateValuePointer State::get_value_pointer(std::size_t index) {
  StateValue& state_value = values_.at(index);

  // Return the StateValuePointer where the data is stored
  return std::visit([](auto& value) -> StateValuePointer {
    using T = std::decay_t<decltype(value)>;

    if constexpr (std::is_same_v<T, VCD::Value>)
      return &value;
    else if constexpr (std::is_same_v<T, ranges::span<VCD::Value>>)
      return value;
    else if constexpr (std::is_same_v<T, double>)
      return &value;
    else
      static_assert(Parse::Util::dependant_value<false, T>);
    
  }, state_value);
}

VCD::Value State::get_scalar_value(std::size_t index) const {
  const StateValue& state_value = values_.at(index);
  return std::get<VCD::Value>(state_value);
}

ranges::span<const VCD::Value> State::get_vector_value(std::size_t index) const{
  const StateValue& state_value = values_.at(index);
  return std::get<ranges::span<VCD::Value>>(state_value);
}

double State::get_real_value(std::size_t index) const {
  const StateValue& state_value = values_.at(index);
  return std::get<double>(state_value);
}

void State::set_value(std::size_t index, VCD::Value value) {
  StateValue& state_value = values_.at(index);
  std::get<VCD::Value>(state_value) = value;
}

void State::set_value(std::size_t index, double value) {
  StateValue& state_value = values_.at(index);
  std::get<double>(state_value) = value;
}

void State::set_value(std::size_t index, ranges::span<VCD::Value> values) {
  StateValue& state_value = values_.at(index);
  auto old_values = std::get<ranges::span<VCD::Value>>(state_value);

  if(values.size() != old_values.size())
    throw std::runtime_error("State: Vector value size mismatch");

  ranges::copy(values, ranges::begin(old_values));
}

std::size_t State::num_values() {
  return values_.size();
}
