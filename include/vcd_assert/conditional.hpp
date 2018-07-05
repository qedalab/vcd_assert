#ifndef VCD_ASSERT_CONDITIONAL_HPP
#define VCD_ASSERT_CONDITIONAL_HPP

#include <vcd/types/enums.hpp>
#include <parse/util/dependent_value.hpp>

#include <variant>

namespace VCDAssert {

enum class EqualityOperator {
  logical_equal, logical_not_equal, case_equal, case_not_equal
};

template <EqualityOperator Op> class ConditionalOperator;

using ConditionalValuePointerVariant = std::variant<
  ConditionalOperator<EqualityOperator::logical_equal>*,
  ConditionalOperator<EqualityOperator::logical_not_equal>*,
  ConditionalOperator<EqualityOperator::case_equal>*,
  ConditionalOperator<EqualityOperator::case_not_equal>*,
  VCD::Value*,
  VCD::Value
>;

class ConditionalValuePointer {
  ConditionalValuePointerVariant value_;

public:
  template <typename T>
  ConditionalValuePointer(T value) {
    value_ = value;
  }

  VCD::Value value();
};


template <EqualityOperator Op>
class ConditionalOperator {
  ConditionalValuePointer left_;
  ConditionalValuePointer right_;

public:
  ConditionalOperator(ConditionalValuePointer left,
                      ConditionalValuePointer right) :
      left_(left),
      right_(right) {}

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
