#ifndef LIBSDF_TYPES_DELAYFILE_HPP
#define LIBSDF_TYPES_DELAYFILE_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/cell.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/time_scale.hpp>
#include <sdf/types/values.hpp>

#include <optional>

namespace SDF {


struct DelayFileView
{
  std::string sdf_version;                        
  std::optional<std::string> design_name;         
  std::optional<std::string> date;                
  std::optional<std::string> vendor;              
  std::optional<std::string> program_name;        
  std::optional<std::string> program_version;     
  std::optional<std::string> process;             
  std::optional<HChar> hierarchy_divider;         
  std::optional<Triple> voltage;                  
  std::optional<Triple> temperature;              
  std::optional<TimeScale> timescale;             
  std::vector<Cell> cells;                        
};

namespace Test {
  struct DelayFileTester;
}

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
  std::optional<HChar> hierarchy_divider_;     /// Character used to separate hierarchial identifiers
  std::optional<Triple> voltage_;             /// Voltage specification
  std::optional<Triple> temperature_;         /// Temperature specification
  std::optional<TimeScale> timescale_;        /// Timescale specification
  std::vector<Cell> cells_;                   /// Cells of the SDF file

  friend class DelayFileReader;
  friend struct Test::DelayFileTester;
private: 
  DelayFile(DelayFileView dfw) 
  : sdf_version_(dfw.sdf_version),
    design_name_(dfw.design_name),
    date_(dfw.date),
    vendor_(dfw.vendor),
    program_name_(dfw.program_name),
    program_version_(dfw.program_version),
    process_(dfw.process),
    hierarchy_divider_(dfw.hierarchy_divider),
    voltage_(dfw.voltage),
    temperature_(dfw.temperature),
    timescale_(dfw.timescale),
    cells_(dfw.cells){};
public:
  DelayFile() = default;
  // {
  //   assert(sdf_version_.has_value());
  // };

  std::string_view get_sdf_version() const noexcept;

  /// Get the design_name if present
  /// \returns The design_name if present
  std::optional<std::string_view> get_design_name() const noexcept;
  
  /// True if the delayfile header contains a design_name
  /// \returns Whether the delayfile contains a design_name
  bool has_design_name() const noexcept;

  /// Get the date if present
  /// \returns The date if present
  std::optional<std::string_view> get_date() const noexcept;
  
  /// True if the delayfile header contains a date
  /// \returns Whether the delayfile contains a date
  bool has_date() const noexcept;

  /// Get the vendor if present
  /// \returns The vendor if present
  std::optional<std::string_view> get_vendor() const noexcept;
  
  /// True if the delayfile header contains a vendor
  /// \returns Whether the delayfile contains a vendor
  bool has_vendor() const noexcept;

  /// Get the program_name if present
  /// \returns The program_name if present
  std::optional<std::string_view> get_program_name() const noexcept;
  
  /// True if the delayfile header contains a program_name
  /// \returns Whether the delayfile contains a program_name
  bool has_program_name() const noexcept;

  /// Get the program_version if present
  /// \returns The program_version if present
  std::optional<std::string_view> get_program_version() const noexcept;
  
  /// True if the delayfile header contains a program_version
  /// \returns Whether the delayfile contains a program_version
  bool has_program_version() const noexcept;

  /// Get the process if present
  /// \returns The process if present
  std::optional<std::string_view> get_process() const noexcept;
  
  /// True if the delayfile header contains a process
  /// \returns Whether the delayfile contains a process
  bool has_process() const noexcept;

  /// Get the hierarchy_divider if present
  /// \returns The hierarchy_divider if present
  std::optional<HChar> get_hierarchy_divider() const noexcept;
  
  /// True if the delayfile header contains a hierarchy_divider
  /// \returns Whether the delayfile contains a hierarchy_divider
  bool has_hierarchy_divider() const noexcept;

  /// Get the voltage if present
  /// \returns The voltage if present
  std::optional<Triple> get_voltage() const noexcept;
  
  /// True if the delayfile header contains a voltage
  /// \returns Whether the delayfile contains a voltage
  bool has_voltage() const noexcept;

  /// Get the temperature if present
  /// \returns The temperature if present
  std::optional<Triple> get_temperature() const noexcept;
  
  /// True if the delayfile header contains a temperature
  /// \returns Whether the delayfile contains a temperature
  bool has_temperature() const noexcept;

  /// Get the timescale if present
  /// \returns The timescale if present
  std::optional<TimeScale> get_timescale() const noexcept;
  
  /// True if the delayfile header contains a timescale
  /// \returns Whether the delayfile contains a timescale
  bool has_timescale() const noexcept;

  /// Get all cells  
  std::vector<Cell> get_cells() const noexcept;

  /// Get a cell  
  Cell& get_cell(std::size_t index); //todo: rather output CellView?
  std::size_t num_cells() const noexcept;

  /// Get all cell indices by cell type 
  /// \param type The cell type string
  /// \returns The cell indices
  std::vector<std::size_t> get_cell_indices_by_type(std::string &cell_type) const noexcept;

  /// Get all cell indices by cell instance string
  /// \param type The cell type string
  /// \returns The cell indices
  std::vector<std::size_t> get_cell_indices_by_instance(CellInstance &cell_instance) const noexcept;

  /// TEMPORORARY Get the double value of the input Value, based on mintypmax if Triple.
  /// \param value The sdf Value containing either Number or Triple
  /// \returns The double if there was one. 
  std::optional<double> get_value_content(Value &value) const noexcept;

  /// \param type The cell type sting
  /// \returns The cell indices
  // TimingSpec &get_timingdelay(Unsupported::TimingDelay timing_delay);
  // std::size_t num_timing_delays();

  // TimingSpec &get_timingcheck(TimingCheck timing_check);
  // std::size_t num_timing_checks();

  // TimingSpec &get_timingenv(Unsupported::TimingEnv timing_env);
  // std::size_t num_timing_envs();

  // TimingSpec &get_timinglabel(Unsupported::TimingLabel timing_label);
  // std::size_t num_timing_labels();

};

namespace Test {
  // using namespace SDF;
  struct DelayFileTester{
    SDF::DelayFile get_test_delayfile(SDF::DelayFileView dfw) const{
      return SDF::DelayFile(dfw);
    }
  };
} // namespace Test
 
} // namespace SDF


// class DelayFile;
#endif // LIBSDF_TYPES_DELAYFILE_HPP
