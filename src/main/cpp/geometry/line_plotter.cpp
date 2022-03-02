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
  auto axes = this->axes(line);
  double D = (2 * axes.rise) - axes.run;

  auto x0 = line.origin()[axes.xAxis];
  auto x1 = line.destination()[axes.xAxis];
  auto y = line.origin()[axes.yAxis];

  for (auto x = x0; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += axes.yAxisIncreaseAmount;
      D += 2 * (axes.rise - axes.run);
    }

    else 
      D += 2 * axes.rise;
  }
}

Geometry::LinePlotter::Axes Geometry::LinePlotter::axes(Geometry::Line line)
{
  Geometry::LinePlotter::Axes axes;
  
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis)
    axes = this->tiltedAxis(line);

  else
    axes = this->normalAxis(line);

  axes.yAxisIncreaseAmount = 1;

  if (line.isTraversingSouth()) {
    axes.yAxisIncreaseAmount = -1;
    axes.rise = 0 - axes.rise;
  }

  return axes;
}

Geometry::LinePlotter::Axes Geometry::LinePlotter::normalAxis(
  Geometry::Line line)
{
  Geometry::LinePlotter::Axes axes;

  axes.xAxis = "x";
  axes.yAxis = "y";
  axes.run = line.run();
  axes.rise = line.rise();

  return axes;
}

Geometry::LinePlotter::Axes Geometry::LinePlotter::tiltedAxis(
  Geometry::Line line)
{
  Geometry::LinePlotter::Axes axes;

  axes.xAxis = "y";
  axes.yAxis = "x";
  axes.run = line.rise();
  axes.rise = line.run();

  return axes;
}