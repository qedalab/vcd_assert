#ifndef LIBSDF_TYPES_DELAYFILE_H_
#define LIBSDF_TYPES_DELAYFILE_H_

#include <sdf/types/timingdelay.hpp>
#include <sdf/types/values.hpp>
#include <sdf/types/variant.hpp>

namespace SDF {
namespace Types {


struct DelayFile {
  std::string sdf_version;
  std::optional<std::string> design_name;
  std::optional<std::string> date;
  std::optional<std::string> vendor;
  std::optional<std::string> program_name;
  std::optional<std::string> program_version;
  std::optional<std::string> process;
  std::optional<char> hierarchy_divider;
  std::optional<Triple> voltage;
  std::optional<Triple> temperature;
  std::optional<Timescale> time_scale;
  std::vector<Cell> cells;
}

// class DelayFile
// {
//   // std::string file_path_;
//   std::string sdf_version_;
//   std::optional<std::string> design_name_;
//   std::optional<std::string> date_;
//   std::optional<std::string> vendor_;
//   std::optional<std::string> program_name_;
//   std::optional<std::string> program_version_;
//   std::optional<std::string> process_;
//   std::optional<char> hierarchy_divider_;
//   std::optional<Triple> voltage_;
//   std::optional<Triple> temperature_;
//   std::optional<Timescale> time_scale_;
//   std::vector<Cell> cells_;

//   friend class DelayFileReader;

// public:
//   std::string_view get_sdf_version();

//   std::optional<std::string_view> get_design_name();
//   // bool has_design_name(); optional implicitly covers this..

//   std::optional<std::string_view> get_date();
//   // bool has_date(); optional implicitly covers this..

//   std::optional<std::string_view> get_vendor();
//   // bool has_vendor(); optional implicitly covers this..

//   std::optional<std::string_view> get_program_name();
//   // bool has_program_name(); optional implicitly covers this..

//   std::optional<std::string_view> get_program_version();
//   // bool has_program_version(); optional implicitly covers this..

//   std::optional<std::string_view> get_process();
//   // bool has_process(); optional implicitly covers this..

//   std::optional<char> get_hierarchy_divider();
//   // bool has_hierarchy_divider(); optional implicitly covers this..

//   std::optional<Triple> get_voltage();
//   // bool has_voltage(); optional implicitly covers this..

//   std::optional<Triple> get_temperature();
//   // bool has_temperature(); optional implicitly covers this..

//   std::optional<Timescale> get_time_scale();
//   // bool has_time_scale(); optional implicitly covers this..

//   Cell &get_cell(std::size_t index);

//   Delay &get_timingdelay(std::string hierarchy);
//   TimingCheck &get_timingcheck(std::string hierarchy);
//   TimingEnv &get_timingenv(std::string hierarchy);
//   Label &get_timinglabel(std::string hierarchy);

//   std::size_t num_scopes();
// };


// class DelayFileReader {
//   std::unique_ptr<DelayFile> delayfile_;
//   std::vector<std::size_t> scope_stack_;
// public:
//   DelayFileReader();

//   void scope(ScopeType type, std::string name);
//   void upscope();
//   void var(VarType type, std::size_t size, std::string identifier_code, std::string reference);

//   sdf_version(std::string sdf_version_string );

//   design_name(std::string design_name_string );
//   // bool has_design_name(); optional implicitly covers this..

//   date(std::string date_string );
//   // bool has_date(); optional implicitly covers this..

//   vendor(std::string vendor_string );
//   // bool has_vendor(); optional implicitly covers this..

//   program_name(std::string program_name_string );
//   // bool has_program_name(); optional implicitly covers this..

//   program_version(std::string program_version_string );
//   // bool has_program_version(); optional implicitly covers this..

//   process(std::string process_string );
//   // bool has_process(); optional implicitly covers this..

//   hierarchy_divider(std::string hierarchy_divider_string );
//   // bool has_hierarchy_divider(); optional implicitly covers this..

//   voltage(std::string voltage_string );
//   // bool has_voltage(); optional implicitly covers this..

//   temperature(std::string temperature_string );
//   // bool has_temperature(); optional implicitly covers this..

//   time_scale(std::string time_scale_string );


//   void version(std::string version_string);
//   void overwrite_version(std::string version_string);
//   bool has_version();

//   void date(std::string date_string);
//   void overwrite_date(std::string date_string);
//   bool has_date();

//   void timescale(TimeNumber number, TimeUnit unit);
//   void overwrite_timescale(TimeNumber number, TimeUnit unit);
//   bool has_timescale();

//   std::unique_ptr<DelayFile> release();
// };



} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_DELAYFILE_H_