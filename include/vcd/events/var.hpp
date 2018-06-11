#ifndef LIBVCD_TYPES_EVENT_VAR_HPP
#define LIBVCD_TYPES_EVENT_VAR_HPP

#include "../types/enums.hpp"
#include "../grammar/enums/var_type.hpp"

#include <parse/action/enum.h>
#include <tao/pegtl/nothing.hpp>

#include <string_view>
#include <parse/action/enum.h>
#include <vcd/grammar/base.hpp>
#include <vcd/grammar/commands.hpp>

namespace VCD {

struct VarEvent {
  VarType type;
  std::size_t size;
  std::string_view id_code;
  std::string_view reference;
};

template<class Rule>
struct VarAction : tao::pegtl::nothing<Rule> {};

template<>
struct VarAction<Grammar::var_type> : Parse::ScopedValueAction<VarType> {};

template<>
struct VarAction<VarEvent> {
  static void success(VarEvent &parent, VarType type) {
    parent.type = type;
  }
};

template<>
struct VarAction<Grammar::identifier_code> {
  template<class Input>
  static void apply(const Input& input, VarEvent& state) {
    state.id_code = std::string_view{input.begin(), input.size()};
  }
};

template<>
struct VarAction<Grammar::reference> {
  template<class Input>
  static void apply(const Input& input, VarEvent& state) {
    state.reference = std::string_view{input.begin(), input.size()};
  }
};

template<>
struct VarAction<Grammar::var_size> {
  template<class Input>
  static void apply(const Input& input, VarEvent& state) {
    // TODO avoid the string alloc
    state.size = std::stoul(input.string());
  }
};

} // namespace VCD

#endif // LIBVCD_TYPES_EVENT_VAR_HPP
