#ifndef LIBSDF_SERIALIZE_BASE_HPP
#define LIBSDF_SERIALIZE_BASE_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

template <class OutputIterator, class Type>
void serialize_quoted(OutputIterator oi,
                      std::string_view input) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("\""sv, oi);
  ranges::copy(input, oi);
  ranges::copy("\""sv, oi);
}

template <class OutputIterator, class InnerSerializer, class Type>
void serialize_quoted(OutputIterator oi, InnerSerializer inner,
                      Type input) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("\""sv, oi);
  inner(oi, input);
  ranges::copy("\""sv, oi);
}

/// Serialize SDF HierarchicalIdentifier
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param comment The comment to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_hierarchical_identifier(
    OutputIterator oi, std::string_view hi) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("/*"sv, oi);
  ranges::copy(hi, oi);
  ranges::copy("*/"sv, oi);
}

/// Serialize SDF comment
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param comment The comment to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_comment_ml(OutputIterator oi, std::string_view comment) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("/*"sv, oi);
  ranges::copy(comment, oi);
  ranges::copy("*/"sv, oi);
}

/// Serialize SDF comment
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param comment The comment to write (may not contain new line character)
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_comment_sl(OutputIterator oi, std::string_view comment) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("//"sv, oi);
  ranges::copy(comment, oi);
  ranges::copy("\n"sv, oi);
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_COMMENT_HPP
