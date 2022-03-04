#include <unordered_map>
#include "src/main/cpp/rasterisation/plotters/line/axes.h"

Geometry::ErrorAxes::ErrorAxes()
{
  // pass.
}

Geometry::ErrorAxes::ErrorAxes(Geometry::Line line)
{
  this->determineAxes(line);
}

std::string Geometry::ErrorAxes::operator [](std::string vertex)
{
  std::unordered_map<std::string, std::string> vertices {
    {"x0", this->_horizontalAxis + "0"},
    {"y0", this->_verticalAxis + "0"},
    {"x1", this->_horizontalAxis + "1"},
    {"y1", this->_verticalAxis + "1"}
  };

  return vertices[vertex];
}

void Geometry::ErrorAxes::determineAxes(Geometry::Line line)
{  
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis)
    this->tiltAxes(line);

  else
    this->setNormalAxes(line);

  this->determineVerticalAxisDirection();
}

void Geometry::ErrorAxes::setNormalAxes(Geometry::Line line)
{
  this->_horizontalAxis = "x";
  this->_verticalAxis = "y";
  this->_run = line.run();
  this->_rise = line.rise();
}

void Geometry::ErrorAxes::tiltAxes(Geometry::Line line)
{
  this->_horizontalAxis = "y";
  this->_verticalAxis = "x";
  this->_run = line.rise();
  this->_rise = line.run();
}

void Geometry::ErrorAxes::determineVerticalAxisDirection()
{
  this->_verticalChangeAmount = 1;

  if (this->_rise < 0) {
    this->_verticalChangeAmount = -1;
    this->_rise = 0 - this->_rise;
  }
}

bool Geometry::ErrorAxes::xIsErrorAxis()
{
  return this->_verticalAxis == "x";
}

bool Geometry::ErrorAxes::yIsErrorAxis()
{
  return this->_verticalAxis == "y";
}

std::string Geometry::ErrorAxes::horizontalAxis()
{
  return this->_horizontalAxis;
}
std::string Geometry::ErrorAxes::verticalAxis()
{
  return this->_verticalAxis;
}

double Geometry::ErrorAxes::verticalIncrementDirection()
{
  return this->_verticalChangeAmount;
}

double Geometry::ErrorAxes::run()
{
  return this->_run;
}

double Geometry::ErrorAxes::rise()
{
  return this->_rise;
}