#include "src/main/cpp/geometry/line/line.h"

Geometry::Line::Line()
{
  this->setEndpoints({0,0}, {0,0});
}

Geometry::Line::Line(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  this->setEndpoints(origin, destination);
}

Geometry::Line::Line(std::pair<double,double> destination)
{
  this->setEndpoints({0,0}, destination);
}

Geometry::Gradient Geometry::Line::gradient()
{
  return this->_gradient;
}

void Geometry::Line::setOrigin(std::pair<double,double> coordinates)
{
  this->_origin = coordinates;
  this->updateGradient();
}

void Geometry::Line::setDestination(std::pair<double,double> coordinates)
{
  this->_destination = coordinates;
  this->updateGradient();
}

void Geometry::Line::setEndpoints(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  this->_origin = origin;
  this->_destination = destination;
  this->updateGradient();
}

std::pair<double,double> Geometry::Line::origin()
{
  return this->_origin;
}

std::pair<double,double> Geometry::Line::destination()
{
  return this->_destination;
}

void Geometry::Line::updateGradient()
{
  this->_gradient = {this->_origin, this->_destination};
}