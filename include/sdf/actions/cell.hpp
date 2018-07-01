// #ifndef LIBSDF_ACTIONS_CELL_HPP_
// #define LIBSDF_ACTIONS_CELL_HPP_

// #include <sdf/actions/base.hpp>

// #include <sdf/actions/timingspec.hpp>

// #include <sdf/types/cell.hpp>
// #include <sdf/grammar/cell.hpp>

// namespace SDF{
// namespace Actions{

// using namespace Parse;  
// using namespace SDF::Types;  


// struct CellInstancePathStorage {
//   static bool store(CellInstanceVariant::Path &path, std::vector<std::string> ss) {
//     path = std::move(s)
//     return true;
//   }
// };

// struct CellInstancePathAction : multi_dispatch<
//   Grammar::hierarchical_identifier, inner_action<
//     HierarchicalIdentifierAction,
//     CellInstancePathStorage
//   >
// > {
//   using state = Path;
// };

// struct CellInstanceAction : multi_dispatch<
//   Grammar:::one<'*'>, apply0<Apply::value<CellInstanceVariant::Star>>,
//   Grammar::hierarchical_identifier, inner_action<
//     HierarchicalIdentifierAction,
//     CellInstancePathStorage
//   >
// > {
//   using state = CellInstanceVariant;
// };

// struct CellAction : multi_dispatch<
//   Grammar::celltype, inner_action<
//     QStringAction,
//     Storage::member<&Cell::celltype>
//   >
//   Grammar::cell_instance, inner_action<
//     CellInstanceAction,
//     Storage::member<&Cell::cell_instance>
//   >
//   Grammar::timing_spec, inner_action<
//     TimingSpecArrayAction,
//     Storage::member<&Cell::timing_specs>
//   >
// > {
//   using state = Cell;
// };

// struct CellArrayAction : single_dispatch<
//   Grammar::cell, inner_action<
//     CellAction,
//     Storage::push_back
//   >
// > {
//   using state = std::vector<Cell>;
// };


// }
// }

// #endif // LIBSDF_ACTIONS_CELL_HPP_