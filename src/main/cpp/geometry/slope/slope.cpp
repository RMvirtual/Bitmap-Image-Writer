#include <algorithm>
#include "src/main/cpp/geometry/slope/slope.h"

Geometry::Slope::Slope()
{
  this->_origin = {0,0};
  this->_destination = {0,0};
}

Geometry::Slope::Slope(
  const Maths::Vector& origin, const Maths::Vector& destination)
{
  this->_origin = origin;
  this->_destination = destination;
}

Geometry::Slope::Slope(const Maths::Vector& destination)
{
  this->_origin = {0.0, 0.0};
  this->_destination = destination;
}

double Geometry::Slope::gradient() const
{
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);
  // Not too sure on what value to return when x's change is 0 as
  // can't divide by zero.

  return hasZeroDivision ? 0 : yChange / xChange;
}

double Geometry::Slope::run() const
{
  return this->_destination["x"] - this->_origin["x"];
}

double Geometry::Slope::rise() const
{
  return this->_destination["y"] - this->_origin["y"];
}

bool Geometry::Slope::isSloped() const
{
  return !this->isSlopeless();
}

bool Geometry::Slope::isSlopeless() const
{
  return (this->isHorizontallyStraight() || this->isVerticallyStraight());
}

bool Geometry::Slope::isHorizontallySloped() const
{
  bool isHorizontallySloped = false;

  if (this->isSloped())
    isHorizontallySloped = abs(this->run()) > abs(this->rise());

  return isHorizontallySloped;
}

bool Geometry::Slope::isVerticallySloped() const
{
  bool isVerticallySloped = false;

  if (this->isSloped())
    isVerticallySloped = abs(this->rise()) > abs(this->run());

  return isVerticallySloped;
}

bool Geometry::Slope::isVerticallyStraight() const
{
  return this->_origin["x"] == this->_destination["x"];
}

bool Geometry::Slope::isHorizontallyStraight() const
{
  return this->_origin["y"] == this->_destination["y"];  
}

bool Geometry::Slope::isAscendingByX() const
{
  return this->_origin["x"] < this->_destination["x"];
}

bool Geometry::Slope::isAscendingByY() const
{
  return this->_origin["y"] < this->_destination["y"];
}

bool Geometry::Slope::isDescendingByX() const
{
  return this->_origin["x"] > this->_destination["x"];
}

bool Geometry::Slope::isDescendingByY() const
{
  return this->_origin["y"] > this->_destination["y"];
}

bool Geometry::Slope::isTraversingEast() const
{
  return this->isAscendingByX();
}

bool Geometry::Slope::isTraversingWest() const
{
  return this->isDescendingByX();
}

bool Geometry::Slope::isTraversingNorth() const
{
  return this->isAscendingByY();
}

bool Geometry::Slope::isTraversingSouth() const
{
  return this->isDescendingByY();
}

double Geometry::Slope::xLowerBound() const
{
  return std::min(this->_origin["x"], this->_destination["x"]);
}

double Geometry::Slope::xUpperBound() const
{
  return std::max(this->_origin["x"], this->_destination["x"]);
}

double Geometry::Slope::yLowerBound() const
{
  return std::min(this->_origin["y"], this->_destination["y"]);
}

double Geometry::Slope::yUpperBound() const
{
  return std::max(this->_origin["y"], this->_destination["y"]);
}

std::string Geometry::Slope::toString() const
{
  std::string representation = {
    "Gradient" + std::to_string(this->gradient()) + ", "};

  return representation;
}