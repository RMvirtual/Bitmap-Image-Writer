#pragma once

#include <utility>
#include <vector>

#include "src/main/cpp/geometry/line/line.h"

namespace Geometry {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<std::pair<int,int>> plot(Line line);

private:
  std::vector<std::pair<int,int>> plotHigh(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> plotLow(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> horizontalPlot(Line line);
  std::vector<std::pair<int,int>> verticalPlot(Line line);


};}