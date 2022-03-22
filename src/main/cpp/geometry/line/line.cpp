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
  this->setEndpoints(coordinates, this->_destination);
}

void Geometry::Line::setDestination(const Maths::Vector& coordinates)
{
  this->setEndpoints(this->_origin, coordinates);
}

void Geometry::Line::setEndpoints(
  const Maths::Vector& origin, const Maths::Vector& destination)
{
  this->_origin = origin;
  this->_destination = destination;
  this->calculateSlope();
}

void Geometry::Line::calculateSlope()
{
  this->slope = {this->_origin, this->_destination};
}

void Geometry::Line::switchEndpoints()
{
  this->setEndpoints(this->destination(), this->origin());
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

void Geometry::Line::translate(const Maths::Vector& translation)
{
  auto translatedOrigin = this->_origin + translation;
  auto translatedDestination = this->_destination + translation;

  this->setEndpoints(translatedOrigin, translatedDestination);
}

void Geometry::Line::scale(double scaleFactor, const Maths::Vector& origin)
{
  auto newOrigin = this->scaleVectorFromOrigin(
    this->_origin, scaleFactor, origin);

  auto newDestination = this->scaleVectorFromOrigin(
    this->_destination, scaleFactor, origin);
  
  this->setEndpoints(newOrigin, newDestination);
}

void Geometry::Line::scale(double scaleFactor)
{
  auto lineLength = this->_destination - this->_origin;
  auto scaledLength = lineLength * scaleFactor;
  auto newDestination = this->_origin + scaledLength;
  
  this->setDestination(newDestination);
}

Maths::Vector Geometry::Line::scaleVectorFromOrigin(
  const Maths::Vector& vector, double scaleFactor,
  const Maths::Vector& origin) const
{
  auto length = vector - origin;
  auto scaledLength =  length * scaleFactor;
  
  return origin + scaledLength;
}

void Geometry::Line::scaleIncludingOrigin(double scaleFactor)
{
  auto newOrigin = this->_origin * scaleFactor;
  auto newDestination = this->_destination * scaleFactor;
  
  this->setEndpoints(newOrigin, newDestination);
}

/**
 * @brief Indexed from x0-x1, y0-y1.
 */
double Geometry::Line::operator [](const std::string& vertex) const
{
  std::string indexString = {vertex[1]};
  int index = std::stoi(indexString);
  std::string coordinate {vertex[0]};

  auto endPoint = this->_origin;

  if (index == 1)
    endPoint = this->_destination;

  return endPoint[coordinate];
}

/**
 * @brief Indexed from x0-x1, y0-y1.
 */
double& Geometry::Line::operator [](const std::string& vertex)
{
  std::string indexString = {vertex[1]};
  int index = std::stoi(indexString);
  std::string coordinate {vertex[0]};

  auto endPoint = this->_origin;

  if (index == 1)
    endPoint = this->_destination;

  return endPoint[coordinate];
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

bool Geometry::Line::isVerticallyStraight() const
{
  return this->slope.isVerticallyStraight();
}

bool Geometry::Line::isHorizontallyStraight() const
{
  return this->slope.isHorizontallyStraight();
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