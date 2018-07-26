#ifndef LIBSDF_ACTIONS_CELL_HPP
#define LIBSDF_ACTIONS_CELL_HPP

#include <sdf/actions/base.hpp>

#include <sdf/actions/timing_spec.hpp>

#include <sdf/types/cell.hpp>
#include <sdf/grammar/cell.hpp>

namespace SDF{
namespace Actions{

using namespace Parse;  



// struct CellInstanceHierIdStorage {
//   static bool store(HierarchicalIdentifier &hi, std::vector<std::string> ss) {
//     hi.value = std::move(ss);
//     return true;
//   }
// };

// struct CellInstanceHierIdAction : single_dispatch<
//   Grammar::hierarchical_identifier, inner_action<
//     HierarchicalIdentifierAction,
//     CellInstanceHierIdStorage
//   >
// > {
//   using state = HierarchicalIdentifier;
// };

/*always returns star if got to this point*/
struct StarStorage {
  static bool store(Star & /*unused*/, bool found) {
    if(found){
      return true;
    }else{
      return false;
    }
  }
};


struct StarAction : single_dispatch<
  Grammar::one<'*'>, apply0<Apply::value<true>>
> {
  using state = bool;
};

struct StarCellInstanceAction : single_dispatch<
  Grammar::one<'*'>, inner_action<StarAction, StarStorage>
> {
  using state = Star;
};


struct CellInstanceAction : multi_dispatch<
  Grammar::one<'*'>, inner_action_passthrough< StarCellInstanceAction >,
  Grammar::hierarchical_identifier, inner_action_passthrough< HierarchicalIdentifierAction >
> {
  using state = CellInstance;
};

// struct CellAction : multi_dispatch<
//   Grammar::cell_type, inner_action<
//     StarAction,
//     StarStorage
//   >,
//   Grammar::cell_instance, inner_action<
//     CellInstanceAction,
//     Storage::member<&Cell::cell_instance>
//   >,
//   Grammar::timing_spec, inner_action<
//     TimingSpecArrayAction,
//     Storage::member<&Cell::timing_specs>
//   >
// > {
//   using state = CellInstance;
// };

struct CellAction : multi_dispatch<
  Grammar::cell_type, inner_action<
    QStringAction,
    Storage::member<&Cell::cell_type>
  >,
  Grammar::cell_instance, inner_action<
    CellInstanceAction,
    Storage::member<&Cell::cell_instance>
  >,
  Grammar::timing_spec, inner_action<
    TimingSpecArrayAction,
    Storage::member<&Cell::timing_specs>
  >
> {
  using state = Cell;
};

struct CellArrayAction : single_dispatch<
  Grammar::cell, inner_action<
    CellAction,
    Storage::push_back
  >
> {
  using state = std::vector<Cell>;
};


}
}

#endif // LIBSDF_ACTIONS_CELL_HPP
