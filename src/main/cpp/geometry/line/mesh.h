#pragma once

#include <vector>
#include "src/main/cpp/geometry/line/line.h"

namespace Geometry {
class LineMesh
{
public:
  LineMesh();
  LineMesh(const std::vector<Geometry::Line>& lines);
  Geometry::Line& operator [](int index); 

  std::vector<Geometry::Line>::iterator begin();
  std::vector<Geometry::Line>::iterator end();
  std::vector<Geometry::Line>::const_iterator begin() const;
  std::vector<Geometry::Line>::const_iterator end() const;

  int size();
  void add(const Geometry::Line& line);
  Maths::Vector origin();
  void translateToZeroOrigin();
  void scale(double scaleFactor, const Maths::Vector& origin);
  void scale(double scaleFactor);
  void translate(const Maths::Vector& translation);
  double xLowerBound();
  double xUpperBound();
  double yLowerBound();
  double yUpperBound();

private:
  std::vector<Geometry::Line> lines;
  double xOrigin;
  double yOrigin;

  void calculateOrigin();
};}