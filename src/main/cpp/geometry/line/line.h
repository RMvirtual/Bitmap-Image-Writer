#pragma once

#include <utility>
#include "src/main/cpp/geometry/line/gradient.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Line
{
public:
  Line();
  Line(Maths::Vector origin, Maths::Vector destination);
  Line(Maths::Vector destination);

  Gradient gradient();
  void setOrigin(Maths::Vector coordinates);
  void setDestination(Maths::Vector coordinates);  
  void setEndpoints(Maths::Vector origin, Maths::Vector destination);

  Maths::Vector origin();
  Maths::Vector destination();

private:
  Maths::Vector _origin;
  Maths::Vector _destination;
  Gradient _gradient;

  void updateGradient();
};}