#ifndef LIBSDF_ACTIONS_CELL_HPP
#define LIBSDF_ACTIONS_CELL_HPP

#include <sdf/actions/delayfile.hpp>
#include <sdf/actions/timing_spec.hpp>
#include <sdf/types/cell.hpp>

namespace SDF{

struct CellStorage {
  template<class InnerValue>
  static bool store(JSONValuePtr& value_ptr, InnerValue value) {
    if constexpr (std::is_same_v<JSONValuePtr, InnerValue>) {
      value_ptr = std::move(value);
    } else {
      value_ptr = std::make_unique<JSONValue>(std::move(value));
    }

    return true;
  }
};

struct TimingSpecStorage {
  static bool store(Cell &cell, TimingSpec cell) {
    cell.timing_specs.emplace_back(std::move(spec))
    return true;
  }
};

struct CellInstanceAction : multi_dispatch<
  Grammar::one<'*'>, inner_value<
    QStringAction,
    Storage::member<&Cell::celltype>
  >
  Grammar::cell_instance, inner_value<
    CellInstanceAction,
    Storage::member<&Cell::cell_instance>
  >
> {
  using state = Cell;
};

struct CellAction : multi_dispatch<
  Grammar::celltype, inner_value<
    QStringAction,
    Storage::member<&Cell::celltype>
  >
  Grammar::cell_instance, inner_value<
    CellInstanceAction,
    Storage::member<&Cell::cell_instance>
  >
  Grammar::timing_spec, inner_value<
    TimingSpecAction,
    Storage::push_back<&Cell::timing_specs>
  >
> {
  using state = Cell;
};

}

#endif // LIBSDF_ACTIONS_CELL_HPP