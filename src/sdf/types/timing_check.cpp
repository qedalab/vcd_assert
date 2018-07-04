#include <sdf/types/timing_check.hpp>

#include <cassert>

using namespace SDF;


// TimingCheck::TimingCheck(TimingCheckType type, TimingCheckVariant timing_check) noexcept:
//   type(std::move(type)),
//   cell_instance_(std::move(cell_instance)),
//   timing_specs_(std::move(timing_specs))
// {
//   // Empty
// }

// TimingCheckSpec::TimingCheckSpec()


std::vector<std::size_t> TimingCheckSpec::get_timing_check_indices_by_type(TimingCheckType &type) const
{
  std::vector<std::size_t> result;
  std::size_t i = 0;
  
  for(auto&& tc : timing_checks){
    if(type == tc.type){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}