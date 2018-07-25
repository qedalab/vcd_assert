#include "verilog/types/var_id_code.hpp"

using namespace Verilog;

VarIdCode::VarIdCode(VarType type, std::size_t size,
                     std::string identifier_code) noexcept :
    type_(type),
    size_(size),
    id_code_(std::move(identifier_code))
{
  // Empty
}

std::string_view VarIdCode::get_id_code() const noexcept { return id_code_; }

VarType VarIdCode::get_type() const noexcept { return type_; }

std::size_t VarIdCode::get_size() const noexcept { return size_; }
