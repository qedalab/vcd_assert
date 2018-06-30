#ifndef LIBVCD_TYPES_HEADER_HPP
#define LIBVCD_TYPES_HEADER_HPP

#include "./time_scale.hpp"
#include "./variable.hpp"
#include "./var_id_code.hpp"
#include "./scope.hpp"

#include "parse/util/name_index_map.hpp"

#include <string>
#include <string_view>
#include <vector>
#include <optional>

namespace VCD {

/// Stores the VCD definition information.
/// Allows for efficient lookups for common access pattern. Also efficient when
/// being read in from file or similar data structure. Can only be populated
/// with HeaderReader
/// \related HeaderReader
class Header
{
  std::optional<TimeScale> time_scale_; /// Time scale of VCD file
  std::optional<std::string> date_;     /// Date of VCD file
  std::optional<std::string> version_;  /// Version of simulator

  Parse::Util::NameIndexMap var_id_code_map_; /// 'identifier code' <-> 'index' lookup

  std::vector<VarIdCode> id_codes_;     /// Identifier codes
  std::vector<Variable> variables_;     /// Variable
  std::vector<Scope> scopes_;           /// Scopes

  friend class HeaderReader;

public:
  /// Get the time scale if present
  /// \returns The time scale if present
  std::optional<TimeScale> get_time_scale() const noexcept;

  /// True if the header contains a time scale
  /// \returns Wether the header contains a time scale
  bool has_time_scale() const noexcept;

  /// Get the date if present
  /// \returns The date if present
  std::optional<std::string_view> get_date() const noexcept;

  /// True if the header contains a date
  /// \returns Wether the header contains a date
  bool has_date() const noexcept;

  /// Get the version information if present
  /// \returns The version information if present
  std::optional<std::string_view> get_version() const noexcept;

  /// True if header contains version information
  /// \returns Wether the header contains version information
  bool has_version() const noexcept;

  /// Get variable by index
  /// \param index the variable index
  Variable &get_var(std::size_t index);

  /// Get scope by index
  /// \param index the scope index
  /// \returns the scope
  Scope &get_scope(std::size_t index);

  /// Get the first scope defined in the header
  /// \returns the root scope
  Scope &get_root_scope();

  /// Get the identifier code index by string
  /// \param id_code the identifier code string
  /// \returns the identifier code index
  std::size_t get_var_id_code_index(std::string &id_code) const;

  /// Get the identifier code by index
  /// \param index the identifier code index
  /// \returns the identifier code
  VarIdCode &get_var_id_code(std::size_t index);

  /// True if header contains the identifier code
  /// \param id_code the identifier code string
  /// \returns Wether the header contains the identifier code
  bool has_var_id_code(std::string &id_code) const noexcept;

  /// Returns the number of scopes defined in the header
  /// \returns the number of scopes defined in the header
  std::size_t num_scopes() const noexcept;

  /// Returns the number of variables defined in the header
  /// \returns the number of scopes defined in the header
  std::size_t num_variables() const noexcept;

  /// Returns the number of identifier codes defined in the header
  /// \returns the number of identifier code define din the header
  std::size_t num_id_codes() const noexcept;
};

} // namespace VCD

#endif // LIBVCD_TYPES_HEADER_HPP
