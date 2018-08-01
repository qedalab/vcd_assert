#ifndef VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
#define VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP

#include "./conditional.hpp"
#include "./edge_type.hpp"
#include "./event.hpp"

#include "sdf/types/enums.hpp"

#include "parse/util/bag.hpp"

namespace VCDAssert {

struct TriggeredItem {
  std::reference_wrapper<const ConditionalValuePointer> condition;
  EdgeType edge_type;
  std::string_view assertion_sv;
  std::size_t until;
};

struct TriggeredItemList {
  Parse::Util::Bag<TriggeredItem> items;
};

class TriggeredTimingChecker
{
  std::vector<TriggeredItemList> triggered_item_list_;
  std::size_t sim_time_;

public:
  TriggeredTimingChecker(std::size_t size);

  void set_sim_time(std::size_t sim_time);
  std::size_t get_sim_time();

  [[nodiscard]] bool event(std::size_t index,
                           VCD::Value from, VCD::Value to);

  void hold(const TriggeredEvent &event, std::size_t index);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
