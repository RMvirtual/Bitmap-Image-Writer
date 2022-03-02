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

  this->determineVerticalAxisChange();
}

void Geometry::Axes::setNormalAxes(Geometry::Line line)
{
  this->_horizontalAxis = "x";
  this->_verticalAxis = "y";
  this->_run = line.run();
  this->_rise = line.rise();
}

void Geometry::Axes::setTiltedAxes(Geometry::Line line)
{
  this->_horizontalAxis = "y";
  this->_verticalAxis = "x";
  this->_run = line.rise();
  this->_rise = line.run();
}

void Geometry::Axes::determineVerticalAxisChange()
{
  this->_verticalChangeAmount = 1;

  if (this->_rise < 0) {
    this->_verticalChangeAmount = -1;
    this->_rise = 0 - this->_rise;
  }
}

std::string Geometry::Axes::horizontalAxis()
{
  return this->_horizontalAxis;
}
std::string Geometry::Axes::verticalAxis()
{
  return this->_verticalAxis;
}

double Geometry::Axes::verticalChangeAmount()
{
  return this->_verticalChangeAmount;
}

double Geometry::Axes::run()
{
  return this->_run;
}

double Geometry::Axes::rise()
{
  return this->_rise;
}