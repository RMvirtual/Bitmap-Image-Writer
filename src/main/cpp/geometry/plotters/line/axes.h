#pragma once

#include <string>
#include "src/main/cpp/geometry/line/line.h"

namespace Geometry {
class Axes
{
public:
  Axes();
  Axes(Geometry::Line line);

  void determineAxes(Geometry::Line line);

  std::string xAxis();
  std::string yAxis();
  double yChangeAmount();
  double run();
  double rise();

private:
  std::string _xAxis;
  std::string _yAxis;
  double _yChangeAmount;
  double _run;
  double _rise;

  void setNormalAxes(Geometry::Line line);
  void setTiltedAxes(Geometry::Line line);
  void determineYAxisChange();
};}