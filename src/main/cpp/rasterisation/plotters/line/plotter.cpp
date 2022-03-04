#include <cmath>
#include "src/main/cpp/maths/range/range.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

Geometry::LinePlotter::LinePlotter()
{
  // pass.
}

std::vector<Maths::Vector> Geometry::LinePlotter::plot(Geometry::Line line)
{  
  this->plotPoints.clear();

  if (line.isSloped())
    this->plotSlopedLine(line);

  else
    this->plotSlopelessLine(line);

  return plotPoints;
}

void Geometry::LinePlotter::plotSlopelessLine(Geometry::Line line)
{
  auto xCoordinates = Maths::range(line["x0"], line["x1"]);
  auto yCoordinates = Maths::range(line["y0"], line["y1"]);
  auto plots = Maths::cartesianProduct(xCoordinates, yCoordinates);
  
  for (auto plot : plots)
    this->plotPoints.push_back(plot);
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

void Geometry::LinePlotter::initialise(Geometry::Line line)
{
  line.sortByXAscending();

  this->slopedAxes = {line};
  this->initialiseYError();
}

void Geometry::LinePlotter::initialiseYError()
{
  auto rise = this->slopedAxes.rise();
  auto run = this->slopedAxes.run();

  this->yError = (2 * rise) - run;
}

void Geometry::LinePlotter::addPointWithYError(double x, double&y)
{
  this->plotPoints.push_back({x, y});
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

void Geometry::LinePlotter::updateYError()
{
  auto yErrorChange = this->slopedAxes.rise();

  if (this->shouldIncrementY())
    yErrorChange -= this->slopedAxes.run();

  this->yError += 2 * yErrorChange;  
}