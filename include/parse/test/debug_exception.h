#ifndef PARSE_TEST_DEBUG_EXCEPTION_H
#define PARSE_TEST_DEBUG_EXCEPTION_H

#include <stdexcept>
#include <vector>
#include <string>

namespace Parse {

struct DebugState {
  std::string rule;
  size_t line, col;

  std::string to_string();
};

class DebugException : public std::exception {
  std::vector<DebugState> states_ {};
  std::string msg_;
  std::string what_str_ {};
  bool is_oom_ = false;

  void create_what_str();

  void handle_oom();

public:
  DebugException(std::string msg);

  void add_trace(DebugState&& trace);

  const char* what() const noexcept override;
};

}

#endif //PARSE_DEBUG_EXCEPTION_H
