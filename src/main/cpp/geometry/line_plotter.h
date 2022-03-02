#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<Maths::Vector> plot(Line line);

private:
  struct Axes {
    std::string xAxis;
    std::string yAxis;
    double yChangeAmount;
    double run;
    double rise;
  };



  std::vector<Maths::Vector> plotPoints;
  Axes axes;

  void createPlotPoints(Geometry::Line line);
  void determineAxes(Geometry::Line line);
  void setNormalAxes(Geometry::Line line);
  void setTiltedAxes(Geometry::Line line);

};}