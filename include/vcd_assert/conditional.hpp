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

  VCD::Value value();
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
