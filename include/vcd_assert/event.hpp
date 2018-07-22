#ifndef VCD_ASSERT_EVENT_HPP
#define VCD_ASSERT_EVENT_HPP

#include "./conditional.hpp"
#include "./edge_type.hpp"

#include "parse/util/bag.hpp"

#include <range/v3/span.hpp>

#include <cstdint>
#include <vector>

namespace VCDAssert {

struct TriggeredEvent {
  ConditionalValuePointer condition;
  EdgeType edge_type;
  std::size_t assertion_index;
  std::size_t hold_time;
};

struct TriggeredEventList {
  Parse::Util::Bag<TriggeredEvent> events;
};

struct RegisterEvent {
  ConditionalValuePointer condition;
  EdgeType edge_type;
  TriggeredEvent triggered;
};

struct RegisterEventList {
  std::vector<RegisterEvent> events;
};

} // namespace VCDAssert

#endif // VCD_ASSERT_EVENT_HPP
