#ifndef LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
#define LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP

namespace Parse {

template <typename Type>
struct make_pegtl_template {
  template <typename Rule>
  using type = Type;
};

template <class Apply0>
struct make_pegtl_apply0 {
  template <typename Rule>
  struct type {

    template<typename State>
    static bool apply0(State &state) {
      return Apply0::template apply0<Rule>(state);
    }
  };
};

template <class Apply>
struct make_pegtl_apply {
  template <typename Rule>
  struct type {

    template<typename Input, typename State>
    static bool apply(const Input& input, State &state) {
      return Apply::template apply0<Rule>(input, state);
    }
  };
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
