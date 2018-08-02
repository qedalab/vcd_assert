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

#include "sdf/types/delayfile.hpp"
#include "sdf/types/cell.hpp"

#include <cassert>

using namespace SDF;

// DelayFile::DelayFile(DelayFileView dfw){

// }

std::string_view DelayFile::get_sdf_version() const noexcept
{
  return sdf_version_; 
}

std::optional<std::string_view> DelayFile::get_design_name() const noexcept
{
  return design_name_; 
}

bool DelayFile::has_design_name() const noexcept
{
  return design_name_.has_value();
}

std::optional<std::string_view> DelayFile::get_date() const noexcept
{
  return date_; 
}

bool DelayFile::has_date() const noexcept
{
  return date_.has_value();
}

std::optional<std::string_view> DelayFile::get_vendor() const noexcept
{
  return vendor_; 
}

bool DelayFile::has_vendor() const noexcept
{
  return vendor_.has_value();
}

std::optional<std::string_view> DelayFile::get_program_name() const noexcept
{
  return program_name_; 
}

bool DelayFile::has_program_name() const noexcept
{
  return program_name_.has_value();
}

std::optional<std::string_view> DelayFile::get_program_version() const noexcept
{
  return program_version_; 
}

bool DelayFile::has_program_version() const noexcept
{
  return program_version_.has_value();
}

std::optional<std::string_view> DelayFile::get_process()  const noexcept
{
  return process_; 
}

bool DelayFile::has_process() const noexcept
{
  return process_.has_value();
}

std::optional<HChar> DelayFile::get_hierarchy_divider() const noexcept
{
  return hierarchy_divider_; 
}

bool DelayFile::has_hierarchy_divider() const noexcept
{
  return hierarchy_divider_.has_value();
}

std::optional<Triple> DelayFile::get_voltage() const noexcept
{
  return voltage_; 
}

bool DelayFile::has_voltage() const noexcept
{
  return voltage_.has_value();
}

std::optional<Triple> DelayFile::get_temperature() const noexcept
{
  return temperature_; 
}

bool DelayFile::has_temperature() const noexcept
{
  return temperature_.has_value();
}

std::optional<TimeScale> DelayFile::get_timescale() const noexcept
{
  return timescale_; 
}

bool DelayFile::has_timescale() const noexcept
{
  return timescale_.has_value();
}

std::vector<Cell> DelayFile::get_cells() const noexcept
{
  return move(cells_); 
}

std::size_t DelayFile::num_cells() const noexcept
{
  return cells_.size();
}

Cell& DelayFile::get_cell(std::size_t index)
{
  assert(index < num_cells());
  return cells_.at(index);
}

std::vector<std::size_t> DelayFile::get_cell_indices_by_type(std::string &cell_type) const noexcept
{
  std::vector<std::size_t> result;
  std::size_t i = 0;
  
  for(auto&& cell : cells_){
    if(cell_type == cell.cell_type){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}
std::vector<std::size_t> DelayFile::get_cell_indices_by_instance(CellInstance &cell_instance) const noexcept
{
  std::vector<std::size_t> result;
  std::size_t i = 0;
  
  for(auto&& cell : cells_){
    if(cell_instance == cell.cell_instance){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}
