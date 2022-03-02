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
  auto rise = this->axes.rise();
  auto run = this->axes.run();
  auto xAxis = this->axes.horizontalAxis();
  auto yAxis = this->axes.verticalAxis();
  auto yChangeAmount = this->axes.verticalChangeAmount();

  double D = (2 * rise) - run;

  auto x0 = line[xAxis + "0"];
  auto x1 = line[xAxis + "1"];
  auto y = line[yAxis + "0"];

  for (auto x = x0; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += yChangeAmount;
      D += 2 * (rise - run);
    }

    else 
      D += 2 * rise;
  }
}