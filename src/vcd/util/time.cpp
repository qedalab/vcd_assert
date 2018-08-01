#include "vcd/util/time.hpp"

#include "vcd/serialize/time_scale.hpp"

using namespace VCD;

std::string Util::time_string(TimeScale scale, std::size_t time) {

  time *= static_cast<std::size_t>(scale.get_number());

  auto buffer = std::to_string(time);
  buffer.append(time_unit_to_string(scale.get_unit()));

  return buffer;
}
