// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
