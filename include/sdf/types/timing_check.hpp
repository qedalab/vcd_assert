#ifndef LIBSDF_TYPES_TIMINGCHECK_HPP
#define LIBSDF_TYPES_TIMINGCHECK_HPP


#include <sdf/types/timing.hpp>
#include <sdf/types/values.hpp>

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

struct InvertedNode : public Node {
  using Node::Node;
};

using NodeEqualityTuple = std::tuple<Node,Node>;

struct NodeEquality : public NodeEqualityTuple {
  using NodeEqualityTuple::NodeEqualityTuple;
};

using TimingCheckConditionVariant = std::variant<
  Node,
  InvertedNode,
  NodeEquality
>;

struct TimingCheckCondition : public TimingCheckConditionVariant {
  using TimingCheckConditionVariant::TimingCheckConditionVariant;
};

struct PortTimingCheck{
  Port port_instance;
  std::optional<std::string> edge_identifier;
  std::optional<std::string> symbolic_name;
  std::optional<TimingCheckCondition> timing_check_condition;
};
struct Hold {
  PortTimingCheck input; //subject
  PortTimingCheck output; //stimili //change
  Value value;
};

// clang-format off
using TimingCheckVariant = std::variant<
  Hold,
  Unsupported::Setup,
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
  TimingCheckType type;
  TimingCheckVariant value;
};

struct TimingCheckSpec{
  std::vector<TimingCheck> timing_checks;

  std::vector<std::size_t> get_timing_check_indices_by_type(TimingCheckType &type) const;
};

 
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_HPP