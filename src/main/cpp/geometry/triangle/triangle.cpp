#include "src/main/cpp/geometry/triangle/triangle.h"

Geometry::Triangle::Triangle()
{
  this->vertices = {
    {0.0, 0.0}, {1,1}, {2, 0.0},
  };
}

Geometry::Triangle::Triangle(std::vector<Maths::Vector> vertices)
{
  this->vertices = vertices;
}

Maths::Vector& Geometry::Triangle::operator [](int index)
{
  return this->vertices[index];
}

std::vector<Maths::Vector>::iterator Geometry::Triangle::begin()
{
  return this->vertices.begin();
}

std::vector<Maths::Vector>::iterator Geometry::Triangle::end()
{
  return this->vertices.end();
}

std::vector<Maths::Vector>::const_iterator Geometry::Triangle::begin() const
{
  return this->vertices.begin();
}

std::vector<Maths::Vector>::const_iterator Geometry::Triangle::end() const
{
  return this->vertices.end();
}

void Geometry::Triangle::translate(Maths::Vector translation)
{
  for (auto& vertex: this->vertices)
    vertex = vertex + translation;
}