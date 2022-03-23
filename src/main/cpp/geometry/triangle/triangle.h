#pragma once

#include <string>
#include <utility>
#include <vector>
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/line/line.h"
#include "src/main/cpp/geometry/triangle/edge.h"

namespace Geometry {
class Triangle
{
public:
  Triangle();
  Triangle(const std::vector<Maths::Vector>& vertices);
  Triangle(std::initializer_list<Maths::Vector> vertices);
  
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

  Geometry::Edge edge(std::string point1, std::string point2);
  std::vector<Geometry::Edge> edges();

  Maths::Vector smallestXVertex();
  Maths::Vector middleVertex();
  Maths::Vector greatestXVertex();
  Maths::Vector interceptOfMiddleVertex();
  void sortByX();
  Geometry::Triangle sortedByX();
  
  bool shouldSplit();
  bool hasFlatHorizontalEdge();
  bool hasFlatHorizontalEastEdge();
  bool hasFlatHorizontalWestEdge();

private:
  std::vector<Maths::Vector> vertices;

  double xLowerBound() const;
  double xUpperBound() const;
  bool verticesMatchX(std::string vertex1, std::string vertex2);
};}