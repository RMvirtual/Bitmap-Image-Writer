#pragma once

#include <utility>
#include <vector>
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/line/line.h"

namespace Geometry {
class Triangle
{
public:
  Triangle();
  Triangle(const std::vector<Maths::Vector>& vertices);
  
  void translate(const Maths::Vector& translation);
  void scale(double scalar, int pointOfOrigin);
  void scale(double scalar);
  std::pair<Geometry::Triangle, Geometry::Triangle> split();
  Maths::Vector operator [](int index) const; 
  Maths::Vector& operator [](int index); 
  std::vector<Maths::Vector>::iterator begin();
  std::vector<Maths::Vector>::iterator end();
  std::vector<Maths::Vector>::const_iterator begin() const;
  std::vector<Maths::Vector>::const_iterator end() const;
  

  
private:
  std::vector<Maths::Vector> vertices;
};}