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

  BasicTimingChecker checker_;
  State state_;
  std::vector<IndexLookup> index_lookup_;
  std::vector<Event> events_;

  size_t sim_time_ = 0;
public:
  TimingChecker(const VCD::Header& header);

  [[nodiscard]] bool event(std::size_t index, VCD::Value value);
  [[nodiscard]] bool event(std::size_t index, ranges::span<VCD::Value> values);
  [[nodiscard]] bool event(std::size_t index, double value);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
