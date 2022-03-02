#include <cmath>

#include "src/main/cpp/geometry/line_plotter.h"

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
  this->determineAxes(line);
  double D = (2 * axes.rise) - axes.run;

  auto x0 = line.origin()[axes.xAxis];
  auto x1 = line.destination()[axes.xAxis];
  auto y = line.origin()[axes.yAxis];

  for (auto x = x0; x <= x1; x++) {
    this->plotPoints.push_back({x, y});

    if (D > 0) {
      y += axes.yChangeAmount;
      D += 2 * (axes.rise - axes.run);
    }

    else 
      D += 2 * axes.rise;
  }
}

void Geometry::LinePlotter::determineAxes(Geometry::Line line)
{  
  bool shouldTiltAxis = line.isVerticallySloped();

  if (shouldTiltAxis)
    this->setTiltedAxes(line);

  else
    this->setNormalAxes(line);

  this->determineYChangeAmount();
}

void Geometry::LinePlotter::setNormalAxes(Geometry::Line line)
{
  this->axes.xAxis = "x";
  this->axes.yAxis = "y";
  this->axes.run = line.run();
  this->axes.rise = line.rise();
}

void Geometry::LinePlotter::setTiltedAxes(Geometry::Line line)
{
  this->axes.xAxis = "y";
  this->axes.yAxis = "x";
  this->axes.run = line.rise();
  this->axes.rise = line.run();
}

void Geometry::LinePlotter::determineYChangeAmount()
{
  this->axes.yChangeAmount = 1;

  if (this->axes.rise < 0) {
    this->axes.yChangeAmount = -1;
    this->axes.rise = 0 - axes.rise;
  }
}