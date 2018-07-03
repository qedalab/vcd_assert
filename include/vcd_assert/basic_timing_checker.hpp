#ifndef VCD_ASSERT_BASIC_TIMING_CHECKER_HPP
#define VCD_ASSERT_BASIC_TIMING_CHECKER_HPP

#include <cstdint>
#include <vector>

namespace VCDAssert {

class BasicTimingChecker {
  struct Entry {
    std::size_t last_event = 0;
    std::size_t hold_until = 0;
  };

  std::vector<Entry> storage_;
  size_t sim_time_ = 0;

  void update_sim_time(std::size_t sim_time);

public:
  BasicTimingChecker(std::size_t size);

  // enforce hold condition
  void hold(std::size_t index, std::size_t sim_time, std::size_t hold_time);

  // Stuff check for timing violations
  [[nodiscard]] bool setup(std::size_t index, std::size_t sim_time,
                           std::size_t setup_time);
  [[nodiscard]] bool event(std::size_t index, std::size_t sim_time);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_BASIC_TIMING_CHECKER_HPP
