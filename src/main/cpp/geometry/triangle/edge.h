#pragma once

#include "src/main/cpp/geometry/slope/slope.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Edge
{
public:
  Edge(const Maths::Vector& origin, const Maths::Vector& destination);

  Geometry::Slope slope() const;
  Maths::Vector operator [](int index) const;
  double operator [](std::string index) const;

  double xLowerBound() const;
  double xUpperBound() const;
  double yLowerBound() const;
  double yUpperBound() const;

private:
  Geometry::Slope _slope;
  Maths::Vector _origin;
  Maths::Vector _destination;
};}