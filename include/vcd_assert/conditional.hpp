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

#ifndef VCD_ASSERT_CONDITIONAL_HPP
#define VCD_ASSERT_CONDITIONAL_HPP

#include <memory>
#include <parse/util/dependent_value.hpp>
#include <variant>
#include <vcd/types/enums.hpp>

namespace VCDAssert {

enum class EqualityOperator {
  logical_equal, logical_not_equal, case_equal, case_not_equal
};

template <EqualityOperator Op> class ConditionalOperator;

template <EqualityOperator Op>
using UniqueConditionalOperator = std::unique_ptr<ConditionalOperator<Op>>;

using ConditionalValuePointerVariant = std::variant<
  UniqueConditionalOperator<EqualityOperator::logical_equal>,
  UniqueConditionalOperator<EqualityOperator::logical_not_equal>,
  UniqueConditionalOperator<EqualityOperator::case_equal>,
  UniqueConditionalOperator<EqualityOperator::case_not_equal>,
  VCD::Value*,
  VCD::Value
>;

class ConditionalValuePointer {
  ConditionalValuePointerVariant value_;

public:
  template <typename Type>
  ConditionalValuePointer(Type value)
  {
    using Decayed = typename std::decay<Type>::type;

    if constexpr (std::is_same_v<Decayed, VCD::Value>) {
      value_ = value;
    } else if constexpr (std::is_same_v<Decayed, VCD::Value*>) {
      value_ = value;
    } else {
      value_ = std::make_unique<Decayed>(std::move(value));
    }
  }

  ConditionalValuePointer(const ConditionalValuePointer&) = delete;
  ConditionalValuePointer& operator=(const ConditionalValuePointer&) = delete;

  ConditionalValuePointer(ConditionalValuePointer&& other);
  ConditionalValuePointer& operator=(ConditionalValuePointer&& other);
  ~ConditionalValuePointer();

  const ConditionalValuePointerVariant& inner() const noexcept;

  VCD::Value value() const noexcept;
};


template <EqualityOperator Op>
class ConditionalOperator {
  ConditionalValuePointer left_;
  ConditionalValuePointer right_;

public:
  ConditionalOperator(ConditionalValuePointer left,
                      ConditionalValuePointer right) :
      left_(std::move(left)),
      right_(std::move(right)) {}

  constexpr EqualityOperator get_operator() const noexcept {
    return Op;
  }

  const ConditionalValuePointer& inner_left() const noexcept {
    return left_;
  }

  const ConditionalValuePointer& inner_right() const noexcept {
    return right_;
  }

  VCD::Value call() {
    VCD::Value left = left_.value();
    VCD::Value right = right_.value();

    if constexpr (Op == EqualityOperator::case_equal) {
      if(left == right)
        return VCD::Value::one;
      else 
        return VCD::Value::zero;
    } else if constexpr (Op == EqualityOperator::case_not_equal) {
      if(left == right)
        return VCD::Value::zero;
      else 
        return VCD::Value::one;
    } else if constexpr (Op == EqualityOperator::logical_equal) {
      if(left == VCD::Value::one) {
        if(right == VCD::Value::one)
          return VCD::Value::one;

        if(right == VCD::Value::zero)
          return VCD::Value::zero;

        return VCD::Value::x;
      }

      if(left == VCD::Value::zero) {
        if(right == VCD::Value::one)
          return VCD::Value::zero;

        if(right == VCD::Value::zero)
          return VCD::Value::one;

        return VCD::Value::x;
      }

      return VCD::Value::x;
    } else if constexpr (Op == EqualityOperator::logical_not_equal) {
      if(left == VCD::Value::one) {
        if(right == VCD::Value::one)
          return VCD::Value::zero;

        if(right == VCD::Value::zero)
          return VCD::Value::one;

        return VCD::Value::x;
      }

      if(left == VCD::Value::zero) {
        if(right == VCD::Value::one)
          return VCD::Value::one;

        if(right == VCD::Value::zero)
          return VCD::Value::zero;

        return VCD::Value::x;
      }

      return VCD::Value::x;
    } else {
      static_assert(Parse::Util::dependent_value<false, decltype(Op)>);
    };
  };
};

}

#endif // VCD_ASSERT_CONDITIONAL_HPP
