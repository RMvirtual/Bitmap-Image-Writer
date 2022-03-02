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
  std::vector<Maths::Vector> horizontalPlot(Line line);
  std::vector<Maths::Vector> verticalPlot(Line line);

  std::vector<Maths::Vector> plotHigh(
    Maths::Vector origin, Maths::Vector destination);

  std::vector<Maths::Vector> plotLow(
    Maths::Vector origin, Maths::Vector destination);

};}