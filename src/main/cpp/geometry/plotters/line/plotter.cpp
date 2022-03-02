#include <cmath>

#include "src/main/cpp/geometry/plotters/line/plotter.h"

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
  this->axes = {line};
  double D = (2 * this->axes.rise()) - this->axes.run();

  auto x0 = line.origin()[this->axes.xAxis()];
  auto x1 = line.destination()[this->axes.xAxis()];
  auto y = line.origin()[this->axes.yAxis()];

  for (auto x = x0; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += this->axes.yChangeAmount();
      D += 2 * (this->axes.rise() - this->axes.run());
    }

    else 
      D += 2 * axes.rise();
  }
}