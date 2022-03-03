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
  
  if (line.isSloped())
    this->plotSlopedLine(line);

  else
    this->plotSlopelessLine(line);

  return plotPoints;
}

void Geometry::LinePlotter::initialise(Geometry::Line line)
{
  this->plotPoints.clear();

  this->axes = {line};
  this->initialiseYError();
}

void Geometry::LinePlotter::plotSlopelessLine(Geometry::Line line)
{
  auto x0 = line["x0"];
  auto x1 = line["x1"];
  auto x = x0;

  auto y0 = line["y0"];
  auto y1 = line["y1"];
  auto y = y0;

  auto axisRange = x1;
  auto axisToIncrement = &x;

  if (line.isVerticalLine()) {
    axisRange = y1;
    axisToIncrement = &y;
  }
  
  for (; *axisToIncrement <= axisRange; (*axisToIncrement)++)
    this->addPoint(x, y);
}

void Geometry::LinePlotter::plotSlopedLine(Geometry::Line line)
{
  auto x0 = line[this->axes["x0"]];
  auto x1 = line[this->axes["x1"]];
  auto y = line[this->axes["y0"]];

  for (auto x = x0; x <= x1; x++)
    this->addPointWithYError(x, y);
}

void Geometry::LinePlotter::addPoint(double x, double&y)
{
    this->plotPoints.push_back({x, y});
}

void Geometry::LinePlotter::addPointWithYError(double x, double&y)
{
    this->addPoint(x, y);
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