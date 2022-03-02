#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"

// Bresenham's Line Drawing Algorithm.
/* TODO: THIS NEEDS TIDYING UP AND UNDERSTANDING BETTER */
Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{
  this->plotPoints.clear();
  line.normaliseEndpoints();
  this->createPlotPoints(line);

  return plotPoints;
}

void Geometry::LinePlotter::createPlotPoints(Geometry::Line line)
{
  std::string constantAxis = "x";
  std::string variableAxis = "y";

  auto run = line.run();
  auto rise = line.rise();

  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis) {
    constantAxis = "y";
    variableAxis = "x";

    run = line.rise();
    rise = line.run();
  }

  double variableAxisIncrease = 1;

  if (rise < 0) {
    variableAxisIncrease = -1;
    rise = 0 - rise;
  }

  double D = (2 * rise) - run;

  double x = line.origin()[constantAxis];
  auto x1 = line.destination()[constantAxis];
  double y = line.origin()[variableAxis];

  for (; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += variableAxisIncrease;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }
}