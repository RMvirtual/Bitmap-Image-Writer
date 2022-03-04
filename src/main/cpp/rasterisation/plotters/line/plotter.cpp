#include <cmath>
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{  
  if (line.isSloped())
    this->plotSlopedLine(line);

  else
    this->plotSlopelessLine(line);

  return plotPoints;
}

void Geometry::LinePlotter::initialise(Geometry::Line line)
{
  this->plotPoints.clear();
  line.normaliseEndpoints();

  this->slopedAxes = {line};
  this->initialiseYError();
}

void Geometry::LinePlotter::plotSlopelessLine(Geometry::Line line)
{
  // Could do cartesian product of the ranges of x and y.
  auto x0 = line["x0"];
  auto x1 = line["x1"];

  auto lowerBound = x0;
  auto upperBound = x1;

  if (upperBound < lowerBound) {
    lowerBound = x1;
    upperBound = x0;
  }

  std::vector<double> xCoordinates;

  for (double x = lowerBound; x <= upperBound; x++)
    xCoordinates.push_back(x);

  auto y0 = line["y0"];
  auto y1 = line["y1"];

  lowerBound = y0;
  upperBound = y1;

  if (upperBound < lowerBound) {
    lowerBound = y1;
    upperBound = y0;
  }

  std::vector<double> yCoordinates;

  for (double y = lowerBound; y <= upperBound; y++)
    yCoordinates.push_back(y);

  for (auto x : xCoordinates)
    for (auto y : yCoordinates)
      this->addPoint(x, y);
}

void Geometry::LinePlotter::plotSlopedLine(Geometry::Line line)
{
  this->initialise(line);

  auto x0 = line[this->slopedAxes["x0"]];
  auto x1 = line[this->slopedAxes["x1"]];
  auto y = line[this->slopedAxes["y0"]];

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
  auto yDirection = this->slopedAxes.verticalIncrementDirection();

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
  auto rise = this->slopedAxes.rise();
  auto run = this->slopedAxes.run();

  this->yError = (2 * rise) - run;
}

void Geometry::LinePlotter::updateYError()
{
  auto yErrorChange = this->slopedAxes.rise();

  if (this->shouldIncrementY())
    yErrorChange -= this->slopedAxes.run();

  this->yError += 2 * yErrorChange;  
}