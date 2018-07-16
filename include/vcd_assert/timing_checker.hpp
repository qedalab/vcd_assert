#ifndef VCD_ASSERT_TIMING_CHECKER_HPP
#define VCD_ASSERT_TIMING_CHECKER_HPP

#include "./basic_timing_checker.hpp"
#include "./conditional.hpp"
#include "./event.hpp"
#include "./state.hpp"

#include "vcd/types/header.hpp"
#include <range/v3/span.hpp>

namespace VCDAssert {

class TimingChecker {

  struct IndexLookup {
    std::size_t from;
    std::size_t to;
  };

  // Order is important
  std::shared_ptr<VCD::Header> header_;
  State state_;
  BasicTimingChecker checker_;

  std::vector<IndexLookup> index_lookup_;
  std::vector<EventList> event_lists_;

  size_t sim_time_ = 0;

  [[nodiscard]] bool handle_event(const Event& event);

private:
  bool match_scope(std::shared_ptr<SDF::DelayFile> delayfile std::size_t vcd_scope_node);

public:
  // Claims ownership of the header
  TimingChecker(std::shared_ptr<VCD::Header> header);

  void apply_sdf(std::shared_ptr<SDF::DelayFile> delayfile std::size_t vcd_scope_node);

  // Trigger event and return true if event was triggered
  [[nodiscard]] bool event(std::size_t time, std::size_t index,
                           VCD::Value value);

  [[nodiscard]] bool event(std::size_t time, std::size_t index,
                           ranges::span<VCD::Value> values);

  void update_sim_time(std::size_t sim_time_);
  // Don't handle doubles for now
  // [[nodiscard]] bool event(std::size_t index, double value);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
