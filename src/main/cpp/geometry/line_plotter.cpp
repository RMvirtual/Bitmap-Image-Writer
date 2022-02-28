#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/gradient_calculator.h"

// Bresenham's Line Drawing Algorithm.
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
  double x0 = origin.first;
  double y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  std::vector<std::pair<int,int>> plotPoints;

  if (abs(y1 - y0) < abs(x1 - x0)) {
    if (x0 > x1)
      plotPoints = this->plotLineLow(x1, y1, x0, y0);
    else
      plotPoints = this->plotLineLow(x0, y0, x1, y1);
  }
  
  else {
    if (y0 > y1)
      plotPoints = this->plotLineHigh(x1, y1, x0, y0);
    else
      plotPoints = this->plotLineHigh(x0, y0, x1, y1);
  }

  return plotPoints;
}

/* Could merge this and plotLineHigh together using Axis as variable. */
std::vector<std::pair<int,int>> Geometry::LinePlotter::plotLineLow(
  double x0, double y0, double x1, double y1)
{
  auto dx = x1 - x0;
  auto dy = y1 - y0;
  double yi = 1;

  if (dy < 0) {
    yi = -1;
    dy = 0 - dy;
  }

  double D = (2 * dy) - dx;
  double y = y0;

  std::vector<std::pair<int,int>> plotPoints {};

  for (double x = x0; x <= x1; x++) {
    plotPoints.push_back({int(x), int(y)});

    if (D > 0) {
      y = y + yi;
      D = D + (2 * (dy-dx));
    }

    else 
      D = D + 2*dy;
  }

  return plotPoints;
}

/* Could merge this and plotLineLow together using Axis as variable. */
std::vector<std::pair<int,int>> Geometry::LinePlotter::plotLineHigh(
  double x0, double y0, double x1, double y1)
{
  auto dx = x1 - x0;
  auto dy = y1 - y0;
  double xi = 1;

  if (dx < 0) {
    xi = -1;
    dx = 0 - dx;
  }

  double D = (2 * dx) - dy;
  double x = x0;

  std::vector<std::pair<int,int>> plotPoints {};

  for (double y = y0; y <= y1; y++) {
    plotPoints.push_back({int(x), int(y)});

    if (D > 0) {
      x = x + xi;
      D = D + (2 * (dx-dy));
    }

    else
      D = D + 2*dx;
  }

  return plotPoints;
}
