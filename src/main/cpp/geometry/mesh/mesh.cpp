#include "src/main/cpp/geometry/mesh/mesh.h"
#include "src/main/cpp/geometry/triangle/triangle.h"

Geometry::Mesh::Mesh(std::vector<Geometry::Triangle> triangles)
{
  this->triangles = triangles;
}

Geometry::Triangle& Geometry::Mesh::operator [](int index)
{
  return this->triangles[index];
}

std::vector<Geometry::Triangle>::iterator Geometry::Mesh::begin()
{
  return this->triangles.begin();
}

std::vector<Geometry::Triangle>::iterator Geometry::Mesh::end()
{
  return this->triangles.end();
}

std::vector<Geometry::Triangle>::const_iterator Geometry::Mesh::begin() const
{
  return this->triangles.begin();
}

std::vector<Geometry::Triangle>::const_iterator Geometry::Mesh::end() const
{
return this->triangles.end();
}

