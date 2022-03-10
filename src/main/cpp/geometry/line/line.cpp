#include <algorithm>
#include "src/main/cpp/geometry/line/line.h"

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

bool Geometry::Line::isDescendingByX() const
{
  return this->isTraversingWest();
}

bool Geometry::Line::isDescendingByY() const
{
  return this->isTraversingSouth();
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
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);
  // Not too sure on what value to return when x's change is 0 as
  // can't divide by zero.

  return hasZeroDivision ? 0 : yChange / xChange;
}

double Geometry::Line::run() const
{
  return this->_destination["x"] - this->_origin["x"];
}

double Geometry::Line::rise() const
{
  return this->_destination["y"] - this->_origin["y"];
}

bool Geometry::Line::isSloped() const
{
  return !this->isSlopeless();
}

bool Geometry::Line::isSlopeless() const
{
  return (this->isHorizontalLine() || this->isVerticalLine());
}

bool Geometry::Line::isHorizontallySloped() const
{
  return this->isSloped() ? abs(this->run()) > abs(this->rise()) : false; 
}

bool Geometry::Line::isVerticallySloped() const
{
  return this->isSloped() ? abs(this->rise()) > abs(this->run()) : false;
}

bool Geometry::Line::isVerticalLine() const
{
  return this->_origin["x"] == this->_destination["x"];
}

bool Geometry::Line::isHorizontalLine() const
{
  return this->_origin["y"] == this->_destination["y"];
}

bool Geometry::Line::isTraversingEast() const
{
  return this->_origin["x"] < this->_destination["x"];
}

bool Geometry::Line::isTraversingWest() const
{
  return this->_origin["x"] > this->_destination["x"];
}

bool Geometry::Line::isTraversingNorth() const
{
  return this->_origin["y"] < this->_destination["y"];
}

bool Geometry::Line::isTraversingSouth() const
{
  return this->_origin["y"] > this->_destination["y"];
}

double Geometry::Line::xLowerBound() const
{
  return std::min(this->_origin["x"], this->_destination["x"]);
}

double Geometry::Line::xUpperBound() const
{
  return std::max(this->_origin["x"], this->_destination["x"]);
}

double Geometry::Line::yLowerBound() const
{
  return std::min(this->_origin["y"], this->_destination["y"]);
}

double Geometry::Line::yUpperBound() const
{
  return std::max(this->_origin["y"], this->_destination["y"]);
}