#ifndef LIBVCD_TYPES_EVENT_SCOPE_HPP
#define LIBVCD_TYPES_EVENT_SCOPE_HPP

#include "../types/enums.hpp"
#include "../grammar/enums/scope_type.hpp"
#include "../grammar/commands.hpp"
#include "parse/action/enum.h"

#include <string_view>

namespace VCD {

struct ScopeEvent {
  ScopeType type;
  std::string_view identifier;
};

template<class Rule>
struct ScopeAction : tao::pegtl::nothing<Rule> {};

template<>
struct ScopeAction<Grammar::scope_type> : Parse::ScopedValueAction<ScopeType> {};

template<>
struct ScopeAction<ScopeEvent> {
  static void success(ScopeEvent &parent, ScopeType type) {
    parent.type = type;
  }
};

template<>
struct ScopeAction<Grammar::scope_identifier> {
  template<class Input>
  static void apply(const Input& input, ScopeEvent& state) {
    state.identifier = std::string_view{input.begin(), input.size()};
  }
};

}

#endif //PARSE_SCOPE_HPP
