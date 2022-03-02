#pragma once

#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Gradient
{
public:
  Gradient();
  
  Gradient(Maths::Vector origin, Maths::Vector destination);
  static Gradient fromOriginZero(Maths::Vector destination);

  double gradient();
  double rise();
  double run();
  bool isHorizontallySloped();
  bool isTraversingUpwards();
  bool isTraversingLeftToRight();

private:
  Maths::Vector origin;
  Maths::Vector destination;
};}