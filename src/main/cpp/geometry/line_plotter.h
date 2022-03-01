#pragma once

#include <vector>
#include <utility>

namespace Geometry {
class LinePlotter
{
public:
  LinePlotter();

  std::vector<std::pair<int,int>> plotPoints(
    std::pair<double,double> destination);

  std::vector<std::pair<int,int>> plotPoints(
    std::pair<double,double> origin, std::pair<double,double> destination);

private:
  std::vector<std::pair<int,int>> plotLineHigh(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> plotLineLow(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> horizontalLinePlot(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::vector<std::pair<int,int>> verticalLinePlot(
    std::pair<double,double> origin, std::pair<double,double> destination);


};}