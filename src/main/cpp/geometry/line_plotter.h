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
  std::vector<Maths::Vector> plotPoints;

  void horizontalPlot(Line line);
  void verticalPlot(Line line);
  void plotHigh(Maths::Vector origin, Maths::Vector destination);
  void plotLow(Maths::Vector origin, Maths::Vector destination);

};}