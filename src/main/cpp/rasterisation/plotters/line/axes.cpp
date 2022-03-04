#include <unordered_map>
#include "src/main/cpp/rasterisation/plotters/line/axes.h"

Geometry::SlopedAxes::SlopedAxes()
{
  // pass.
}

Geometry::SlopedAxes::SlopedAxes(Geometry::Line line)
{
  this->determineAxes(line);
}

std::string Geometry::SlopedAxes::operator [](std::string vertex)
{
  std::unordered_map<std::string, std::string> vertices {
    {"x0", this->_horizontalAxis + "0"},
    {"y0", this->_verticalAxis + "0"},
    {"x1", this->_horizontalAxis + "1"},
    {"y1", this->_verticalAxis + "1"}
  };

  return vertices[vertex];
}

void Geometry::SlopedAxes::determineAxes(Geometry::Line line)
{  
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis)
    this->tiltAxes(line);

  else
    this->setNormalAxes(line);

  this->determineVerticalAxisDirection();
}

void Geometry::SlopedAxes::setNormalAxes(Geometry::Line line)
{
  this->_horizontalAxis = "x";
  this->_verticalAxis = "y";
  this->_run = line.run();
  this->_rise = line.rise();
}

void Geometry::SlopedAxes::tiltAxes(Geometry::Line line)
{
  this->_horizontalAxis = "y";
  this->_verticalAxis = "x";
  this->_run = line.rise();
  this->_rise = line.run();
}

void Geometry::SlopedAxes::determineVerticalAxisDirection()
{
  this->_verticalChangeAmount = 1;

  if (this->_rise < 0) {
    this->_verticalChangeAmount = -1;
    this->_rise = 0 - this->_rise;
  }
}

std::string Geometry::SlopedAxes::horizontalAxis()
{
  return this->_horizontalAxis;
}
std::string Geometry::SlopedAxes::verticalAxis()
{
  return this->_verticalAxis;
}

double Geometry::SlopedAxes::verticalIncrementDirection()
{
  return this->_verticalChangeAmount;
}

double Geometry::SlopedAxes::run()
{
  return this->_run;
}

double Geometry::SlopedAxes::rise()
{
  return this->_rise;
}