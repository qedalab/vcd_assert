#ifndef LIBPARSE_AST_STORE_H
#define LIBPARSE_AST_STORE_H

namespace Parse {
namespace AST {

template <class Storage>
struct Store {
  template<class Input, class State>
  static void apply(const Input& in, State& state) {
    state.set(Storage{in});
  }
};

} // namespace AST
} // namespace Parse

#endif
