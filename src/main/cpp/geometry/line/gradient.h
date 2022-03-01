#pragma once

#include <utility>

namespace Geometry {
class Gradient
{
public:
  Gradient();
  
  Gradient(
    std::pair<double,double> origin, std::pair<double,double> destination);
  
  static Gradient fromOriginZero(double x, double y);

  double gradient();
  double rise();
  double run();
  bool isHorizontallySloped();
  bool isTraversingUpwards();
  bool isTraversingLeftToRight();

private:
  std::pair<double,double> origin;
  std::pair<double,double> destination;

};}