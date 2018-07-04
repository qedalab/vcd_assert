#include <sdf/types/timing_check.hpp>

#include <cassert>

using namespace SDF;

std::vector<std::size_t> TimingCheckSpec::get_timing_check_indices_by_type(TimingCheckType &type) const
{
  std::vector<std::size_t> result;
  std::size_t i = 0;
  
  for(auto&& tc : *this){
    if(type == tc.get_enum_type()){
      result.emplace_back(i);
    }
    i++; 
  }
  return result;
}