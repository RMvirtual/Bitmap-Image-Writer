#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"
#include "src/main/cpp/geometry/gradient.h"

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
  Gradient gradient {origin, destination};
  std::vector<std::pair<int,int>> plotPoints;

  if (gradient.isHorizontallySloped())
    plotPoints = this->horizontalLinePlot(origin, destination);
  
  else
    plotPoints = this->verticalLinePlot(origin, destination);

  return plotPoints;
}

/* Could merge this and plotLineHigh together using Axis as variable. */
std::vector<std::pair<int,int>> Geometry::LinePlotter::plotLineLow(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  auto x0 = origin.first;
  auto y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
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
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  double x0 = origin.first;
  double y0 = origin.second;

  auto x1 = destination.first;
  auto y1 = destination.second;

  Gradient gradient {origin, destination};
  auto run = gradient.run();
  auto rise = gradient.rise();
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
  Gradient gradient {origin, destination};
  std::vector<std::pair<int,int>> plotPoints;

  if (gradient.isTraversingLeftToRight())
    plotPoints = this->plotLineLow(origin, destination);

  else
    plotPoints = this->plotLineLow(destination, origin);

  return plotPoints;
}

std::vector<std::pair<int,int>> Geometry::LinePlotter::verticalLinePlot(
  std::pair<double,double> origin, std::pair<double,double> destination)
{
  Gradient gradient {origin, destination};
  std::vector<std::pair<int,int>> plotPoints;

  if (gradient.isTraversingUpwards())
    plotPoints = this->plotLineHigh(origin, destination);

  else
    plotPoints = this->plotLineHigh(destination, origin);

  return plotPoints;
}