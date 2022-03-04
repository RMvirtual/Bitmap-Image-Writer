#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/rasterisation/plotters/line/axes.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<Maths::Vector> plot(Line line);

private:
  std::vector<Maths::Vector> plotPoints;
  Geometry::SlopedAxes slopedAxes;
  
  double yError;

  void initialise(Geometry::Line line);
  void plotSlopedLine(Geometry::Line line);
  void plotSlopelessLine(Geometry::Line line);
  void addPoint(double x, double&y);
  void addPointWithYError(double x, double&y);
  void initialiseYError();
  void updateY(double& y);
  void updateYError();
  bool shouldIncrementY();

  double lowerBound(double value1, double value2);
  double upperBound(double value1, double value2);

};}