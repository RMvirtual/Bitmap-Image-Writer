#include "src/main/cpp/geometry/plotters/line/axes.h"

Geometry::Axes::Axes()
{
  // pass.
}

Geometry::Axes::Axes(Geometry::Line line)
{
  this->determineAxes(line);
}

void Geometry::Axes::determineAxes(Geometry::Line line)
{  
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis)
    this->setTiltedAxes(line);

  else
    this->setNormalAxes(line);

  this->determineYAxisChange();
}

void Geometry::Axes::setNormalAxes(Geometry::Line line)
{
  this->_xAxis = "x";
  this->_yAxis = "y";
  this->_run = line.run();
  this->_rise = line.rise();
}

void Geometry::Axes::setTiltedAxes(Geometry::Line line)
{
  this->_xAxis = "y";
  this->_yAxis = "x";
  this->_run = line.rise();
  this->_rise = line.run();
}

void Geometry::Axes::determineYAxisChange()
{
  this->_yChangeAmount = 1;

  if (this->_rise < 0) {
    this->_yChangeAmount = -1;
    this->_rise = 0 - this->_rise;
  }
}

std::string Geometry::Axes::xAxis()
{
  return this->_xAxis;
}
std::string Geometry::Axes::yAxis()
{
  return this->_yAxis;
}

double Geometry::Axes::yChangeAmount()
{
  return this->_yChangeAmount;
}

double Geometry::Axes::run()
{
  return this->_run;
}

double Geometry::Axes::rise()
{
  return this->_rise;
}