#include "src/main/cpp/geometry/line/line.h"

Geometry::Line::Line()
{
  this->setEndpoints({0,0}, {0,0});
}

Geometry::Line::Line(Maths::Vector origin, Maths::Vector destination)
{
  this->setEndpoints(origin, destination);
}

Geometry::Line::Line(Maths::Vector destination)
{
  this->setEndpoints({0,0}, destination);
}

Geometry::Line Geometry::Line::reverse()
{
  return {this->_destination, this->_origin};
}

void Geometry::Line::setOrigin(Maths::Vector coordinates)
{
  this->_origin = coordinates;
  this->updateGradient();
}

void Geometry::Line::setDestination(Maths::Vector coordinates)
{
  this->_destination = coordinates;
  this->updateGradient();
}

void Geometry::Line::setEndpoints(
  Maths::Vector origin, Maths::Vector destination)
{
  this->_origin = origin;
  this->_destination = destination;
  this->updateGradient();
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
  return this->_gradient.gradient();
}

double Geometry::Line::rise()
{
  return this->_gradient.rise();
}

double Geometry::Line::run()
{
  return this->_gradient.run();
}

bool Geometry::Line::isHorizontallySloped()
{
  return this->_gradient.isHorizontallySloped();
}

bool Geometry::Line::isTraversingUpwards()
{
  return this->_gradient.isTraversingUpwards();
}

bool Geometry::Line::isTraversingLeftToRight()
{
  return this->_gradient.isTraversingLeftToRight();
}

void Geometry::Line::updateGradient()
{
  this->_gradient = {this->_origin, this->_destination};
}