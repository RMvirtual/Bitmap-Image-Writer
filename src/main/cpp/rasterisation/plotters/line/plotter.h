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
  Geometry::ErrorAxes errorAxes;
  
  double error;

  void initialise(Geometry::Line& line);
  void plotSlopedLine(Geometry::Line& line);
  void plotSlopelessLine(Geometry::Line& line);
  void addPointWithYError(double x, double&y);
  void initialiseErrorAxis();
  void updateErrorAxis(double& y);
  void updateError();
  bool shouldIncrementErrorAxis();  
};}