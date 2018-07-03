#ifndef LIBVCD_EVENTS_HEADER_HPP
#define LIBVCD_EVENTS_HEADER_HPP

#include "../types/header_reader.hpp"

#include "./scope.hpp"
#include "./time_scale.hpp"
#include "./var.hpp"

#include "parse/actions/apply/string.hpp"
#include "parse/actions/storage/function.hpp"

#include <string>

namespace VCD::Actions {

using namespace Parse;

struct VersionAction : single_dispatch<
    Grammar::string_before_end, apply<Apply::string>
> {
  using state = std::string;
};

struct DateAction : single_dispatch<
    Grammar::string_before_end, apply<Apply::string>
> {
  using state = std::string;
};

using HeaderVarFunctionType = void (HeaderReader::*)(VariableView);
using HeaderScopeFunctionType = void (HeaderReader::*)(ScopeDataView);
using HeaderTimeScaleFunctionType = void (HeaderReader::*)(TimeScaleView);

struct HeaderAction : multi_dispatch<
    Grammar::date_command, inner_action<
        DateAction, Storage::function<&HeaderReader::date>>,
    Grammar::timescale_command, inner_action<
        TimeScaleAction, Storage::function<
            static_cast<HeaderTimeScaleFunctionType>(&HeaderReader::timescale)>>,
    Grammar::version_command, inner_action<
        VersionAction, Storage::function<&HeaderReader::version>>,
    Grammar::scope_command, inner_action<
        ScopeAction,
        Storage::function<
            static_cast<HeaderScopeFunctionType >(&HeaderReader::scope)>>,
    Grammar::upscope_command, apply0<UpscopeApply>,
    Grammar::var_command, inner_action<
        VarAction,
        Storage::function<
            static_cast<HeaderVarFunctionType>(&HeaderReader::var)>>
> {
  using state = HeaderReader;
};

} // namespace VCD::Actions

#endif // LIBVCD_EVENTS_HEADER_HPP
