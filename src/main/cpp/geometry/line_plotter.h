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
  std::vector<std::pair<int,int>> plotLineHigh(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> plotLineLow(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> horizontalLinePlot(Line line);
  std::vector<std::pair<int,int>> verticalLinePlot(Line line);


};}