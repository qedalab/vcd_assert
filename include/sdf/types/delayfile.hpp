#ifndef LIBSDF_TYPES_DELAYFILE_HPP
#define LIBSDF_TYPES_DELAYFILE_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/cell.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/time_scale.hpp>
#include <sdf/types/values.hpp>

#include <optional>

namespace SDF {

/// Stores the SDF data.
/// Can only be populated with DelayFileReader
/// \related DelayFileReader
class DelayFile
{
  std::string sdf_version_;                   /// Version of the SDF file
  std::optional<std::string> design_name_;    /// Name of design being annotated
  std::optional<std::string> date_;           /// Date of SDF file creation
  std::optional<std::string> vendor_;         /// Vendor that supplied the SDF file
  std::optional<std::string> program_name_;   /// Name of program that created the SDF file
  std::optional<std::string> program_version_;/// Version of program that created the SDF file
  std::optional<std::string> process_;        /// Process specification
  std::optional<char> hierarchy_divider_;     /// Character used to separate hierarchial identifiers
  std::optional<Triple> voltage_;             /// Voltage specification
  std::optional<Triple> temperature_;         /// Temperature specification
  std::optional<TimeScale> timescale_;        /// Timescale specification
  std::vector<Cell> cells_;                   /// Cells of the SDF file

  friend class DelayFileReader;
// #ifdef DEBUG
//   friend TestDelayFile;
// #endif

public:
  // DelayFile();
  
  std::string_view get_sdf_version();

  /// Get the design_name if present
  /// \returns The design_name if present
  std::optional<std::string_view> get_design_name();
  
  /// True if the delayfile header contains a design_name
  /// \returns Whether the delayfile contains a design_name
  bool has_design_name() const noexcept;

  /// Get the date if present
  /// \returns The date if present
  std::optional<std::string_view> get_date();
  
  /// True if the delayfile header contains a date
  /// \returns Whether the delayfile contains a date
  bool has_date() const noexcept;

  /// Get the vendor if present
  /// \returns The vendor if present
  std::optional<std::string_view> get_vendor();
  
  /// True if the delayfile header contains a vendor
  /// \returns Whether the delayfile contains a vendor
  bool has_vendor() const noexcept;

  /// Get the program_name if present
  /// \returns The program_name if present
  std::optional<std::string_view> get_program_name();
  
  /// True if the delayfile header contains a program_name
  /// \returns Whether the delayfile contains a program_name
  bool has_program_name() const noexcept;

  /// Get the program_version if present
  /// \returns The program_version if present
  std::optional<std::string_view> get_program_version();
  
  /// True if the delayfile header contains a program_version
  /// \returns Whether the delayfile contains a program_version
  bool has_program_version() const noexcept;

  /// Get the process if present
  /// \returns The process if present
  std::optional<std::string_view> get_process();
  
  /// True if the delayfile header contains a process
  /// \returns Whether the delayfile contains a process
  bool has_process() const noexcept;

  /// Get the hierarchy_divider if present
  /// \returns The hierarchy_divider if present
  std::optional<char> get_hierarchy_divider();
  
  /// True if the delayfile header contains a hierarchy_divider
  /// \returns Whether the delayfile contains a hierarchy_divider
  bool has_hierarchy_divider() const noexcept;

  /// Get the voltage if present
  /// \returns The voltage if present
  std::optional<Triple> get_voltage();
  
  /// True if the delayfile header contains a voltage
  /// \returns Whether the delayfile contains a voltage
  bool has_voltage() const noexcept;

  /// Get the temperature if present
  /// \returns The temperature if present
  std::optional<Triple> get_temperature();
  
  /// True if the delayfile header contains a temperature
  /// \returns Whether the delayfile contains a temperature
  bool has_temperature() const noexcept;

  /// Get the timescale if present
  /// \returns The timescale if present
  std::optional<TimeScale> get_timescale();
  
  /// True if the delayfile header contains a timescale
  /// \returns Whether the delayfile contains a timescale
  bool has_timescale() const noexcept;

  // std::vector<Cell> get_cells() const noexcept;
  Cell& get_cell(std::size_t index);
  std::size_t num_cells() const noexcept;

  // TimingSpec &get_timingdelay(Unsupported::TimingDelay timing_delay);
  // std::size_t num_timing_delays();

  // TimingSpec &get_timingcheck(TimingCheck timing_check);
  // std::size_t num_timing_checks();

  // TimingSpec &get_timingenv(Unsupported::TimingEnv timing_env);
  // std::size_t num_timing_envs();

  // TimingSpec &get_timinglabel(Unsupported::TimingLabel timing_label);
  // std::size_t num_timing_labels();

};

 
} // namespace SDF

#endif // LIBSDF_TYPES_DELAYFILE_HPP