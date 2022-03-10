#include <cmath>
#include "src/main/cpp/maths/range/range.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(
  const Geometry::Line& line)
{  
  this->plotPoints.clear();

  if (line.isSloped())
    this->plotSlopedLine(line);

  else
    this->plotSlopelessLine(line);

  return plotPoints;
}

void Geometry::LinePlotter::plotSlopelessLine(const Geometry::Line& line)
{
  auto xCoordinates = Maths::range(line["x0"], line["x1"]);
  auto yCoordinates = Maths::range(line["y0"], line["y1"]);
  auto plots = Maths::cartesianProduct(xCoordinates, yCoordinates);
  
  for (auto& plot : plots)
    this->plotPoints.push_back(plot);
}

void Geometry::LinePlotter::plotSlopedLine(const Geometry::Line& line)
{
  auto sortedLine = line;
  sortedLine.sortByXAscending();

  auto constantAxisLowerBound = sortedLine["x0"];
  auto constantAxisUpperBound = sortedLine["x1"];
  auto errorAxisLowerBound = sortedLine["y0"];
  auto errorAxisUpperBound = sortedLine["y1"];

  this->errorRun = sortedLine.run();
  this->errorRise = sortedLine.rise();

  this->initialiseErrorIncrementDirection();
  this->initialiseErrorTracker();

  auto constant = constantAxisLowerBound;
  auto error = errorAxisLowerBound;
  
  double* x = &constant;
  double* y = &error;

  if (sortedLine.isVerticallySloped()) {
    sortedLine.sortByYAscending();

    constantAxisLowerBound = sortedLine["y0"];
    constantAxisUpperBound = sortedLine["y1"];
    errorAxisLowerBound = sortedLine["x0"];
    errorAxisUpperBound = sortedLine["x1"];

    this->errorRun = sortedLine.rise();
    this->errorRise = sortedLine.run();

    this->initialiseErrorIncrementDirection();
    this->initialiseErrorTracker();

    constant = constantAxisLowerBound;
    error = errorAxisLowerBound;
  
    x = &error;
    y = &constant;
  }

  for (; constant <= constantAxisUpperBound; constant++) {
    this->plotPoints.push_back({*x, *y});
    this->updateErrorAxis(error);
  }
}

void Geometry::LinePlotter::initialiseErrorTracker()
{
  this->errorTracker = (2 * this->errorRise) - this->errorRun;
}

void Geometry::LinePlotter::initialiseErrorIncrementDirection()
{
  this->errorIncrementDirection = 1;

  if (this->errorRise < 0) {
    this->errorIncrementDirection = -1;
    this->errorRise = 0 - this->errorRise;
  }
}

void Geometry::LinePlotter::addPointWithYError(double x, double& y)
{
  this->plotPoints.push_back({x, y});
  this->updateErrorAxis(y);
}

void Geometry::LinePlotter::updateErrorAxis(double& errorAxis)
{
  auto errorAxisDirection = this->errorIncrementDirection;

  if (this->shouldIncrementErrorAxis())
    errorAxis += this->errorIncrementDirection;

  this->updateError();
}

bool Geometry::LinePlotter::shouldIncrementErrorAxis()
{
  return this->errorTracker > 0;
}

void Geometry::LinePlotter::updateError()
{
  auto errorChange = this->errorRise;

  if (this->shouldIncrementErrorAxis())
    errorChange -= this->errorRun;

  this->errorTracker += 2 * errorChange;  
}