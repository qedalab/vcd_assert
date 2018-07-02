#ifndef LIBPARSE_TEST_DEBUG_EXCEPTION_HPP
#define LIBPARSE_TEST_DEBUG_EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include <vector>

namespace Parse::Test {

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

} // namespace Parse::Test

#endif // LIBPARSE_TEST_DEBUG_EXCEPTION_HPP
