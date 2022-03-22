#pragma once

#include <string>
#include <utility>
#include <vector>
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/cartesian-index/cartesian_index.h"

namespace Geometry {
class Triangle
{
public:
  Triangle();
  Triangle(const std::vector<Maths::Vector>& vertices);
  Triangle(Maths::Vector vertices...);
  
  void translate(const Maths::Vector& translation);
  void scale(double scalar, int pointOfOrigin);
  void scale(double scalar);
  std::pair<Geometry::Triangle, Geometry::Triangle> split();
  double operator [](std::string vertex) const; 
  double& operator [](std::string vertex);
  Maths::Vector operator [](int index) const; 
  Maths::Vector& operator [](int index); 
  std::vector<Maths::Vector>::iterator begin();
  std::vector<Maths::Vector>::iterator end();
  std::vector<Maths::Vector>::const_iterator begin() const;
  std::vector<Maths::Vector>::const_iterator end() const;
  Maths::Vector middleVertex();
  Maths::Vector interceptOfMiddleVertex();
  std::vector<Maths::Vector> sortedByX();
  bool shouldSplit();
  Geometry::Slope slope(Geometry::CartesianIndex point);

private:
  std::vector<Maths::Vector> vertices;

  double xLowerBound() const;
  double xUpperBound() const;
};}