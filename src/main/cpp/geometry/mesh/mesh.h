#pragma once

#include <vector>
#include "src/main/cpp/geometry/triangle/triangle.h"

namespace Geometry {
class Mesh
{
public:
  Mesh(std::vector<Geometry::Triangle> triangles);
  Geometry::Triangle& operator [](int index); 

  std::vector<Geometry::Triangle>::iterator begin();
  std::vector<Geometry::Triangle>::iterator end();
  std::vector<Geometry::Triangle>::const_iterator begin() const;
  std::vector<Geometry::Triangle>::const_iterator end() const;

private:
  std::vector<Geometry::Triangle> triangles;  
};}