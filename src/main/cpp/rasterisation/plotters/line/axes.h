#pragma once

#include <string>
#include "src/main/cpp/geometry/line/line.h"

namespace Geometry {
class SlopedAxes
{
public:
  SlopedAxes();
  SlopedAxes(Geometry::Line line);

  void determineAxes(Geometry::Line line);
  void setNormalAxes(Geometry::Line line);
  void tiltAxes(Geometry::Line line);

  std::string horizontalAxis();
  std::string verticalAxis();
  double verticalIncrementDirection();
  double run();
  double rise();
  std::string operator [](std::string vertex);

private:
  std::string _horizontalAxis;
  std::string _verticalAxis;
  double _verticalChangeAmount;
  double _run;
  double _rise;

  void determineVerticalAxisDirection();
};}