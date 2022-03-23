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

Geometry::Triangle::Triangle(std::initializer_list<Maths::Vector> vertices)
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

void Geometry::Triangle::sortByX()
{
  auto isLessThan = [](
    Maths::Vector vector1, Maths::Vector vector2) {
      return (vector1["x"] < vector2["x"]);
  };

  std::sort(this->vertices.begin(), this->vertices.end(), isLessThan);
}

Geometry::Triangle Geometry::Triangle::sortedByX()
{
  auto isLessThan = [](
    Maths::Vector vector1, Maths::Vector vector2) {
      return (vector1["x"] < vector2["x"]);
  };

  auto sortedVertices = this->vertices;
  std::sort(sortedVertices.begin(), sortedVertices.end(), isLessThan);

  return sortedVertices;
}

Maths::Vector Geometry::Triangle::interceptOfMiddleVertex()
{
  auto sortedTriangle = this->sortedByX();
  
  auto slopeOfInterceptedLine = (
    (sortedTriangle["y3"]-sortedTriangle["y1"]) / (
      sortedTriangle["x3"]-sortedTriangle["x1"])
  );

  Maths::Vector interceptPoint = {
    sortedTriangle["x2"],
    sortedTriangle["y1"]
    + slopeOfInterceptedLine * (sortedTriangle["x2"] - sortedTriangle["x1"])
  };

  return interceptPoint;
}

bool Geometry::Triangle::shouldSplit()
{
  auto sortedTriangle = this->sortedByX();

  return (
    sortedTriangle["x1"] != sortedTriangle["x2"]
    && sortedTriangle["x2"] != sortedTriangle["x3"]
  );
}

Maths::Vector Geometry::Triangle::middleVertex()
{
  return this->sortedByX()[1];
}

Maths::Vector Geometry::Triangle::smallestXVertex()
{
  return this->sortedByX()[0];
}

Maths::Vector Geometry::Triangle::greatestXVertex()
{
  return this->sortedByX()[2];
}

std::vector<Geometry::Edge> Geometry::Triangle::edges()
{
  auto sortedTriangle = this->sortedByX();

  auto point1 = sortedTriangle[0];
  auto point2 = sortedTriangle[1];
  auto point3 = sortedTriangle[2];
  
  Geometry::Edge edge1To2 {point1, point2};
  Geometry::Edge edge1To3 {point1, point3};
  Geometry::Edge edge2To3 {point2, point3};

  std::cout << point3;

  return {edge1To2, edge1To3, edge2To3};
}

Geometry::Edge Geometry::Triangle::edge(std::string point1, std::string point2)
{
  auto sortedTriangle = this->sortedByX();

  std::string point1IndexString = {point1[1]};
  int point1index = std::stoi(point1IndexString);
  auto point1Vector = sortedTriangle[point1index];

  std::string point2IndexString = {point2[1]};
  int point2index = std::stoi(point2IndexString);
  auto point2Vector = sortedTriangle[point2index];

  return {point1Vector, point2Vector};
}

bool Geometry::Triangle::hasFlatHorizontalEastEdge()
{
  return this->verticesMatchX("x2", "x3");
}

bool Geometry::Triangle::hasFlatHorizontalWestEdge()
{
  return this->verticesMatchX("x1", "x2");
}

bool Geometry::Triangle::hasFlatHorizontalEdge()
{
  return (
    this->hasFlatHorizontalEastEdge() || this->hasFlatHorizontalWestEdge());
}

bool Geometry::Triangle::verticesMatchX(
  std::string vertex1, std::string vertex2)
{
  auto sortedTriangle = this->sortedByX();

  return sortedTriangle[vertex1] == sortedTriangle[vertex2]; 
}