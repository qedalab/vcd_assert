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

#include "parse/test/debug_exception.hpp"

using namespace Parse::Test;

std::string DebugState::to_string()
{
  return rule + " at " + "(" + std::to_string(line) + ":" +
         std::to_string(col) + ")\n";
}

void DebugException::create_what_str()
{
  if (!what_str_.empty() || is_oom_)
    return;

  try {
    what_str_ = "Debug Trace:\n  ";
    what_str_.append(msg_);
    what_str_.append("\n\n");

    for (auto &state : states_) {
      what_str_ += "  " + state.to_string();
    }
  } catch (const std::bad_alloc &ba) {
    handle_oom();
  }
}

void DebugException::handle_oom()
{
  is_oom_ = true;
  states_.clear();
  what_str_.clear();
}

DebugException::DebugException(std::string msg) : msg_(std::move(msg))
{
  // Empty
}

void DebugException::add_trace(DebugState &&trace)
{
  if (!is_oom_) {
    try {
      states_.emplace_back(std::move(trace));
      what_str_.clear();
      create_what_str();
    } catch (const std::bad_alloc &ba) {
      handle_oom();
    }
  }
}

const char *DebugException::what() const noexcept
{
  if (is_oom_) {
    return "Debug Trace: Out of memory: trace unavailable";
  }

  return what_str_.data();
}
