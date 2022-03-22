#include <algorithm>
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/slope/slope.h"

Geometry::Line::Line()
{
  this->setEndpoints({0.0, 0.0}, {1.0, 1.0});
}

Geometry::Line::Line(
  const Maths::Vector& origin, const Maths::Vector& destination)
{
  this->setEndpoints(origin, destination);
}

Geometry::Line::Line(const Maths::Vector& destination)
{
  this->setEndpoints({0.0, 0.0}, destination);
}

void Geometry::Line::setOrigin(const Maths::Vector& coordinates)
{
  this->_origin = coordinates;
  this->calculateVertices();
}

void Geometry::Line::setDestination(const Maths::Vector& coordinates)
{
  this->_destination = coordinates;
  this->calculateVertices();
}

void Geometry::Line::setEndpoints(
  const Maths::Vector& origin, const Maths::Vector& destination)
{
  this->_origin = origin;
  this->_destination = destination;
  this->calculateVertices();
}

void Geometry::Line::switchEndpoints()
{
  auto originalOrigin = this->_origin;
  auto originalDestination = this->_destination;
  
  this->_destination = originalOrigin;
  this->_origin = originalDestination;
  this->calculateVertices();
}

void Geometry::Line::translate(const Maths::Vector& translation)
{
  this->_origin = this->_origin + translation;
  this->_destination = this->_destination + translation;
  this->calculateVertices();
}

void Geometry::Line::scale(double scaleFactor, const Maths::Vector& origin)
{
  auto originLineLength = this->_origin - origin;
  auto originScaledLength =  originLineLength * scaleFactor;
  this->_origin = origin + originScaledLength;

  auto destLineLength = this->_destination - origin;
  auto destScaledLength =  destLineLength * scaleFactor;
  this->_destination = origin + destScaledLength;
  this->calculateVertices();
}

void Geometry::Line::scale(double scaleFactor)
{
  auto lineLength = this->_destination - this->_origin;
  auto scaledLength = lineLength * scaleFactor;

  this->_destination = this->_origin + scaledLength;
  this->calculateVertices();
}

void Geometry::Line::scaleIncludingOrigin(double scaleFactor)
{
  this->_origin = this->_origin * scaleFactor;
  this->_destination = this->_destination * scaleFactor;
  this->calculateVertices();
}

void Geometry::Line::sortByXAscending()
{
  if (this->isDescendingByX())
    this->switchEndpoints();
}

void Geometry::Line::sortByYAscending()
{
  if (this->isDescendingByY())
    this->switchEndpoints();
}

Maths::Vector Geometry::Line::origin() const
{
  return this->_origin;
}

Maths::Vector Geometry::Line::destination() const
{
  return this->_destination;
}

void Geometry::Line::calculateVertices()
{
  this->vertices = {
    {"x0", this->_origin["x"]},
    {"y0", this->_origin["y"]},
    {"x1", this->_destination["x"]},
    {"y1", this->_destination["y"]}
  };

  this->recalculateSlope();
}

void Geometry::Line::recalculateSlope()
{
  this->slope = {this->_origin, this->_destination};
}

double Geometry::Line::operator [](const std::string& vertex) const
{
  return this->vertices.at(vertex);
}

double& Geometry::Line::operator [](const std::string& vertex)
{
  return this->vertices[vertex];
}

double Geometry::Line::gradient() const
{
  return this->slope.gradient();
}

double Geometry::Line::run() const
{
  return this->slope.run();
}

double Geometry::Line::rise() const
{
  return this->slope.rise();
}

bool Geometry::Line::isDescendingByX() const
{
  return this->slope.isDescendingByX();
}

bool Geometry::Line::isDescendingByY() const
{
  return this->slope.isDescendingByY();
}

bool Geometry::Line::isSloped() const
{
  return this->slope.isSloped();
}

bool Geometry::Line::isSlopeless() const
{
  return this->slope.isSlopeless();
}

bool Geometry::Line::isHorizontallySloped() const
{
  return this->slope.isHorizontallySloped();
}

bool Geometry::Line::isVerticallySloped() const
{
  return this->slope.isVerticallySloped();
}

bool Geometry::Line::isVerticalLine() const
{
  return this->slope.isVerticalLine();
}

bool Geometry::Line::isHorizontalLine() const
{
  return this->slope.isHorizontalLine();
}

bool Geometry::Line::isTraversingEast() const
{
  return this->slope.isTraversingEast();
}

bool Geometry::Line::isTraversingWest() const
{
  return this->slope.isTraversingWest();
}

bool Geometry::Line::isTraversingNorth() const
{
  return this->slope.isTraversingNorth();
}

bool Geometry::Line::isTraversingSouth() const
{
  return this->slope.isTraversingSouth();
}

double Geometry::Line::xLowerBound() const
{
  return this->slope.xLowerBound();
}

double Geometry::Line::xUpperBound() const
{
  return this->slope.xUpperBound();
}

double Geometry::Line::yLowerBound() const
{
  return this->slope.yLowerBound();
}

double Geometry::Line::yUpperBound() const
{
  return this->slope.yUpperBound();
}