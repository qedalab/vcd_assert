#ifndef LIBVCD_TYPES_HEADER_HPP
#define LIBVCD_TYPES_HEADER_HPP

#include "./time_scale.hpp"
#include "./variable.hpp"
#include "./var_id_code.hpp"
#include "./scope.hpp"

#include "parse/util/name_index_map.hpp"

#include <string>
#include <vector>
#include <optional>

namespace VCD {

class Header {
  std::optional<TimeScale> time_scale_;
  std::optional<std::string> date_;
  std::optional<std::string> version_;

  Parse::NameIndexMap var_id_code_map_;

  std::vector<VarIdCode> id_codes_;
  std::vector<Variable> variables_;
  std::vector<Scope> scopes_;

  friend class HeaderReader;
  friend class HeaderWriter;

public:
  std::optional<TimeScale> get_time_scale();
  bool has_time_scale();

  std::optional<std::string_view> get_date();
  bool has_date();

  std::optional<std::string_view> get_version();
  bool has_version();

  Variable &get_var(std::size_t index);

  Scope &get_scope(std::size_t index);
  Scope &get_root_scope();

  std::size_t get_var_id_code_index(std::string &id_code);
  VarIdCode& get_var_id_code(std::size_t index);
  bool has_var_id_code(std::string &id_code);


  std::size_t num_scopes();
  std::size_t num_variables();
  std::size_t num_id_codes();
};

} // namespace VCD

#endif //LIBVCD_TYPES_HEADER_HPP
