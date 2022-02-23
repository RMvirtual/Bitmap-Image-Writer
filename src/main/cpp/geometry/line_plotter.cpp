#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/gradient_calculator.h"

#include <cmath>
#include <iostream>

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::plotPoints(
  std::pair<double,double> destination)
{
  std::vector<std::pair<int,int>> plotPoints {};

  double x0 = 0;
  double y0 = 0;

  auto x1 = destination.first;
  auto y1 = destination.second;

  GradientCalculator gradientCalculator;
  auto run = gradientCalculator.run({0, 0}, destination);
  auto rise = gradientCalculator.rise({0, 0}, destination);
  double yIntercept = 1;

  if (rise < 0) {
    yIntercept = -1;
    rise = std::abs(rise);
  }

  auto gradient = gradientCalculator.fromOriginZero(x1, y1);

  double d = (2 * rise) - run;
  double y = y0;

  for (double x = x0; x < x1; x++) {
    plotPoints.push_back({x, y});
    std::cout << "d: " << d << std::endl;

    if (d > 0) {
      y += yIntercept;
      d -= 2 * run;
    }

    d += 2 * rise;
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