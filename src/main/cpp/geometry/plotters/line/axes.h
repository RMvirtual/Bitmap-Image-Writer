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

  std::string horizontalAxis();
  std::string verticalAxis();
  double verticalChangeAmount();
  double run();
  double rise();
  std::string operator [](std::string vertex);

private:
  std::string _horizontalAxis;
  std::string _verticalAxis;
  double _verticalChangeAmount;
  double _run;
  double _rise;

  void setNormalAxes(Geometry::Line line);
  void setTiltedAxes(Geometry::Line line);
  void determineVerticalAxisChange();
};}