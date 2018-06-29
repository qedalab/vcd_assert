#ifndef PARSE_CONTROL_BASE_H
#define PARSE_CONTROL_BASE_H

#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/rewind_mode.hpp>

namespace Parse {

using tao::pegtl::apply_mode;
using tao::pegtl::rewind_mode;

template<class T>
using member_state_t = typename T::state;

template<class T, class Rule>
using member_action_t = typename T::template action<Rule>;


}

#endif //PARSE_CONTROL_BASE_H
