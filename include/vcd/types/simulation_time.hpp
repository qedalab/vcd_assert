#ifndef LIBVCD_TYPES_SIMULATION_TIME_HPP
#define LIBVCD_TYPES_SIMULATION_TIME_HPP

#include <cstddef>

namespace VCD {

struct SimulationTime {
  std::size_t number;

  SimulationTime& operator=(std::size_t value) {
    this->number = value;
    return *this;
  }
};

} // namespace VCD

#endif // LIBVCD_TYPES_SIMULATION_TIME_HPP
