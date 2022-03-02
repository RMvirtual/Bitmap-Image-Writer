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
  auto horizontalAxis = this->axes.horizontalAxis();
  auto verticalAxis = this->axes.verticalAxis();
  auto verticalChangeAmount = this->axes.verticalChangeAmount();

  this->initialiseYError();

  auto x0 = line[horizontalAxis + "0"];
  auto x1 = line[horizontalAxis + "1"];
  auto y = line[verticalAxis + "0"];

  for (auto x = x0; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (this->shouldIncrementY())
      y += verticalChangeAmount;

    this->updateYError();
  }
}

bool Geometry::LinePlotter::shouldIncrementY()
{
  return this->yError > 0;
}

void Geometry::LinePlotter::initialiseYError()
{
  auto rise = this->axes.rise();
  auto run = this->axes.run();

  this->yError = (2 * rise) - run;
}

void Geometry::LinePlotter::updateYError()
{
  auto yErrorChange = this->axes.rise();

  if (this->shouldIncrementY())
    yErrorChange -= this->axes.run();

  this->yError += 2 * yErrorChange;  
}