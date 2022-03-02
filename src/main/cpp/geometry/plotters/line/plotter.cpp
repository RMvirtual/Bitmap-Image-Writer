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
  auto tiltedX0 = line[this->axes["x0"]];
  auto tiltedX1 = line[this->axes["x1"]];
  auto y = line[this->axes["y0"]];

  for (auto x = tiltedX0; x <= tiltedX1; x++)
    this->processPoints(x, y);
}

void Geometry::LinePlotter::processPoints(double x, double&y)
{
    this->plotPoints.push_back({x, y});
    this->updateY(y);
}

void Geometry::LinePlotter::updateY(double& y)
{
  auto yDirection = this->axes.verticalIncrementDirection();

  if (this->shouldIncrementY())
    y += yDirection;

  this->updateYError();
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