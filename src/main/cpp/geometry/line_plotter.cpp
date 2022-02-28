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
  std::vector<std::pair<int,int>> plotPoints {};

  double x0 = 0;
  double y0 = 0;
  std::pair<double,double> origin {x0, y0};

  auto x1 = destination.first;
  auto y1 = destination.second;

  GradientCalculator gradientCalculator;

  /* Both ends of the line start at halfway points rather than dot on
  an axis, so deduct one total from the run and rise distance
  variables.*/
  auto dx = gradientCalculator.run(origin, destination) - 1;
  auto dy = gradientCalculator.rise(origin, destination) - 1;
  double yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = 0 - dy;
  }

  auto gradient = gradientCalculator.fromOriginZero(x1, y1);

  double D = (2 * dy) - dx;
  double y = y0;

  // 6, 3 errors up.

  for (double x = x0; x < x1; x++) {
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