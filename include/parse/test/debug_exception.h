//
// Created by xonar on 2018/05/24.
//

#ifndef PARSE_TEST_DEBUG_EXCEPTION_H
#define PARSE_TEST_DEBUG_EXCEPTION_H

#include <stdexcept>
#include <vector>
#include <string>

namespace Parse {

struct DebugState {
  std::string rule;
  size_t line, col;

  std::string to_string() {
    return rule + " at " + "(" + std::to_string(line) + ":" + std::to_string(col) + ")\n";
  }
};

class DebugException : public std::exception {
  std::vector<DebugState> states_;
  std::string msg_;
  std::string what_str_;
  bool is_oom_ = false;

  void create_what_str() {
    if(!what_str_.empty() || is_oom_)
      return;

    try {
      what_str_ = "Debug Trace:\n  ";
      what_str_.append(msg_);
      what_str_.append("\n\n");

      for(auto &state: states_) {
        what_str_ +=  "  " + state.to_string();
      }
    } catch (const std::bad_alloc &ba) {
      handle_oom();
    }
  }

  void handle_oom() {
    is_oom_ = true;
    states_.clear();
    what_str_.clear();
  }

public:
  DebugException(const std::string msg) : msg_(std::move(msg)) {}

  void add_trace(DebugState&& trace) {
    if(!is_oom_) {
      try {
        states_.emplace_back(std::move(trace));
        what_str_.clear();
        create_what_str();
      } catch (const std::bad_alloc &ba) {
        handle_oom();
      }
    }
  }

  const char* what() const throw() {

    if(is_oom_) {
      return "Debug Trace: Out of memory: trace unavailable";
    }

    return what_str_.data();
  }
};

}

#endif //PARSE_DEBUG_EXCEPTION_H
