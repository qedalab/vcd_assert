#ifndef LIBVCD_ACTIONS_IDENTIFIER_CODE_HPP
#define LIBVCD_ACTIONS_IDENTIFIER_CODE_HPP

#include "..//grammar/base.hpp"

#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/dispatch.hpp"

namespace VCD::Actions {

using namespace Parse;

struct IdentifierCodeAction : single_dispatch<
    Grammar::identifier_code, apply<Apply::string_view>
> {
using state = std::string_view;
};

} // namespace VCD::Actions

#endif // LIBVCD_ACTIONS_IDENTIFIER_CODE_HPP
