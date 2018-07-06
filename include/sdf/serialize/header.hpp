#ifndef LIBSDF_SERIALIZE_HEADER_HPP
#define LIBSDF_SERIALIZE_HEADER_HPP

#include <sdf/serialize/base.hpp>
#include <sdf/serialize/values.hpp>
#include <sdf/serialize/enum/base.hpp>
#include <sdf/serialize/enum/time_scale.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>
#include <sdf/types/time_scale.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

/// Serialize SDF sdf_version
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param sdf_version The sdf_version to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_sdf_version(OutputIterator oi, int indent, std::string_view sdf_version) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(SDFVERSION "sv, oi);
  serialize_quoted(oi, sdf_version);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF design_name
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param design_name The SDF file design_name to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_design_name(OutputIterator oi, int indent, std::string_view design_name) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(DESIGN "sv, oi);
  serialize_quoted(oi, design_name);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF date
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param date The SDF file date to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_date(OutputIterator oi, int indent, std::string_view date) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(DATE "sv, oi);
  serialize_quoted(oi, date);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF vendor
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param vendor The SDF file vendor to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_vendor(OutputIterator oi, int indent, std::string_view vendor) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(VENDOR "sv, oi);
  serialize_quoted(oi, vendor);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF program_name
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param program_name The SDF file program_name to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_program_name(OutputIterator oi, int indent, std::string_view program_name) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(PROGRAM "sv, oi);
  serialize_quoted(oi, program_name);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF program_version
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param program_version The SDF file program_version to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_program_version(OutputIterator oi, int indent, std::string_view program_version) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(VERSION "sv, oi);
  serialize_quoted(oi, program_version);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF hierarchy_divider
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param hierarchy_divider The SDF file hierarchy_divider to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_hierarchy_divider(OutputIterator oi, int indent, HChar hierarchy_divider) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(DIVIDER "sv, oi);
  ranges::copy(hierarchy_divider_to_string(hierarchy_divider),oi);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF voltage
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param voltage The SDF file voltage to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_voltage(OutputIterator oi, int indent, Triple voltage) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(VOLTAGE "sv, oi);
  serialize_triple(oi, indent, voltage);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF process
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param process The SDF file process to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_process(OutputIterator oi, int indent, std::string_view process) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(PROCESS "sv, oi);
  serialize_quoted(oi, process);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF temperature
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param temperature The SDF file temperature to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_temperature(OutputIterator oi, int indent, Triple temperature) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(TEMPERATURE "sv, oi);
  serialize_triple(oi, 0, temperature);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF timescale
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timescale(OutputIterator oi, int indent, TimeScale timescale) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(TIMESCALE "sv, oi);
  ranges::copy(timescale_number_to_string(timescale.get_number()), oi);
  ranges::copy(timescale_unit_to_string(timescale.get_unit()), oi);
  ranges::copy(")\n"sv, oi);
}


} // namespace SDF

#endif // LIBSDF_SERIALIZE_HEADER_HPP
