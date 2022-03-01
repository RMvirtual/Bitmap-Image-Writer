#include "src/main/cpp/geometry/gradient_calculator.h"

Geometry::GradientCalculator::GradientCalculator()
{
  // pass.
}

double Geometry::GradientCalculator::gradient(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  auto xChange = this->run(origin, destination);
  auto yChange = this->rise(origin, destination);

  bool hasZeroDivision = (xChange == 0);

  return hasZeroDivision ? 1 : yChange / xChange;
}

double Geometry::GradientCalculator::fromOriginZero(double x, double y)
{
  return this->gradient({0, 0}, {x, y});
}

double Geometry::GradientCalculator::run(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  return destination.first - origin.first; 
}

double Geometry::GradientCalculator::rise(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  return destination.second - origin.second;
}

bool Geometry::GradientCalculator::isHorizontallySloped(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  auto run = this->run(origin, destination);
  auto rise = this->rise(origin, destination);

  return (abs(rise) < abs(run));
}

bool Geometry::GradientCalculator::isTraversingUpwards(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  double y0 = origin.second;
  auto y1 = destination.second;

  return y0 < y1;
}

bool Geometry::GradientCalculator::isTraversingLeftToRight(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  double x0 = origin.first;
  auto x1 = destination.first;

  return x0 < x1;
}