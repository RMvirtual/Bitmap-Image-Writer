#include "src/main/cpp/geometry/line/line.h"

Geometry::Line::Line()
{
  this->setEndpoints({0.0, 0.0}, {1.0, 1.0});
}

Geometry::Line::Line(Maths::Vector origin, Maths::Vector destination)
{
  this->setEndpoints(origin, destination);
}

Geometry::Line::Line(Maths::Vector destination)
{
  this->setEndpoints({0.0, 0.0}, destination);
}

Geometry::Line Geometry::Line::reverse()
{
  return {this->_destination, this->_origin};
}

void Geometry::Line::setOrigin(Maths::Vector coordinates)
{
  this->_origin = coordinates;
}

void Geometry::Line::setDestination(Maths::Vector coordinates)
{
  this->_destination = coordinates;
}

void Geometry::Line::setEndpoints(
  Maths::Vector origin, Maths::Vector destination)
{
  this->_origin = origin;
  this->_destination = destination;
}

Maths::Vector Geometry::Line::origin()
{
  return this->_origin;
}

Maths::Vector Geometry::Line::destination()
{
  return this->_destination;
}

double Geometry::Line::gradient()
{
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);

  return hasZeroDivision ? 1 : yChange / xChange;
}

double Geometry::Line::rise()
{
  return this->_destination["y"] - this->_origin["y"];
}

double Geometry::Line::run()
{
  return this->_destination["x"] - this->_origin["x"];
}

bool Geometry::Line::isHorizontallySloped()
{
  return abs(this->rise()) < abs(this->run());
}

bool Geometry::Line::isVerticallySloped()
{
  return abs(this->rise()) > abs(this->run());
}

bool Geometry::Line::isTraversingNorth()
{
  return this->rise() > 0;
}

bool Geometry::Line::isTraversingSouth()
{
  return this->rise() < 0;
}

bool Geometry::Line::isTraversingEast()
{
  return this->run() > 0;
}

bool Geometry::Line::isTraversingWest()
{
  return this->run() < 0;
}