#pragma once

#include <vector>
#include "src/main/cpp/maths/vector/vector.h"

namespace Geometry {
class Triangle
{
public:
  Triangle();
  Triangle(std::vector<Maths::Vector> vertices);
  
  void translate(Maths::Vector translation);
  Maths::Vector& operator [](int index); 
  std::vector<Maths::Vector>::iterator begin();
  std::vector<Maths::Vector>::iterator end();
  std::vector<Maths::Vector>::const_iterator begin() const;
  std::vector<Maths::Vector>::const_iterator end() const;
  
private:
  std::vector<Maths::Vector> vertices;
  
};}