#include "src/geometry/gradient_calculator.h"

Geometry::GradientCalculator::GradientCalculator()
{
  // pass.
}

float Geometry::GradientCalculator::gradient(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  auto xChange = destination.first - origin.first;
  auto yChange = destination.second - origin.second;

  return yChange / xChange;
}

float Geometry::GradientCalculator::fromOriginZero(double x, double y)
{
  return y / x;
}