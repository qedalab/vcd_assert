#ifndef LIBSDF_TYPES_TIMINGCHECK_HPP
#define LIBSDF_TYPES_TIMINGCHECK_HPP


#include <sdf/types/timing.hpp>
#include <sdf/types/values.hpp>
#include <parse/util/dependant_value.hpp>

#include <variant>
#include <tuple>

namespace SDF {
 
namespace Unsupported {
  struct Setup{};
  struct Setuphold{};
  struct Recovery{};
  struct Removal{};
  struct Recrem{};
  struct Skew{};
  struct Bidirectskew{};
  struct Width{};
  struct Period{};
  struct Nochange{};
}


struct InvertedNode : public Node {};

using NodeEqualityTuple = std::tuple<Node,Node>;

struct NodeScalarEquality {
  Node left;
  EqualityOperator op;
  bool right;
  bool operator==(const NodeScalarEquality& other) const noexcept{
    if((left == other.left)
        && (op == other.op) 
        && (right == other.right)){
            return true;
    }else{
        return false;
    }
  }
};

using TimingCheckConditionVariant = std::variant<
  Node,
  InvertedNode,
  NodeScalarEquality
>;

struct TimingCheckCondition : public TimingCheckConditionVariant {
  using TimingCheckConditionVariant::TimingCheckConditionVariant;
//   bool operator==(const TimingCheckCondition& other) const noexcept{
//     if(std::holds_alternative<Node>(*this) && std::holds_alternative<Node>(other)){
//       return std::get<Node>(*this) == std::get<Node>(other);
//     }else if(std::holds_alternative<Number>(*this) && std::holds_alternative<Number>(other)){
//       return std::get<InvertedNode>(*this) == std::get<InvertedNode>(other);
//     }else if(std::holds_alternative<Number>(*this) && std::holds_alternative<Number>(other)){
//       return std::get<NodeScalarEquality>(*this) == std::get<NodeScalarEquality>(other);
//     }else{
//       return false;
//     }
//   }
//     bool operator==(const TimingCheckCondition& other) const noexcept{
//     if(std::holds_alternative<Node>(*this) && std::holds_alternative<Node>(other)){
//       return std::get<Node>(*this) == std::get<Node>(other);
//     }else if(std::holds_alternative<Number>(*this) && std::holds_alternative<Number>(other)){
//       return std::get<InvertedNode>(*this) == std::get<InvertedNode>(other);
//     }else if(std::holds_alternative<Number>(*this) && std::holds_alternative<Number>(other)){
//       return std::get<NodeScalarEquality>(*this) == std::get<NodeScalarEquality>(other);
//     }else{
//       return false;
//     }
//   }
};

struct PortTimingCheck{
  Node port; //Todo make Port and remove edge
//   std::optional<EdgeType> edge;
  std::optional<TimingCheckCondition> timing_check_condition;
  std::optional<std::string> symbolic_name;
    
//   bool operator==(const TimingCheckCondition& other) const noexcept{
  
//   }
};

struct Hold {
  PortTimingCheck input; //subject
  PortTimingCheck output; //stimili //change
  Value value;
};

// clang-format off
using TimingCheckVariant = std::variant<
  Hold,
  Unsupported::Setup, // TODO
  Unsupported::Setuphold,
  Unsupported::Recovery,
  Unsupported::Removal,
  Unsupported::Recrem,
  Unsupported::Skew,
  Unsupported::Bidirectskew,
  Unsupported::Width,
  Unsupported::Period,
  Unsupported::Nochange 
>;
// clang-format on

struct TimingCheck {
  TimingCheckVariant value;

  TimingCheckType get_enum_type() const {

    return std::visit([](auto&& param) -> TimingCheckType {

      using T = typename std::decay<decltype(param)>::type;

      if constexpr (std::is_same_v<T, Unsupported::Setup>) {
          return TimingCheckType::setup;
      } else if constexpr (std::is_same_v<T, Hold>) {
          return TimingCheckType::hold;
      } else if constexpr (std::is_same_v<T, Unsupported::Setuphold>) {
          return TimingCheckType::setuphold;
      } else if constexpr (std::is_same_v<T, Unsupported::Recovery>) {
          return TimingCheckType::recovery;
      } else if constexpr (std::is_same_v<T, Unsupported::Removal>) {
          return TimingCheckType::removal;
      } else if constexpr (std::is_same_v<T, Unsupported::Recrem>) {
          return TimingCheckType::recrem;
      } else if constexpr (std::is_same_v<T, Unsupported::Skew>) {
          return TimingCheckType::skew;
      } else if constexpr (std::is_same_v<T, Unsupported::Bidirectskew>) {
          return TimingCheckType::bidirectskew;
      } else if constexpr (std::is_same_v<T, Unsupported::Width>) {
          return TimingCheckType::width;
      } else if constexpr (std::is_same_v<T, Unsupported::Period>) {
          return TimingCheckType::period;
      } else if constexpr (std::is_same_v<T, Unsupported::Nochange>) {
          return TimingCheckType::nochange;
      } else {
          static_assert(Parse::Util::dependant_value<false, T>);
      }
    }, value);
  }

};

using TimingCheckVector = std::vector<TimingCheck>;

struct TimingCheckSpec : public TimingCheckVector {
  using TimingCheckVector::TimingCheckVector;

  std::vector<std::size_t> get_timing_check_indices_by_type(TimingCheckType &type) const;
};

// get_timing_check_indices_by_type<TimingCheckVariant::Hold>()
 
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_HPP