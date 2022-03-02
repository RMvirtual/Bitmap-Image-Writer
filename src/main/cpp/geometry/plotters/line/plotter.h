#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/plotters/line/axes.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<Maths::Vector> plot(Line line);

private:
  std::vector<Maths::Vector> plotPoints;
  Geometry::Axes axes;

  void createPlotPoints(Geometry::Line line);
};}