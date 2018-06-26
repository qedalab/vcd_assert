#ifndef LIBVCD_SERIALIZE_COMMENT_HPP
#define LIBVCD_SERIALIZE_COMMENT_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

template<class OutputIterator>
void serialize_comment(OutputIterator oi, std::string_view comment) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$comment "sv, oi);
  ranges::copy(comment, oi);
  ranges::copy(" $end\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_COMMENT_HPP
