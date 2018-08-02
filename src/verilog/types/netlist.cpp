// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

// #include "verilog/types/netlist.hpp"

// #include <cassert>

// using namespace Verilog;

// Net::Net(Verilog::NetType type, std::string identifier, std::optional<std::size_t> definition_index) noexcept :
//     type_(type),
//     identifier_(std::move(identifier)),
//     definition_index_(definition_index)
// {
//   // Empty
// }

// bool Net::contains_variable(std::string &reference) const noexcept
// {
//   return child_variables_.count(reference) > 0;
// }

// std::size_t Net::get_variable_index(std::string &reference) const
// {
//   assert(contains_variable(reference));
//   return child_variables_.at(reference);
// }

// std::size_t Net::num_variables() const noexcept
// {
//   return child_variables_.size();
// }

// bool Net::has_definition_index() const noexcept
// {
//   return definition_index_.has_value();
// }


// std::size_t Net::get_definition_index() const
// {
//   return definition_index_.value();
// }

// bool Net::contains_net(std::string &identifier) const noexcept
// {
//   return child_nets_.count(identifier) > 0;
// }

// std::size_t Net::get_net_index(std::string &identifier) const
// {
//   assert(contains_net(identifier));
//   return child_nets_.at(identifier);
// }

// std::size_t Net::num_nets() const noexcept { return child_nets_.size(); }

// auto Net::get_nets() const -> decltype(ranges::view::all(this->child_nets_))
// {
//   return ranges::view::all(this->child_nets_);
// }

// auto Net::get_variables() const
//     -> decltype(ranges::view::all(this->child_variables_))
// {
//   return ranges::view::all(this->child_variables_);
// }

// std::string_view Net::get_identifier() const noexcept { return identifier_; }

// NetType Net::get_net_type() const noexcept { return type_; }

// Net::operator NetDataView() const noexcept { return {type_, identifier_, definition_index_}; }
