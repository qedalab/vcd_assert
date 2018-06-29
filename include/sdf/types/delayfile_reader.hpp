#ifndef LIBSDF_TYPES_DELAYFILE_READER_HPP
#define LIBSDF_TYPES_DELAYFILE_READER_HPP

#include <sdf/types/delayfile.hpp>
#include <sdf/types/enums.hpp>

#include <vector>
#include <memory>

namespace VCD {

class DelayFileReader {
  std::unique_ptr<DelayFile> delayfile_;

  std::vector<std::size_t> scope_stack_;
public:
  DelayFileReader();

  void scope(ScopeType type, std::string name);
  void upscope();
  void var(VarType type, std::size_t size, std::string identifier_code, std::string reference);

  sdf_version(std::string sdf_version_string );

  design_name(std::string design_name_string );
  // bool has_design_name(); optional implicitly covers this..

  date(std::string date_string );
  // bool has_date(); optional implicitly covers this..

  vendor(std::string vendor_string );
  // bool has_vendor(); optional implicitly covers this..

  program_name(std::string program_name_string );
  // bool has_program_name(); optional implicitly covers this..

  program_version(std::string program_version_string );
  // bool has_program_version(); optional implicitly covers this..

  process(std::string process_string );
  // bool has_process(); optional implicitly covers this..

  hierarchy_divider(std::string hierarchy_divider_string );
  // bool has_hierarchy_divider(); optional implicitly covers this..

  voltage(std::string voltage_string );
  // bool has_voltage(); optional implicitly covers this..

  temperature(std::string temperature_string );
  // bool has_temperature(); optional implicitly covers this..

  time_scale(std::string time_scale_string );


  void version(std::string version_string);
  void overwrite_version(std::string version_string);
  bool has_version();

  void date(std::string date_string);
  void overwrite_date(std::string date_string);
  bool has_date();

  void timescale(TimeNumber number, TimeUnit unit);
  void overwrite_timescale(TimeNumber number, TimeUnit unit);
  bool has_timescale();

  std::unique_ptr<DelayFile> release();
};

}

#endif //LIBSDF_TYPES_HEADER_BUILDER_HPP
