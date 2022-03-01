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
  GradientCalculator gradient;
  bool horizontallySloped = gradient.isHorizontallySloped(origin, destination);

  std::vector<std::pair<int,int>> plotPoints;

  if (horizontallySloped)
    plotPoints = this->horizontalLinePlot(origin, destination);
  
  else
    plotPoints = this->verticalLinePlot(origin, destination);

  return plotPoints;
}

/* Could merge this and plotLineHigh together using Axis as variable. */
std::vector<std::pair<int,int>> Geometry::LinePlotter::plotLineLow(
  double x0, double y0, double x1, double y1)
{
  GradientCalculator gradient;
  auto run = gradient.run({x0,y0}, {x1,y1});
  auto rise = gradient.rise({x0,y0}, {x1,y1});
  double yi = 1;

  if (rise < 0) {
    yi = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;
  double y = y0;

  std::vector<std::pair<int,int>> plotPoints {};

  for (double x = x0; x <= x1; x++) {
    plotPoints.push_back({int(x), int(y)});

    if (D > 0) {
      y += yi;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }

  return plotPoints;
}


/* Could merge this and plotLineLow together using Axis as variable. */
std::vector<std::pair<int,int>> Geometry::LinePlotter::plotLineHigh(
  double x0, double y0, double x1, double y1)
{
  GradientCalculator gradient;
  auto run = gradient.run({x0,y0}, {x1,y1});
  auto rise = gradient.rise({x0,y0}, {x1,y1});
  double xi = 1;

  if (run < 0) {
    xi = -1;
    run = 0 - run;
  }

  double D = (2 * run) - rise;
  double x = x0;

  std::vector<std::pair<int,int>> plotPoints {};

  for (double y = y0; y <= y1; y++) {
    plotPoints.push_back({int(x), int(y)});

    if (D > 0) {
      x += xi;
      D += (2 * (run - rise));
    }

    else
      D += 2 * run;
  }

  return plotPoints;
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::horizontalLinePlot(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  std::vector<std::pair<int,int>> plotPoints;

  double x0 = origin.first;
  double y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  bool traversingLeftToRight = (x0 < x1);

  if (traversingLeftToRight)
    plotPoints = this->plotLineLow(x0, y0, x1, y1);

  else
    plotPoints = this->plotLineLow(x1, y1, x0, y0);

  return plotPoints;
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::verticalLinePlot(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  std::vector<std::pair<int,int>> plotPoints;

  double x0 = origin.first;
  double y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  bool traversingBottomToTop = (y0 < y1);

  if (traversingBottomToTop)
    plotPoints = this->plotLineHigh(x0, y0, x1, y1);

  else
    plotPoints = this->plotLineHigh(x1, y1, x0, y0);

  return plotPoints;
}
