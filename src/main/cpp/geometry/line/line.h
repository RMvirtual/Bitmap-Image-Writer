#pragma once

#include <string>
#include <unordered_map>

#include "src/main/cpp/geometry/slope/slope.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Line
{
public:
  Line();
  Line(const Maths::Vector& origin, const Maths::Vector& destination);
  Line(const Maths::Vector& destination);

  void setOrigin(const Maths::Vector& coordinates);
  void setDestination(const Maths::Vector& coordinates);
  void setEndpoints(
    const Maths::Vector& origin, const Maths::Vector& destination);
  
  void switchEndpoints();
  void sortByXAscending();
  void sortByYAscending();
  void translate(const Maths::Vector& translate);
  void scale(double scaleFactor, const Maths::Vector& origin);
  void scale(double scaleFactor);
  void scaleIncludingOrigin(double scaleFactor);
  void calculateVertices();

  Maths::Vector origin() const;
  Maths::Vector destination() const;

  double& operator [](const std::string& vertex);
  double operator [](const std::string& vertex) const;

  double gradient() const;
  double rise() const;
  double run() const;

  bool isSloped() const;
  bool isSlopeless() const;
  bool isHorizontallySloped() const;
  bool isVerticallySloped() const;
  bool isHorizontalLine() const;
  bool isVerticalLine() const;
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
  Geometry::Slope slope;
  std::unordered_map<std::string, double> vertices;

  void recalculateSlope();
};}