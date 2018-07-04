#ifndef LIBSDF_TYPES_DELAYFILE_READER_HPP
#define LIBSDF_TYPES_DELAYFILE_READER_HPP

#include <sdf/types/delayfile.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/cell.hpp>
#include <sdf/types/time_scale.hpp>

#include <vector>
#include <memory>


namespace SDF {

class DelayFileReader {
  
  std::unique_ptr<DelayFile> delayfile_;

public:
  DelayFileReader();

  /// Set the delayfile sdf_version
  /// \param sdf_version The sdf_version string
  void sdf_version(std::string sdf_version) noexcept;
  
  /// True if the current delayfile contains a sdf_version
  /// \returns Whether the current delayfile contains a sdf_version
  bool has_sdf_version() const noexcept;

  /// Set the delayfile design_name
  /// \param design_name The design_name string
  /// \exception Throws if and only if design_name is already set
  void design_name(std::string design_name);
  
  /// True if the current delayfile contains a design_name
  /// \returns Whether the current delayfile contains a design_name
  bool has_design_name() const noexcept;
  /// Set the delayfile date
  /// \param date The date string
  /// \exception Throws if and only if date is already set
  void date(std::string date);

  /// True if the current delayfile contains a date
  /// \returns Whether the current delayfile contains a date
  bool has_date() const noexcept;

  /// Set the delayfile vendor
  /// \param vendor The delayfile vendor
  /// \exception Throws if and only if vendor is already set
  void vendor(std::string vendor);

  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_vendor() const noexcept;

  /// Set the delayfile program_name
  /// \param program_name The delayfile program_name
  /// \exception Throws if and only if program_name is already set
  void program_name(std::string program_name);

  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_program_name() const noexcept;

  /// Set DelayFile program_version string
  /// \param version The version string
  /// \exception Throws if and only if program version is already set
  void program_version(std::string program_version);

  /// True if the current delayfile contains program_version information
  /// \returns Whether the current delayfile contains program_version information
  bool has_program_version() const noexcept;

  /// Set the delayfile process
  /// \param process The delayfile process
  /// \exception Throws if and only if process is already set
  void process(std::string process);
  
  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_process() const noexcept;
  
  /// Set the delayfile hierarchy_divider
  /// \param hierarchy_divider The delayfile hierarchy_divider
  /// \exception Throws if and only if hierarchy_divider is already set
  void hierarchy_divider(char hierarchy_divider);
  
  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_hierarchy_divider() const noexcept;
  
  /// Set the delayfile voltage
  /// \param voltage The delayfile voltage
  /// \exception Throws if and only if voltage is already set
  void voltage(Triple voltage);
  
  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_voltage() const noexcept;
  
  /// Set the delayfile temperature
  /// \param temperature The delayfile temperature
  /// \exception Throws if and only if temperature is already set
  void temperature(Triple temperature);
  
  /// True if the current delayfile contains a xxx
  /// \returns Whether the current delayfile contains a xxx
  bool has_temperature() const noexcept;
  
  /// Set delayfile timescale
  /// \param number The timescale number
  /// \param unit The timescale unit
  /// \exception Throws if and only if timescale is already set
  void timescale(TimeScaleNumber number, TimeScaleUnit unit);

  /// Set delayfile timescale
  /// \param timescale The timescale
  /// \exception Throws if and only if timescale is already set
  void timescale(TimeScaleView timescale);

  /// True if the current delayfile contains a timescale
  /// \returns Whether the current delayfile contains a timescale
  bool has_timescale() const noexcept;

  /// Set the delayfile cells
  /// \param cells The delayfile cells
  /// \exception Throws if and only if cells is already set
  void cells(std::vector<Cell> cells);

  /// True if the current delayfile contains a cells
  /// \returns Whether the current delayfile contains a cells
  bool has_cells() const noexcept;

  /// Add delayfile cell
  /// \param cell The delayfile cell
  void add_cell(Cell cell) const noexcept; //todo remove

  /// Releases the delayfile file that was read in.
  /// Essentially finalizing the data within the delayfile file.
  /// \returns Owning pointer to the DelayFile
  /// \exception Throws if sdf_version and cells have not yet been set.
  std::unique_ptr<DelayFile> release();
};

}

#endif //LIBSDF_TYPES_DELAYFILE_READER_HPP
