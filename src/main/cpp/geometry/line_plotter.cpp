#include <cmath>
#include <iostream>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/gradient_calculator.h"

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
  auto dx = gradientCalculator.run({0, 0}, destination);
  auto dy = gradientCalculator.rise({0, 0}, destination);
  double yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = 0 - dy;
  }

  std::cout << "Starting points...\n";
  std::cout << "DX: " << dx << " DY: " << dy << " yi: " << yi << std::endl;

  auto gradient = gradientCalculator.fromOriginZero(x1, y1);

  double D = (2 * dy) - dx;
  double y = y0;

  // 6, 3 errors up.

  for (double x = x0; x < x1; x++) {
    std::cout << "X: " << x;
    std::cout << ", D: " << D << std::endl;

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