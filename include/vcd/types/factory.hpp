#ifndef LIBVCD_TYPES_FACTORY_HPP
#define LIBVCD_TYPES_FACTORY_HPP

#include "./header.hpp"
#include "./enums.hpp"

#include <vector>
#include <memory>

namespace VCD {

class VCDHeaderFactory {
  std::unique_ptr<VCDHeader> header_;

  std::vector<std::size_t> scope_stack_;
public:
  void scope(ScopeType type, std::string name);
  void upscope();
  void var(VarType type, std::size_t size, std::string name, std::string reference);
  void version(std::string version_string);
  void date(std::string date_string);
  void timescale(TimeNumber number, TimeUnit unit);
};

}

#endif //LIBVCD_TYPES_FACTORY_HPP
