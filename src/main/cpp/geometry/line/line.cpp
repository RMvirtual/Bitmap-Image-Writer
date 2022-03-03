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
  bool isHorizontal = (
    this->isHorizontallySloped() || this->isHorizontalLine());

  return (isHorizontal && this->isTraversingWest());
}

bool Geometry::Line::hasVerticallyReversedEndpoints()
{
  bool isVertical = (
    this->isVerticallySloped() || this->isVerticalLine());

  return (isVertical && this->isTraversingSouth());
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

bool Geometry::Line::isSlopeless()
{
  return (this->isHorizontalLine() || this->isVerticalLine());
}

bool Geometry::Line::isSloped()
{
  return (!this->isSlopeless());
}

bool Geometry::Line::isHorizontallySloped()
{
  return this->isSloped() ? abs(this->run()) > abs(this->rise()) : false; 
}

bool Geometry::Line::isVerticallySloped()
{
  return this->isSloped() ? abs(this->rise()) > abs(this->run()) : false;
}

bool Geometry::Line::isHorizontalLine()
{
  return this->rise() == 0.0;
}

bool Geometry::Line::isVerticalLine()
{
  return this->run() == 0.0;  
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