#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Rasterisation {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<Maths::Vector> plot(const Geometry::Line& line);

private:
  std::vector<Maths::Vector> plotPoints;
  
  double errorTracker;
  double errorIncrementDirection;
  double errorRise;
  double errorRun;

  void initialiseErrorIncrementDirection();

  void plotSlopedLine(const Geometry::Line& line);
  void plotSlopelessLine(const Geometry::Line& line);
  void addPointWithYError(double x, double& y);
  void initialiseErrorTracker();
  void updateErrorAxis(double& y);
  void updateError();
  bool shouldIncrementErrorAxis();  
};}