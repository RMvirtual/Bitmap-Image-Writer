#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/gradient_calculator.h"

/* TODO: THIS NEEDS TIDYING UP AND UNDERSTANDING BETTER */

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::plotPoints(
  std::pair<double,double> destination)
{
  return this->plotPoints({0,0}, destination);
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::plotPoints(
    std::pair<double,double> origin, std::pair<double,double> destination)
{
  std::vector<std::pair<int,int>> plotPoints {};

  double x0 = origin.first;
  double y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  GradientCalculator gradientCalculator;
  auto dx = gradientCalculator.run(origin, destination);
  auto dy = gradientCalculator.rise(origin, destination);
  double yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = 0 - dy;
  }

  auto gradient = gradientCalculator.fromOriginZero(x1, y1);

  double D = (2 * dy) - dx;
  double y = y0;

  for (double x = x0; x <= x1; x++) {
    plotPoints.push_back({int(x), int(y)});

    if (D > 0) {
      y = y + yi;
      D = D + (2 * (dy-dx));
    }

    else {
      D = D + 2*dy;
    }
  }

  return plotPoints;
}

double Geometry::LinePlotter::calculateYError(double x, double y)
{
  if (x == 0 && y == 0)
    return 0;

  GradientCalculator gradientCalculator;

  auto gradient = gradientCalculator.fromOriginZero(x, y);
  double yError = y - x * gradient;

  return std::abs(yError);
}