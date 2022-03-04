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

  std::vector<double> xCoordinates = this->range(x0, x1);

  auto y0 = line["y0"];
  auto y1 = line["y1"];

  std::vector<double> yCoordinates = this->range(y0, y1);

  auto plots = this->cartesianProduct(xCoordinates, yCoordinates);
  
  for (auto plot : plots)
    this->plotPoints.push_back(plot);
}

std::vector<Maths::Vector> Geometry::LinePlotter::cartesianProduct(
  std::vector<double> set1, std::vector<double> set2)
{
  std::vector<Maths::Vector> cartesianProduct;

  for (auto x : set1)
    for (auto y : set2)
      cartesianProduct.push_back({x,y});

  return cartesianProduct;
}

std::vector<double> Geometry::LinePlotter::range(double value1, double value2)
{
  auto lowerBound = this->lowerBound(value1, value2);
  auto upperBound = this->upperBound(value1, value2);

  std::vector<double> range;

  for (int i = lowerBound; i <= upperBound; i++)
    range.push_back(i);

  return range;
}

double Geometry::LinePlotter::lowerBound(double value1, double value2)
{
  return value1 < value2 ? value1 : value2;
}

double Geometry::LinePlotter::upperBound(double value1, double value2)
{
  return value1 > value2 ? value1 : value2;
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