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
