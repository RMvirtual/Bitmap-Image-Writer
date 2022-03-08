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
  void switchEndpoints();
  void sortByXAscending();
  void sortByYAscending();
  void translate(Maths::Vector translate);
  void scale(double scaleFactor);
  void scaleIncludingOrigin(double scaleFactor);

  Maths::Vector origin();
  Maths::Vector destination();
  double operator [](std::string vertex);

  double gradient();
  double rise();
  double run();

  bool isSloped();
  bool isSlopeless(); 
  bool isHorizontallySloped();
  bool isVerticallySloped();
  bool isHorizontalLine();
  bool isVerticalLine();
  bool isTraversingNorth();
  bool isTraversingEast();
  bool isTraversingWest();
  bool isTraversingSouth();
  bool isDescendingByX();
  bool isDescendingByY();

  double xLowerBound();
  double xUpperBound();
  double yLowerBound();
  double yUpperBound();

private:
  Maths::Vector _origin;
  Maths::Vector _destination;
};}