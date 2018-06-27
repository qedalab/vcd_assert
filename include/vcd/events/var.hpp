#ifndef LIBVCD_TYPES_EVENT_VAR_HPP
#define LIBVCD_TYPES_EVENT_VAR_HPP

#include "../types/enums.hpp"
#include "../grammar/enums/var_type.hpp"
#include "../types/variable.hpp"

#include <parse/action/enum.h>
#include <tao/pegtl/nothing.hpp>

#include <string_view>
#include <parse/action/enum.h>
#include <vcd/grammar/base.hpp>
#include <vcd/grammar/commands.hpp>

namespace VCD {

template<class Rule>
struct VarAction : tao::pegtl::nothing<Rule> {};

template<>
struct VarAction<Grammar::var_type> : Parse::ScopedValueAction<VarType> {};

template<>
struct VarAction<VariableView> {
  static void success(VariableView &parent, VarType type) {
    parent.type = type;
  }
};

template<>
struct VarAction<Grammar::identifier_code> {
  template<class Input>
  static void apply(const Input& input, VariableView& state) {
    state.identifier_code = std::string_view{input.begin(), input.size()};
  }
};

template<>
struct VarAction<Grammar::reference> {
  template<class Input>
  static void apply(const Input& input, VariableView& state) {
    state.reference = std::string_view{input.begin(), input.size()};
  }
};

template<>
struct VarAction<Grammar::var_size> {
  template<class Input>
  static void apply(const Input& input, VariableView& state) {
    // TODO avoid the string alloc
    state.size = std::stoul(input.string());
  }
};

} // namespace VCD

#endif // LIBVCD_TYPES_EVENT_VAR_HPP
