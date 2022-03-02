#include <cmath>

#include "src/main/cpp/geometry/plotters/line/plotter.h"

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{
  line.normaliseEndpoints();
  this->initialise(line);
  this->createPlotPoints(line);

  return plotPoints;
}

void Geometry::LinePlotter::initialise(Geometry::Line line)
{
  this->plotPoints.clear();
  this->axes = {line};
  this->initialiseYError();
}

void Geometry::LinePlotter::createPlotPoints(Geometry::Line line)
{
  auto horizontalAxis = this->axes.horizontalAxis();
  auto verticalAxis = this->axes.verticalAxis();
  auto verticalChangeAmount = this->axes.verticalChangeAmount();

  auto x0 = line[this->axes["x0"]];
  auto x1 = line[this->axes["x1"]];
  auto y = line[this->axes["y0"]];

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