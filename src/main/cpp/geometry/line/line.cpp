#include <unordered_map>
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

void Geometry::Line::switchEndpoints()
{
  auto originalOrigin = this->_origin;
  auto originalDestination = this->_destination;
  
  this->_destination = originalOrigin;
  this->_origin = originalDestination;
}

void Geometry::Line::translate(Maths::Vector translation)
{
  this->_origin = this->_origin + translation;
  this->_destination = this->_destination + translation;
}

void Geometry::Line::scale(double scalar)
{
  auto lineLength = this->_destination - this->_origin;
  auto scaledLength = lineLength * scalar;

  this->_destination = this->_origin + scaledLength;
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

bool Geometry::Line::isDescendingByX()
{
  return this->isTraversingWest();
}

bool Geometry::Line::isDescendingByY()
{
  return this->isTraversingSouth();
}

Maths::Vector Geometry::Line::origin()
{
  return this->_origin;
}

Maths::Vector Geometry::Line::destination()
{
  return this->_destination;
}

double Geometry::Line::operator [](std::string vertex)
{
  std::unordered_map<std::string, double> vertices {
    {"x0", this->_origin["x"]},
    {"y0", this->_origin["y"]},
    {"x1", this->_destination["x"]},
    {"y1", this->_destination["y"]}
  };

  return vertices[vertex];
}

double Geometry::Line::gradient()
{
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);
  // Not too sure on what value to return when x's change is 0 as
  // can't divide by zero.

  return hasZeroDivision ? 0 : yChange / xChange;
}

double Geometry::Line::run()
{
  return this->_destination["x"] - this->_origin["x"];
}

double Geometry::Line::rise()
{
  return this->_destination["y"] - this->_origin["y"];
}

bool Geometry::Line::isSloped()
{
  return !this->isSlopeless();
}

bool Geometry::Line::isSlopeless()
{
  return (this->isHorizontalLine() || this->isVerticalLine());
}

bool Geometry::Line::isHorizontallySloped()
{
  return this->isSloped() ? abs(this->run()) > abs(this->rise()) : false; 
}

bool Geometry::Line::isVerticallySloped()
{
  return this->isSloped() ? abs(this->rise()) > abs(this->run()) : false;
}

bool Geometry::Line::isVerticalLine()
{
  return this->_origin["x"] == this->_destination["x"];
}

bool Geometry::Line::isHorizontalLine()
{
  return this->_origin["y"] == this->_destination["y"];
}

bool Geometry::Line::isTraversingEast()
{
  return this->_origin["x"] < this->_destination["x"];
}

bool Geometry::Line::isTraversingWest()
{
  return this->_origin["x"] > this->_destination["x"];
}

bool Geometry::Line::isTraversingNorth()
{
  return this->_origin["y"] < this->_destination["y"];
}

bool Geometry::Line::isTraversingSouth()
{
  return this->_origin["y"] > this->_destination["y"];
}