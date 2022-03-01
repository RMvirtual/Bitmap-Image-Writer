#pragma once

#include <utility>
#include "src/main/cpp/geometry/line/gradient.h"

namespace Geometry {
class Line
{
public:
  Line();
  Line(std::pair<double,double> origin, std::pair<double,double> destination);
  Line(std::pair<double,double> destination);

  Gradient gradient();
  void setOrigin(std::pair<double,double> coordinates);
  void setDestination(std::pair<double,double> coordinates);
  
  void setEndpoints(
    std::pair<double,double> origin, std::pair<double,double> destination);

  std::pair<double,double> origin();
  std::pair<double,double> destination();

private:
  std::pair<double,double> _origin;
  std::pair<double,double> _destination;
  Gradient _gradient;

  void updateGradient();
};}