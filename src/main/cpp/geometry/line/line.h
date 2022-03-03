#pragma once

#include <string>
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Line
{
public:
  Line();
  Line(Maths::Vector origin, Maths::Vector destination);
  Line(Maths::Vector destination);

  void setOrigin(Maths::Vector coordinates);
  void setDestination(Maths::Vector coordinates);
  void setEndpoints(Maths::Vector origin, Maths::Vector destination);
  void reverseEndpoints();

  Maths::Vector origin();
  Maths::Vector destination();
  double operator [](std::string vertex);

  double gradient();
  double rise();
  double run();
  bool isHorizontallySloped();
  bool isVerticallySloped();
  bool isSloped();
  bool isTraversingNorth();
  bool isTraversingEast();
  bool isTraversingWest();
  bool isTraversingSouth();

  void normaliseEndpoints();
  bool hasReversedEndpoints();
  bool hasHorizontallyReversedEndpoints();
  bool hasVerticallyReversedEndpoints();

private:
  Maths::Vector _origin;
  Maths::Vector _destination;
};}