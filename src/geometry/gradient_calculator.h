#pragma once

#include <utility>

namespace Geometry {
class GradientCalculator
{
public:
  GradientCalculator();
  
  float gradient(
    std::pair<double,double> origin, std::pair<double,double> destination);

  float fromOriginZero(double x, double y);
};}