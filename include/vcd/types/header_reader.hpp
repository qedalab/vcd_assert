#ifndef LIBVCD_TYPES_HEADER_READER_HPP
#define LIBVCD_TYPES_HEADER_READER_HPP

#include "./enums.hpp"
#include "./header.hpp"

#include <memory>
#include <vector>

namespace VCD {

/// VCD header reader class
/// This class populates and returns a populated VCD::Header
class HeaderReader {
  std::unique_ptr<Header> header_;       /// Pointer to VCD Header
  std::vector<std::size_t> scope_stack_; /// Stack of current scopes

public:
  /// HeaderReader constructor
  HeaderReader();

  /// Introdocue a new scope
  void scope(ScopeType type, std::string name);

  /// Introduce a new scope
  void scope(ScopeDataView scope);

  /// Exits current scope
  void upscope();

  /// Adds a variable to the scope
  void var(VarType type, std::size_t size, std::string identifier_code,
           std::string reference);

  /// Adds a variable to the scope
  /// \param VariableView view of variable to add
  void var(VariableView variable);

  /// Set Header version string
  /// \param version_string The version string
  /// \exception Throws if and only if version is already set
  void version(std::string version_string);

  /// Set Header version string overwriting if it already exists
  /// \param version_string The version string
  void overwrite_version(std::string version_string) noexcept;

  /// True if the current header contains version information
  /// \returns Wether the current header contains version information
  bool has_version() const noexcept;

  /// Set the header date
  /// \param date_string The date string
  /// \exception Throws if and only if date is already set
  void date(std::string date_string);

  /// Set the header date overwriting if is alreadt set
  /// \param date_string The date string
  void overwrite_date(std::string date_string) noexcept;

  /// True if the current header contains a date
  /// \returns Wether the current header contains a date
  bool has_date() const noexcept;

  /// Set header time scale
  /// \param number The time scale number
  /// \param unit The time unit number
  /// \exception Throws if and only if time scale is already set
  void timescale(TimeNumber number, TimeUnit unit);

  /// Set header time scale
  /// \param timescale The time scale
  /// \exception Throws if and only if time scale is already set
  void timescale(TimeScaleView time_scale);

  /// Set the header time scale, overwriting if already set
  /// \param number The time scale number
  /// \param unit The time unit number
  void overwrite_timescale(TimeNumber number, TimeUnit unit) noexcept;

  /// True if the current header contains a time scale
  /// \returns Wether the current header contains a time scale
  bool has_timescale() const noexcept;

  /// Releases the header file that was read in.
  /// Essentially finalizaing the data within the header file.
  /// \returns Owning pointer to the Header
  /// \exception Throws if all there is still scope in the stack.
  Header release();
};

}

#endif // LIBVCD_TYPES_HEADER_READER_HPP
