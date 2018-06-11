#ifndef VCD_EVENT_TIME_SCALE_HPP
#define VCD_EVENT_TIME_SCALE_HPP

#include "vcd/types/enums.hpp"

#include <tao/pegtl/nothing.hpp>
#include <vcd/grammar/enums/time.hpp>
#include <parse/action/enum.h>

namespace VCD {

struct TimeScaleEvent {
  TimeNumber number;
  TimeUnit unit;
};

template <class Rule>
struct TimeScaleAction : tao::pegtl::nothing<Rule> {};

template<>
struct TimeScaleAction<Grammar::time_unit> : Parse::ScopedValueAction<TimeUnit> {};

template<>
struct TimeScaleAction<Grammar::time_number> {
  template<class Input>
  static void apply(const Input& input, TimeScaleEvent& event) {
    switch(input.size()) {
    case 1:
      event.number = TimeNumber::_1;
      break;
    case 2:
      event.number = TimeNumber::_10;
      break;
    case 3:
      event.number = TimeNumber::_100;
      break;
    default:
      throw std::runtime_error("Internal error: bad Grammar::time_number match");
    }
  }
};

template<>
struct TimeScaleAction<TimeScaleEvent> {
  static void success(TimeScaleEvent& event, TimeNumber number) {
    event.number = number;
  }

  static void success(TimeScaleEvent& event, TimeUnit unit) {
    event.unit = unit;
  }
};

} // namespace VCD

#endif // VCD_EVENT_TIME_SCALE_HPP
