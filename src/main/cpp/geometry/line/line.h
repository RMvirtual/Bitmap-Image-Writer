#pragma once

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

  Maths::Vector origin();
  Maths::Vector destination();
  Line reverse();

  double gradient();
  double rise();
  double run();
  bool isHorizontallySloped();
  bool isTraversingNorth();
  bool isTraversingEast();
  bool isTraversingWest();
  bool isTraversingSouth();

private:
  Maths::Vector _origin;
  Maths::Vector _destination;
};}