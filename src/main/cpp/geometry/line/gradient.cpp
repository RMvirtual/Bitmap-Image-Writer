#include "src/main/cpp/geometry/line/gradient.h"

Geometry::Gradient::Gradient()
{
  this->origin = {0,0};
  this->destination = {0,0};
}

Geometry::Gradient::Gradient(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  this->origin = origin;
  this->destination = destination;
}

Geometry::Gradient Geometry::Gradient::fromOriginZero(double x, double y)
{
  return {{0, 0}, {x, y}};
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
  return destination.first - origin.first; 
}

double Geometry::Gradient::rise()
{
  return destination.second - origin.second;
}

bool Geometry::Gradient::isHorizontallySloped()
{
  return abs(this->rise()) < abs(this->run());
}

bool Geometry::Gradient::isTraversingUpwards()
{
  auto y0 = origin.second;
  auto y1 = destination.second;

  return y0 < y1;
}

bool Geometry::Gradient::isTraversingLeftToRight()
{
  auto x0 = origin.first;
  auto x1 = destination.first;

  return x0 < x1;
}