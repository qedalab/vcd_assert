#ifndef LIBSDF_SERIALIZE_DELAYFILE_HPP
#define LIBSDF_SERIALIZE_DELAYFILE_HPP

// #include <sdf/serialize/enum/time_scale.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

/// Serialize SDF header
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param sdf_version The sdf_version to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_delayfile(OutputIterator oi,
                         DelayFile df) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("(DELAYFILE \n"sv, oi);
  serialize_sdf_version(oi, 1, df.get_sdf_version());
  if (df.has_design_name()) {
    serialize_design_name(oi, df.get_design_name());
  }
  if (df.has_date()) {
    serialize_date(oi, 1, df.get_date());
  }
  if (df.has_vendor()) {
    serialize_vendor(oi, 1, df.get_vendor());
  }
  if (df.has_program_name()) {
    serialize_program_name(oi, 1, df.get_program_name());
  }
  if (df.has_program_version()) {
    serialize_program_version(oi, 1, df.get_program_version());
  }
  if (df.has_hierarchy_divider()) {
    serialize_hierarchy_divider(oi, 1, df.get_hierarchy_divider());
  }
  if (df.has_voltage()) {
    serialize_voltage(oi, 1, df.get_voltage());
  }
  if (df.has_process()) {
    serialize_process(oi, 1, df.get_process());
  }
  if (df.has_temperature()) {
    serialize_temperature(oi, 1, df.get_temperature());
  }
  if (df.has_timescale()) {
    serialize_timescale(oi, 1, df.get_timescale());
  }
  serialize_cells(oi, 1, df.get_cells());
  ranges::copy(")\n"sv, oi);
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_HEADER_HPP
