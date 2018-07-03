#include "vcd_assert/basic_timing_checker.hpp"

#include <stdexcept>

using namespace VCDAssert;

BasicTimingChecker::BasicTimingChecker(std::size_t size) :
  storage_{size}
{
  // Empty
}

void BasicTimingChecker::update_sim_time(std::size_t sim_time) {
  if(sim_time < sim_time_)
    throw std::runtime_error("BasicTimnigChecker: Can't go back in time");

  sim_time_ = sim_time;
}

void BasicTimingChecker::hold(std::size_t index, std::size_t sim_time,
                              std::size_t hold_time) {
  update_sim_time(sim_time);

  auto& entry = storage_.at(index);
  entry.hold_until = std::max(sim_time + hold_time, entry.hold_until);
}

[[nodiscard]] bool BasicTimingChecker::setup(std::size_t index,
                                             std::size_t sim_time,
                                             std::size_t setup_time) {
  update_sim_time(sim_time);

  auto& entry = storage_.at(index);

  // Not enough simulation time has passed
  if (setup_time > sim_time)
    return true;

  // If it falls within setup time
  std::size_t time_passed = sim_time - entry.last_event;
  if (setup_time > time_passed)
    return false;

  // setup time not violated
  return true;
}

[[nodiscard]] bool BasicTimingChecker::event(std::size_t index,
                                             std::size_t sim_time) {
  update_sim_time(sim_time);

  auto& entry = storage_.at(index);
  entry.last_event = sim_time;

  if(entry.hold_until > sim_time)
    return false;

  return true;
}
