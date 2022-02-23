#include "src/geometry/line_plotter.h"
#include "src/geometry/gradient_calculator.h"

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::plotPoints(
  std::pair<double,double> destination)
{
  std::vector<std::pair<int,int>> plotPoints {};

  return {};
}

double Geometry::LinePlotter::calculateYError(double x, double y)
{
  GradientCalculator gradientCalculator;

  auto gradient = gradientCalculator.fromOriginZero(x, y);
  double yError = y - x * gradient;

  return gradient;
}
