#include "src/main/cpp/geometry/triangle/edge.h"

Geometry::Edge::Edge(
  const Maths::Vector& origin, const Maths::Vector& destination)
{
  this->_origin = origin;
  this->_destination = destination;

  this->_slope = {this->_origin, this->_destination};
}

Geometry::Slope Geometry::Edge::slope() const
{
  return this->_slope;
}

Maths::Vector Geometry::Edge::operator [](int index) const
{
  auto point = this->_origin;
  
  if (index == 1)
    point = this->_destination;

  return point;
}

double Geometry::Edge::operator [](std::string index) const
{
  std::string pointNoString = {index[1]};
  int pointNo = std::stoi(pointNoString);

  auto point = this->_origin;
  
  if (pointNo == 1)
    point = this->_destination;

  std::string coordinate {index[0]};

  return point[coordinate];
}

double Geometry::Edge::yLowerBound() const
{
  return this->_slope.yLowerBound();
}

double Geometry::Edge::yUpperBound() const
{
  return this->_slope.yUpperBound();
}

double Geometry::Edge::xLowerBound() const
{
  return this->_slope.xLowerBound();
}

double Geometry::Edge::xUpperBound() const
{
  return this->_slope.yUpperBound();
}