#include <sdf/types/cell.hpp>

#include <cassert>

using namespace SDF;

Cell::Cell(std::string cell_type, CellInstance cell_instance, std::vector<TimingSpec> timing_specs) noexcept:
  cell_type_(std::move(cell_type)),
  cell_instance_(std::move(cell_instance)),
  timing_specs_(std::move(timing_specs))
{
  // Empty
}

CellInstance Cell::get_cell_instance() const noexcept
{
  return cell_instance_;
}

std::string_view Cell::get_cell_type() const noexcept
{
  return cell_type_;
}

std::vector<std::size_t> Cell::get_timing_spec_indices_by_type(TimingSpecType &type) const
{
  std::vector<std::size_t> result;
  std::size_t i = 0;
  
  for(auto&& ts : timing_specs_){
    if(type == ts.get_enum_type()){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}

TimingSpec& Cell::get_timing_spec(std::size_t index)
{
  assert(timing_specs_.size() > index);
  return timing_specs_.at(index);
}

std::size_t Cell::num_timing_specs() const noexcept
{
  return timing_specs_.size();
}

std::vector<TimingSpec> Cell::get_timing_specs() const noexcept
{
  return timing_specs_;
}

Cell::operator CellView() const noexcept {
  return {
    .cell_type = cell_type_,
    .cell_instance = cell_instance_,
    .timing_specs = timing_specs_
  };
}