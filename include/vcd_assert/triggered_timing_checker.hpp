#ifndef VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
#define VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP

#include "./conditional.hpp"

#include "sdf/types/enums.hpp"
#include "./edge_type.hpp"

#include <parse/util/slot_map.hpp>
#include <parse/util/bag.hpp>

#include <optional>

namespace VCDAssert {

struct TriggeredEvent {
  ConditionalValuePointer condition;
  EdgeType edge_type;
  std::size_t assertion_index;
  std::size_t until;
};

struct TriggeredEventList {
  Parse::Util::Bag<TriggeredEvent> events;
};

class TriggeredTimingChecker
{
  std::vector<TriggeredEventList> triggered_event_list_;
  std::size_t sim_time_;

public:
  TriggeredTimingChecker(std::size_t size);

  void update_sim_time(std::size_t sim_time);

  [[nodiscard]] bool event(std::size_t index,
                           VCD::Value from, VCD::Value to);

  void hold(ConditionalValuePointer condition, std::size_t index,
            std::size_t hold_time, EdgeType edge_type);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
