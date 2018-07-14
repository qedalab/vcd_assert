#include "vcd/types/variable.hpp"

using namespace VCD;

Variable::Variable(std::size_t id_code, std::string reference) noexcept :
    id_code_(id_code),
    ref_(std::move(reference))
{
  // Empty
}

std::size_t Variable::get_id_code_index() const noexcept { return id_code_; }

std::string_view Variable::get_reference() const noexcept { return ref_; }
