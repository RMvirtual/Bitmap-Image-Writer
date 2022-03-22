#include <algorithm>

#include "src/main/cpp/geometry/triangle/triangle.h"
#include "src/main/cpp/geometry/triangle/splitter.h"

#include <iostream>

Geometry::Triangle::Triangle()
{
  this->vertices = {{0.0, 0.0}, {1, 2}, {2, 0.0}};
}

Geometry::Triangle::Triangle(const std::vector<Maths::Vector>& vertices)
{
  this->vertices = vertices;
}

Geometry::Triangle::Triangle(Maths::Vector vertices...)
{
  this->vertices = {vertices};
}

double Geometry::Triangle::operator [](std::string vertex) const
{
  std::string indexString = {vertex[1]};
  int index = std::stoi(indexString);
  std::string coordinate {vertex[0]};

  return this->vertices[index][coordinate];
}

/**
 * @brief Index from x1-x3, y1-y3.
 * 
 * @param vertex 
 * @return double& 
 */
double& Geometry::Triangle::operator [](std::string vertex)
{
  std::string indexString = {vertex[1]};
  int index = std::stoi(indexString) - 1;
  std::string coordinate {vertex[0]};

  return this->vertices[index][coordinate];
}

Maths::Vector Geometry::Triangle::operator [](int index) const
{
  return this->vertices[index];
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

void Geometry::Triangle::translate(const Maths::Vector& translation)
{
  for (auto& vertex: this->vertices)
    vertex = vertex + translation;
}

void Geometry::Triangle::scale(double scalar, int originVertexIndex)
{
  auto origin = this->vertices[originVertexIndex];
  Maths::Vector zeroOrigin = {0.0, 0.0};

  this->translate(zeroOrigin - origin);

  for (int i = 0; i < 3; i++) {
    auto& vertex = this->vertices[i];
    this->vertices[i] = scalar * vertex;
  }

  this->translate(origin);
}

void Geometry::Triangle::scale(double scalar)
{
  this->scale(scalar, 0);
}

std::pair<Geometry::Triangle, Geometry::Triangle> Geometry::Triangle::split()
{
  Geometry::TriangleSplitter splitter;

  return splitter.split(*this);
}

double Geometry::Triangle::xLowerBound() const
{
  double bound = this->vertices[0]["x"];

  for (auto& vertex : this->vertices)
    bound = std::min(bound, vertex["x"]);

  return bound;
}

double Geometry::Triangle::xUpperBound() const
{
  double bound = this->vertices[0]["x"];

  for (auto& vertex : this->vertices)
    bound = std::max(bound, vertex["x"]);

  return bound;
}

std::vector<Maths::Vector> Geometry::Triangle::sortedByX()
{
  auto isLessThan = [](
    Maths::Vector vector1, Maths::Vector vector2) {
      return (vector1["x"] < vector2["x"]);
  };

  auto sortedVertices = this->vertices;
  std::sort(this->vertices.begin(), this->vertices.end(), isLessThan);

  return sortedVertices;
}

Maths::Vector Geometry::Triangle::interceptOfMiddleVertex()
{
  Geometry::Triangle sortedVertices = {this->sortedByX()};
  
  auto slopeOfInterceptedLine = (
    (sortedVertices["y3"]-sortedVertices["y1"]) / (
      sortedVertices["x3"]-sortedVertices["x1"])
  );

  Maths::Vector interceptPoint = {
    sortedVertices["x2"],
    sortedVertices["y1"]
    + slopeOfInterceptedLine * (sortedVertices["x2"] - sortedVertices["x1"])
  };

  return interceptPoint;
}

bool Geometry::Triangle::shouldSplit()
{
  Geometry::Triangle sortedTriangle = {this->sortedByX()};

  return (
    sortedTriangle["x1"] != sortedTriangle["x2"]
    && sortedTriangle["x2"] != sortedTriangle["x3"]
  );
}

Maths::Vector Geometry::Triangle::middleVertex()
{
  return this->sortedByX()[1];
}