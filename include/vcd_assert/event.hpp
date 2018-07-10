#ifndef VCD_ASSERT_EVENT_HPP
#define VCD_ASSERT_EVENT_HPP

#include "./conditional.hpp"
#include "./edge_type.hpp"

#include <range/v3/span.hpp>

#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

namespace VCDAssert {

struct HoldEvent {
  std::size_t index;
  std::size_t hold_time;
};

struct SetupEvent {
  std::size_t index;
  std::size_t setup_time;
};

struct ConditionalSetupEvent {
  ConditionalValuePointer condition;
  SetupEvent event;
};

struct ConditionalHoldEvent {
  ConditionalValuePointer condition;
  HoldEvent event;
};

// clang-format off

using Event = std::variant<
  HoldEvent,
  SetupEvent,
  ConditionalSetupEvent,
  ConditionalHoldEvent>;

// clang-format on

struct EventList {
  std::vector<Event> pos_edge;
  std::vector<Event> neg_edge;

  ranges::span<Event> get_event_list(EdgeType type);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_EVENT_HPP
