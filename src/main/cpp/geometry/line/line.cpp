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

void Geometry::Line::reverseEndpoints()
{
  auto originalOrigin = this->_origin;
  auto originalDestination = this->_destination;
  
  this->_destination = originalOrigin;
  this->_origin = originalDestination;
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

void Geometry::Line::normaliseEndpoints()
{
  if (this->hasReversedEndpoints())
    this->reverseEndpoints();
}

bool Geometry::Line::hasReversedEndpoints()
{    
  return (
    this->hasHorizontallyReversedEndpoints()
    || this->hasVerticallyReversedEndpoints()
  );
}

bool Geometry::Line::hasHorizontallyReversedEndpoints()
{
  return (this->isHorizontallySloped() && this->isTraversingWest());
}

bool Geometry::Line::hasVerticallyReversedEndpoints()
{
  return (this->isVerticallySloped() && this->isTraversingSouth());
}

double Geometry::Line::gradient()
{
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);

  return hasZeroDivision ? 1 : yChange / xChange;
}

double Geometry::Line::run()
{
  return this->_destination["x"] - this->_origin["x"];
}

double Geometry::Line::rise()
{
  return this->_destination["y"] - this->_origin["y"];
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