#pragma once

#include <utility>

namespace Geometry {
class GradientCalculator
{
public:
  GradientCalculator();
  
  double gradient(
    std::pair<double,double> origin, std::pair<double,double> destination);

  double fromOriginZero(double x, double y);

  double rise(
    std::pair<double,double> origin, std::pair<double,double> destination);

  double run(
    std::pair<double,double> origin, std::pair<double,double> destination);

  bool isHorizontallySloped(
    std::pair<double,double> origin, std::pair<double,double> destination);
};}