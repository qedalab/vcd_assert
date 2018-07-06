#ifndef LIBSDF_SERIALIZE_VALUES_HPP
#define LIBSDF_SERIALIZE_VALUES_HPP

#include <sdf/serialize/base.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <fmt/format.h>
#include <range/v3/algorithm/copy.hpp>
#include <string_view>
#include <variant>
#include <fmt/printf.h>

namespace SDF {

/*
TimingCheckType get_enum_type() const {

    return std::visit([](auto&& param) -> TimingCheckType {

      using T = typename std::decay<decltype(param)>::type;

      if constexpr (std::is_same_v<T, Unsupported::Setup>) {
          return TimingCheckType::setup;
      } else if constexpr (std::is_same_v<T, Hold>) {
          return TimingCheckType::hold;
      } else if constexpr (std::is_same_v<T, Unsupported::Setuphold>) {
          return TimingCheckType::setuphold;
      } else if constexpr (std::is_same_v<T, Unsupported::Recovery>) {
          return TimingCheckType::recovery;
      } else if constexpr (std::is_same_v<T, Unsupported::Removal>) {
          return TimingCheckType::removal;
      } else if constexpr (std::is_same_v<T, Unsupported::Recrem>) {
          return TimingCheckType::recrem;
      } else if constexpr (std::is_same_v<T, Unsupported::Skew>) {
          return TimingCheckType::skew;
      } else if constexpr (std::is_same_v<T, Unsupported::Bidirectskew>) {
          return TimingCheckType::bidirectskew;
      } else if constexpr (std::is_same_v<T, Unsupported::Width>) {
          return TimingCheckType::width;
      } else if constexpr (std::is_same_v<T, Unsupported::Period>) {
          return TimingCheckType::period;
      } else if constexpr (std::is_same_v<T, Unsupported::Nochange>) {
          return TimingCheckType::nochange;
      } else {
          static_assert(Parse::Util::dependant_value<false, T>);
      }
    }, value);
  }
*/

/// Serialize SDF timing spec
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The SDF file timing specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_number(OutputIterator oi, int indent,
                      Number n) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;
  // std::setprecision(std::numeric_limits<double>::digits10)
  // std::to_string
  ranges::copy(fmt::sprintf("%g", n), oi);
}


/// Serialize SDF timing spec
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The SDF file timing specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_triple(OutputIterator oi, int indent,
                      Triple t) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  serialize_number(oi,t.min);
  ranges::copy(":"sv, oi);
  serialize_number(oi,t.typ);
  ranges::copy(":"sv, oi);
  serialize_number(oi,t.max);
}

// /// Serialize SDF timing spec
// /// \tparam OutputIterator must meet the requirements of OutputIterator
// /// \param oi The OutputIterator being written to
// /// \param ts The SDF file timing specification to write
// /// \exception Throws if writing to the OutputIterator throws otherwise noexcept
// template <class OutputIterator>
// void serialize_number(OutputIterator oi, int indent,
//                       Number n) noexcept(noexcept(*oi++ = '!')) {
//   using std::literals::string_view_literals::operator""sv;
//   // std::setprecision(std::numeric_limits<double>::digits10)
//   // std::to_string
//   ranges::copy(std::to_string(n), oi);
// }



/// Serialize SDF timing spec
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The SDF file timing specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_value(OutputIterator oi, int indent,
                               Value v) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("("sv, oi);
  if (std::holds_alternative<Number>(v)) {
    // Number x = std::get<Number>(v);
    serialize_number(oi, indent, std::get<Number>(v));
  } else if (std::holds_alternative<Triple>(v)) {
    // Triple x = v;
    serialize_triple(oi, indent, std::get<Triple>(v));
  } else {
    throw std::runtime_error("InternalError");
  }
  ranges::copy(")"sv, oi);
}

} // namespace SDF

#endif //# LIBSDF_SERIALIZE_VALUES_HPP