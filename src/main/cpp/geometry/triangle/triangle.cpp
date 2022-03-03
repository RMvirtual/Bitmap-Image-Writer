#include "src/main/cpp/geometry/triangle/triangle.h"

Geometry::Triangle::Triangle()
{
  this->vertices = {
    {0.0, 0.0},
    {1, 2},
    {2, 0.0}
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

std::vector<Geometry::Line> Geometry::Triangle::toLines()
{
  std::vector<Geometry::Line> lines {};

  int noOfVertices = this->vertices.size();

  for (int i = 0; i < noOfVertices - 1; i++) {
    auto vertex1 = this->vertices[i];
    auto vertex2 = this->vertices[i+1];

    lines.push_back({{vertex1}, {vertex2}});
  }

  auto originVertex = this->vertices[0];
  auto lastVertex = this->vertices[noOfVertices-1];

  lines.push_back({{lastVertex}, {originVertex}});

  return lines;
}

void Geometry::Triangle::scale(double scalar, int originVertexIndex)
{
  // Needs translating to origin 0,0 first for all triangles to work.

  for (int i = 0; i < 3; i++) {
    auto vertex = this->vertices[i];
    this->vertices[i] = scalar * vertex;
  }
}

void Geometry::Triangle::scale(double scalar)
{
  this->scale(scalar, 0);
}