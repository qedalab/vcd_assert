#ifndef LIBPARSE_CAPTURE_MAKE_PEGTL_ACTION_HPP
#define LIBPARSE_CAPTURE_MAKE_PEGTL_ACTION_HPP

namespace Parse {

template <typename Type>
struct make_pegtl_template {
  template <typename Rule>
  using type = Type;
};

} // namespace Parse

#endif // LIBPARSE_CAPTURE_MAKE_PEGTL_ACTION_HPP
