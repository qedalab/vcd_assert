#ifndef LIBVCD_SERIALIZE_ENUM_HPP
#define LIBVCD_SERIALIZE_ENUM_HPP

#include "../types/enums.hpp"

#include <stdexcept>

namespace VCD {

constexpr std::string_view scope_type_to_string(ScopeType st) {
  switch(st) {
  case ScopeType::begin:
    return "begin";
  case ScopeType::fork:
    return "fork";
  case ScopeType::function:
    return "function";
  case ScopeType::module:
    return "module";
  case ScopeType::task:
    return "task";
  }
}

constexpr std::string_view time_unit_to_string(TimeUnit tu) {
  switch(tu) {
  case TimeUnit::s:
    return "s";
  case TimeUnit::ms:
    return "ms";
  case TimeUnit::us:
    return "us";
  case TimeUnit::ns:
    return "ns";
  case TimeUnit::ps:
    return "ps";
  case TimeUnit::fs:
    return "fs";
  }
}

constexpr std::string_view time_number_to_string(TimeNumber tn) {
  switch(tn) {
  case TimeNumber::_1:
    return "1";
  case TimeNumber::_10:
    return "10";
  case TimeNumber::_100:
    return "100";
  }
}

constexpr std::string_view var_type_to_string(VarType vr) {
  switch(vr) {
  case VarType::event:
    return "event";
  case VarType::integer:
    return "integer";
  case VarType::parameter:
    return "parameter";
  case VarType::real:
    return "real";
  case VarType::realtime:
    return "realtime";
  case VarType::reg:
    return "reg";
  case VarType::supply0:
    return "supply0";
  case VarType::supply1:
    return "supply1";
  case VarType::time:
    return "time";
  case VarType::tri:
    return "tri";
  case VarType::triand:
    return "triand";
  case VarType::trior:
    return "trior";
  case VarType::trireg:
    return "trireg";
  case VarType::tri0:
    return "tri0";
  case VarType::tri1:
    return "tri1";
  case VarType::wand:
    return "wand";
  case VarType::wire:
    return "wire";
  case VarType::wor:
    return "wor";
  }
}


constexpr char value_to_char(Value v) {
  switch(v) {
  case Value::zero:
    return '0';
  case Value::one:
    return '1';
  case Value::z:
    return 'Z';
  case Value::x:
    return 'X';
  }
}

constexpr std::string_view value_to_string(Value v) {
  switch(v) {
  case Value::zero:
    return "0";
  case Value::one:
    return "1";
  case Value::z:
    return "Z";
  case Value::x:
    return "X";
  }
}

} // namespace VCD

#endif // LIBCD_WRITER_ENUM_HPP
