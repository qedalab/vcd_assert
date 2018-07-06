#include <sdf/types/delayfile.hpp>
#include <sdf/types/cell.hpp>

#include <cassert>

using namespace SDF;

std::string_view DelayFile::get_sdf_version()
{
  return sdf_version_; 
}

std::optional<std::string_view> DelayFile::get_design_name()
{
  return design_name_; 
}

bool DelayFile::has_design_name() const noexcept
{
  return design_name_.has_value();
}

std::optional<std::string_view> DelayFile::get_date()
{
  return date_; 
}

bool DelayFile::has_date() const noexcept
{
  return date_.has_value();
}

std::optional<std::string_view> DelayFile::get_vendor()
{
  return vendor_; 
}

bool DelayFile::has_vendor() const noexcept
{
  return vendor_.has_value();
}

std::optional<std::string_view> DelayFile::get_program_name()
{
  return program_name_; 
}

bool DelayFile::has_program_name() const noexcept
{
  return program_name_.has_value();
}

std::optional<std::string_view> DelayFile::get_program_version()
{
  return program_version_; 
}

bool DelayFile::has_program_version() const noexcept
{
  return program_version_.has_value();
}

std::optional<std::string_view> DelayFile::get_process()
{
  return process_; 
}

bool DelayFile::has_process() const noexcept
{
  return process_.has_value();
}

std::optional<HChar> DelayFile::get_hierarchy_divider()
{
  return hierarchy_divider_; 
}

bool DelayFile::has_hierarchy_divider() const noexcept
{
  return hierarchy_divider_.has_value();
}

std::optional<Triple> DelayFile::get_voltage()
{
  return voltage_; 
}

bool DelayFile::has_voltage() const noexcept
{
  return voltage_.has_value();
}

std::optional<Triple> DelayFile::get_temperature()
{
  return temperature_; 
}

bool DelayFile::has_temperature() const noexcept
{
  return temperature_.has_value();
}

std::optional<TimeScale> DelayFile::get_timescale()
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
    if(cell_type == cell.get_cell_type()){
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
    if(cell_instance == cell.get_cell_instance()){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}
