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