#ifndef LIBVCD_TYPES_HEADER_READER_HPP
#define LIBVCD_TYPES_HEADER_READER_HPP

#include "./header.hpp"
#include "./enums.hpp"

#include <vector>
#include <memory>

namespace VCD {

class HeaderReader {
  std::unique_ptr<Header> header_;

  std::vector<std::size_t> scope_stack_;
public:
  HeaderReader();

  void scope(ScopeType type, std::string name);
  void upscope();
  void var(VarType type, std::size_t size, std::string identifier_code, std::string reference);

  void version(std::string version_string);
  void overwrite_version(std::string version_string);
  bool has_version();

  void date(std::string date_string);
  void overwrite_date(std::string date_string);
  bool has_date();

  void timescale(TimeNumber number, TimeUnit unit);
  void overwrite_timescale(TimeNumber number, TimeUnit unit);
  bool has_timescale();

  std::unique_ptr<Header> release();
};

}

#endif //LIBVCD_TYPES_HEADER_BUILDER_HPP
