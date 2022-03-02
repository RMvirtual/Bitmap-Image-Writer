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

Geometry::LinePlotter::PlottingAxes Geometry::LinePlotter::plottingAxes(
  Geometry::Line line)
{
  Geometry::LinePlotter::PlottingAxes axes;
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis) {
    axes.xAxis = "y";
    axes.yAxis = "x";

    axes.run = line.rise();
    axes.rise = line.run();
  }

  else {
    axes.xAxis = "x";
    axes.yAxis = "y";
    axes.run = line.run();
    axes.rise = line.rise();
  }

  axes.yAxisIncreaseAmount = 1;

  if (axes.rise < 0) {
    axes.yAxisIncreaseAmount = -1;
    axes.rise = 0 - axes.rise;
  }

  return axes;
}

void Geometry::LinePlotter::createPlotPoints(Geometry::Line line)
{
  auto axes = this->plottingAxes(line);

  double D = (2 * axes.rise) - axes.run;

  double x = line.origin()[axes.xAxis];
  auto x1 = line.destination()[axes.xAxis];
  double y = line.origin()[axes.yAxis];

  for (; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += axes.yAxisIncreaseAmount;
      D += 2 * (axes.rise - axes.run);
    }

    else 
      D += 2 * axes.rise;
  }
}