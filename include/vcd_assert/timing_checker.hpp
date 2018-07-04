#ifndef VCD_ASSERT_TIMING_CHECKER_HPP
#define VCD_ASSERT_TIMING_CHECKER_HPP

#include "./basic_timing_checker.hpp"

#include "vcd/types/header.hpp"
#include <range/v3/span.hpp>

namespace VCDAssert {

class TimingChecker {
  BasicTimingChecker checker_;

  size_t sim_time_ = 0;
public:
  TimingChecker(const VCD::Header& header);

  [[nodiscard]] bool event(std::size_t index, VCD::Value value);
  [[nodiscard]] bool event(std::size_t index, ranges::span<VCD::Value> values);
  [[nodiscard]] bool event(std::size_t index, double value);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
