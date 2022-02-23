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
  
  
};}