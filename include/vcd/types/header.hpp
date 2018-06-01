#ifndef LIBVCD_TYPES_HEADER_HPP
#define LIBVCD_TYPES_HEADER_HPP

#include "./time_scale.hpp"
#include "./variable.hpp"
#include "./scope.hpp"

#include "parse/util/name_index_map.hpp"

#include <string>
#include <vector>
#include <optional>

namespace VCD {

class VCDHeader {
  std::optional<TimeScale> time_scale_;
  std::optional<std::string> date_;
  std::optional<std::string> version_;

  Parse::NameIndexMap reference_lookup_;
  std::vector<VCDVariable> variables_;
  std::vector<VCDScope> scope_;

  friend class VCDHeaderSerialFactory;
public:
  std::optional<TimeScale> get_time_scale();
  bool has_time_scale();

  std::optional<std::string> get_date();
  bool has_date();

  std::optional<std::string> get_version();
  bool has_version();

  VCDVariable &get_variable(std::size_t index);

  VCDScope &get_scope(std::size_t index);
  VCDScope &get_root_scope();

  std::size_t get_reference_index(std::string reference);

  std::size_t num_scopes();
  std::size_t num_variables();
};

} // namespace VCD

#endif //LIBVCD_TYPES_HEADER_HPP
