#ifndef LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
#define LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP

namespace Parse {

template <typename Type>
struct make_pegtl_template {
  template <typename Rule>
  using type = Type;
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
