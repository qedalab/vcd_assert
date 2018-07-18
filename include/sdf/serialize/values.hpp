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
using namespace fmt::literals;

#include <math.h>       /* modf */

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
          static_assert(Parse::Util::dependent_value<false, T>);
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
void serialize_number(OutputIterator oi, int /*unused*/,
                      Number n) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(fmt::sprintf(" %.g",n), oi);
}

/// Serialize SDF timing spec
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The SDF file timing specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_triple(OutputIterator oi, int /*indent*/,
                      Triple t, int places = -1) noexcept(noexcept(*oi++ = '!')) {
  if(places == -1){
    double intpart;
    double fracpart_min = std::modf(t.min, &intpart);
    double fracpart_typ = std::modf(t.typ, &intpart);
    double fracpart_max = std::modf(t.max, &intpart);
    auto s_min = fmt::sprintf("%.g",fracpart_min);
    auto s_typ = fmt::sprintf("%.g",fracpart_typ);
    auto s_max = fmt::sprintf("%.g",fracpart_max);
    // throw std::runtime_error(fmt::format("({})\n({})\n({})\n", s_min.size(),s_typ.size(),s_max.size()));
    for(auto&& i : {s_min,s_typ,s_max})
    {
      if(static_cast<int>(i.size()) > places){
        places = static_cast<int>(i.size());
      }
    }
    if(places<0)
      throw std::runtime_error(fmt::format("InternalError decimal places negative ({})",places));

    if(places >1){
      places = places-2;
    }else{
      places = places-1;
    }
  }  
  // serialize_indent(oi, indent);
  ranges::copy(fmt::sprintf("%.*f",places,t.min), oi);
  ranges::copy(std::string_view(":"), oi);
  ranges::copy(fmt::sprintf("%.*f",places,t.typ), oi);
  ranges::copy(std::string_view(":"), oi);
  ranges::copy(fmt::sprintf("%.*f",places,t.max), oi);
}

// /// Serialize SDF timing spec
// /// \tparam OutputIterator must meet the requirements of OutputIterator
// /// \param oi The OutputIterator being written to
// /// \param ts The SDF file timing specification to write
// /// \exception Throws if writing to the OutputIterator throws otherwise noexcept
// template <class OutputIterator>
// void serialize_number(OutputIterator oi, int indent,
//                       Number n) noexcept(noexcept(*oi++ = '!')) {
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
  ranges::copy(std::string_view("("), oi);
  if (std::holds_alternative<Number>(v)) {
    // Number x = std::get<Number>(v);
    serialize_number(oi, indent, std::get<Number>(v));
  } else if (std::holds_alternative<Triple>(v)) {
    // Triple x = v;
    serialize_triple(oi, indent, std::get<Triple>(v));
  } else {
    throw std::runtime_error("InternalError");
  }
  ranges::copy(std::string_view(")"), oi);
}

} // namespace SDF

#endif //# LIBSDF_SERIALIZE_VALUES_HPP
