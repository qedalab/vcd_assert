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

// #ifndef LIBVERILOG_TYPES_NETLIST_HPP
// #define LIBVERILOG_TYPES_NETLIST_HPP

// #include "enums.hpp"
// #include "module.hpp"

// #include <range/v3/view/all.hpp>

// #include <optional>
// #include <string>
// #include <unordered_map>
// #include <variant>

// namespace Verilog {



// struct NetDataView {
//   NetType type = NetType::module;
//   std::string_view identifier;
//   std::optional<std::size_t> net_definition;
// };


// /// Verilog Net object
// /// This object is defined in terms of the Design it is contained in and can
// /// therefore only be populated alongside the Design with DesignReader
// /// \related DesignReader
// class Net {
//   NetType type_;                     /// The net type
//   std::string identifier_;           /// The net identifier

//   std::optional<std::size_t> definition_index_; /// Index to the net definition

//   /// Child nets
//   std::unordered_map<std::string, std::size_t> child_nets_;

//   /// Child variables
//   std::unordered_map<std::string, std::size_t> child_variables_;

//   friend class DesignReader;
// public:
//   /// The net constructor
//   /// \todo Ensure identifier correctness
//   /// \param type The net type
//   /// \param identifier The identifier string
//   /// \todo ensure identifier correctness
//   Net(NetType type, std::string identifier, std::optional<std::size_t> definition_index) noexcept;

//   /// True if the net directly contains the variable reference
//   /// \param reference The variable reference
//   /// \returns Wether the net directly contains the variable reference
//   bool contains_variable(std::string &reference) const noexcept;

//   /// Get the variable index by reference
//   /// \param reference The variable reference
//   /// \returns The variable index
//   std::size_t get_variable_index(std::string &reference) const;

//   /// Number of variables directly in this net
//   /// \returns The number of variables directly in this net
//   std::size_t num_variables() const noexcept;
  
//   /// Get whether net in an instance of a definition
//   bool has_definition_index() const noexcept;

//   /// Get the definition of the net instance
//   /// \returns The definition index
//   std::size_t get_definition_index() const;

//   /// True if the net directly contains the net
//   /// \param identifier The child net identifier
//   /// \returns Wether the net directly contains \p identifier
//   bool contains_net(std::string &identifier) const noexcept;

//   /// Get net index by identifierthis
//   /// \param identifier The child net identifier
//   /// \returns The net index from \p identifier
//   std::size_t get_net_index(std::string &identifier) const;

//   /// Returns the number of direct nets within this net
//   /// \returns The number of direct nets within this net
//   std::size_t num_nets() const noexcept;

//   /// Returns a range of identifier-index pairs of the nets
//   /// \returns identifier-index pairs range
//   /// \TODO Make and use identifier-index range
//   auto get_nets() const -> decltype(ranges::view::all(this->child_nets_));

//   /// Returns a range of identifier-index pairs of the variables
//   /// \returns identifier-index pairs range
//   /// \TODO Make and use identifier-index range
//   auto get_variables() const -> decltype(ranges::view::all(this->child_variables_));

//   /// Get net identifier
//   /// \returns View of identifier string
//   std::string_view get_identifier() const noexcept;

//   /// Get net type
//   /// \returns The net type
//   NetType get_net_type() const noexcept;

//   /// Convert to NetDataView
//   /// \returns NetDataView of Net
//   operator NetDataView() const noexcept;
// };

// } // Verilog

// #endif //LIBVERILOG_TYPES_NETLIST_HPP
