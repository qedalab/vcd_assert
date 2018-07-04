#include <sdf/types/delayfile_reader.hpp>

#include <cassert>

using namespace SDF;

DelayFileReader::DelayFileReader()
{
  delayfile_ = std::make_unique<DelayFile>();
}

void DelayFileReader::sdf_version(std::string sdf_version_string) noexcept
{
  delayfile_->sdf_version_ = std::move(sdf_version_string);
}

void DelayFileReader::design_name(std::string design_name_string)
{
  if(has_design_name())
    throw std::runtime_error("design_name has already been set");
  delayfile_->design_name_ = std::move(design_name_string);
}

bool DelayFileReader::has_design_name() const noexcept
{
  return delayfile_->has_design_name();
}

void DelayFileReader::date(std::string date_string)
{
  if(has_date())
    throw std::runtime_error("date has already been set");
  delayfile_->date_ = std::move(date_string);
}

bool DelayFileReader::has_date() const noexcept
{
  return delayfile_->has_date();
}

void DelayFileReader::vendor(std::string vendor_string)
{
  if(has_vendor())
    throw std::runtime_error("vendor has already been set");
  delayfile_->vendor_ = std::move(vendor_string);
}

bool DelayFileReader::has_vendor() const noexcept
{
  return delayfile_->has_vendor();
}

void DelayFileReader::program_name(std::string program_name_string)
{
  if(has_program_name())
    throw std::runtime_error("program_name has already been set");
  delayfile_->program_name_ = std::move(program_name_string);
}

bool DelayFileReader::has_program_name() const noexcept
{
  return delayfile_->has_program_name();
}

void DelayFileReader::program_version(std::string program_version_string)
{
  if(has_program_version())
    throw std::runtime_error("program_version has already been set");
  delayfile_->program_version_ = std::move(program_version_string);
}

bool DelayFileReader::has_program_version() const noexcept
{
  return delayfile_->has_program_version();
}

void DelayFileReader::process(std::string process_string)
{
  if(has_process())
    throw std::runtime_error("process has already been set");
  delayfile_->process_ = std::move(process_string);
}

bool DelayFileReader::has_process() const noexcept
{
  return delayfile_->has_process();
}

void DelayFileReader::hierarchy_divider(HChar hierarchy_divider)
{
  if(has_hierarchy_divider())
    throw std::runtime_error("hierarchy_divider has already been set");
  delayfile_->hierarchy_divider_ = std::move(hierarchy_divider);
}

bool DelayFileReader::has_hierarchy_divider() const noexcept
{
  return delayfile_->has_hierarchy_divider();
}

void DelayFileReader::voltage(Triple voltage)
{
  if(has_voltage())
    throw std::runtime_error("voltage has already been set");
  delayfile_->voltage_ = std::move(voltage);
}

bool DelayFileReader::has_voltage() const noexcept
{
  return delayfile_->has_voltage();
}

void DelayFileReader::temperature(Triple temperature)
{
  if(has_temperature())
    throw std::runtime_error("temperature has already been set");
  delayfile_->temperature_ = std::move(temperature);
}

bool DelayFileReader::has_temperature() const noexcept
{
  return delayfile_->has_temperature();
}

void DelayFileReader::timescale(TimeScaleNumber number, TimeScaleUnit unit)
{
  if(has_timescale())
    throw std::runtime_error("timescale has already been set");

  delayfile_->timescale_ = TimeScale{number, unit};
}

void DelayFileReader::timescale(TimeScaleView timescale)
{
  delayfile_->timescale_= TimeScale{timescale.number, timescale.unit};
}

bool DelayFileReader::has_timescale() const noexcept
{
  return delayfile_->has_timescale();
}

void DelayFileReader::cells(std::vector<Cell> cells)
{
  if(has_cells())
    throw std::runtime_error("timescale has already been set");

  delayfile_->cells_ = std::move(cells);
}

void DelayFileReader::add_cell(Cell cell) const noexcept
{
  delayfile_->cells_.emplace_back(std::move(cell));
}

bool DelayFileReader::has_cells() const noexcept
{
  return delayfile_->cells_.size() > 0;
}