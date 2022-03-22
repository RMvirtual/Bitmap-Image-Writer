#pragma once

#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Slope
{
public:
  Slope();
  Slope(const Maths::Vector& origin, const Maths::Vector& destination);
  Slope(const Maths::Vector& destination);
  
  double gradient() const;
  double rise() const;
  double run() const;

  bool isSloped() const;
  bool isSlopeless() const;
  bool isHorizontallySloped() const;
  bool isVerticallySloped() const;
  bool isHorizontallyStraight() const;
  bool isVerticallyStraight() const;
  bool isTraversingNorth() const;
  bool isTraversingEast() const;
  bool isTraversingWest() const;
  bool isTraversingSouth() const;
  bool isDescendingByX() const;
  bool isDescendingByY() const;

  double xLowerBound() const;
  double xUpperBound() const;
  double yLowerBound() const;
  double yUpperBound() const;

private:
  Maths::Vector _origin;
  Maths::Vector _destination;
};}