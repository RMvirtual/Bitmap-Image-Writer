#include "src/main/cpp/geometry/line/gradient.h"

#include <iostream>

Geometry::Gradient::Gradient()
{
  this->origin = {0,0};
  this->destination = {0,0};
}

Geometry::Gradient::Gradient(Maths::Vector origin, Maths::Vector destination)
{
  this->origin = origin;
  this->destination = destination;
}

Geometry::Gradient Geometry::Gradient::fromOriginZero(
  Maths::Vector destination)
{
  return {{0.0, 0.0}, destination};
}

double Geometry::Gradient::gradient()
{
  auto xChange = this->run();
  auto yChange = this->rise();

  bool hasZeroDivision = (xChange == 0);

  return hasZeroDivision ? 1 : yChange / xChange;
}

double Geometry::Gradient::run()
{
  std::cout << this->origin << std::endl;
  // Origin[x] appears to error out when origin value is 0.
  std::cout << this->origin["x"] << "\n";
  std::cout << this->destination["x"] << "\n";

  return this->destination["x"] - this->origin["x"]; 
}

double Geometry::Gradient::rise()
{
  return this->destination["y"] - this->origin["y"];
}

bool Geometry::Gradient::isHorizontallySloped()
{
  return abs(this->rise()) < abs(this->run());
}

bool Geometry::Gradient::isTraversingUpwards()
{
  return this->origin["y"] < this->destination["y"];
}

bool Geometry::Gradient::isTraversingLeftToRight()
{
  return this->origin["x"] < this->destination["x"];
}