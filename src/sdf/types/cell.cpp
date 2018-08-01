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

#include <sdf/types/cell.hpp>

#include <cassert>

using namespace SDF;

// Cell::Cell(std::string cell_type, CellInstance cell_instance, std::vector<TimingSpec> timing_specs) noexcept:
//   cell_type_(std::move(cell_type)),
//   cell_instance_(std::move(cell_instance)),
//   timing_specs_(std::move(timing_specs))
// {
//   // Empty
// }

// CellInstance Cell::get_cell_instance() const noexcept
// {
//   return cell_instance_;
// }

// std::string_view Cell::get_cell_type() const noexcept
// {
//   return cell_type_;
// }

// std::vector<std::size_t> Cell::get_timing_spec_indices_by_type(TimingSpecType &type) const
// {
//   std::vector<std::size_t> result;
//   std::size_t i = 0;
  
//   for(auto&& ts : timing_specs_){
//     if(type == ts.get_enum_type()){
//       result.emplace_back(i);
//     }
//     i++; 
//   }
//   return result;
// }

// TimingSpec& Cell::get_timing_spec(std::size_t index)
// {
//   assert(timing_specs_.size() > index);
//   return timing_specs_.at(index);
// }

// std::size_t Cell::num_timing_specs() const noexcept
// {
//   return timing_specs_.size();
// }

// std::vector<TimingSpec> Cell::get_timing_specs() const noexcept
// {
//   return timing_specs_;
// }

// Cell::operator CellView() const noexcept {
//   return {
//     .cell_type = cell_type_,
//     .cell_instance = cell_instance_,
//     .timing_specs = timing_specs_
//   };
// }
