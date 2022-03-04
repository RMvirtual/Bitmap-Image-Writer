#include <cmath>
#include "src/main/cpp/maths/range/range.h"
#include "src/main/cpp/rasterisation/plotters/line/plotter.h"

#include <iostream>

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

void Geometry::LinePlotter::plotSlopelessLine(Geometry::Line& line)
{
  auto xCoordinates = Maths::range(line["x0"], line["x1"]);
  auto yCoordinates = Maths::range(line["y0"], line["y1"]);
  auto plots = Maths::cartesianProduct(xCoordinates, yCoordinates);
  
  for (auto plot : plots)
    this->plotPoints.push_back(plot);
}

void Geometry::LinePlotter::plotSlopedLine(Geometry::Line& line)
{
  line.sortByXAscending();
  this->initialise(line);

  auto alteredX0 = this->errorAxes["x0"];
  auto alteredY0 = this->errorAxes["y0"];
  auto alteredX1 = this->errorAxes["x1"];
  auto alteredY1 = this->errorAxes["y1"];

  auto constantAxis0 = line[alteredX0];
  auto constantAxis1 = line[alteredX1];
  auto errorAxis0 = line[alteredY0];
  auto errorAxis1 = line[alteredY1];
  
  std::cout << "x0 : " << alteredX0 << std::endl;
  std::cout << "x1 : " << alteredX1 << std::endl;
  std::cout << "y0 : " << alteredY0 << std::endl;
  std::cout << "y1 : " << alteredY1 << std::endl;

  std::cout << "constant 0: " << constantAxis0 << std::endl;
  std::cout << "constant 1: " << constantAxis1 << std::endl;
  std::cout << "error 0: " << errorAxis0 << std::endl;
  std::cout << "error 1: " << errorAxis1 << std::endl;


  // Need to determine a:
    // constant axis
    // axis that increments upon error
  // Then need to map these to x and y in the right order depending.

  auto constant = constantAxis0;
  auto error = errorAxis0;
  
  double* x = &constant;
  double* y = &error;

  if (this->errorAxes.xIsErrorAxis()) {
    x = &error;
    y = &constant;
  }

  for (; constant <= constantAxis1; constant++) {
    this->plotPoints.push_back({*x, *y});
    this->updateErrorAxis(error);
  }
}

void Geometry::LinePlotter::initialise(Geometry::Line& line)
{
  this->errorAxes = {line};
  this->initialiseErrorAxis();
}

void Geometry::LinePlotter::initialiseErrorAxis()
{
  auto rise = this->errorAxes.rise();
  auto run = this->errorAxes.run();

  this->error = (2 * rise) - run;
}

void Geometry::LinePlotter::addPointWithYError(double x, double&y)
{
  this->plotPoints.push_back({x, y});
  this->updateErrorAxis(y);
}

void Geometry::LinePlotter::updateErrorAxis(double& errorAxis)
{
  auto errorAxisDirection = this->errorAxes.verticalIncrementDirection();

  if (this->shouldIncrementErrorAxis())
    errorAxis += errorAxisDirection;

  this->updateError();
}

bool Geometry::LinePlotter::shouldIncrementErrorAxis()
{
  return this->error > 0;
}

void Geometry::LinePlotter::updateError()
{
  auto errorChange = this->errorAxes.rise();

  if (this->shouldIncrementErrorAxis())
    errorChange -= this->errorAxes.run();

  this->error += 2 * errorChange;  
}