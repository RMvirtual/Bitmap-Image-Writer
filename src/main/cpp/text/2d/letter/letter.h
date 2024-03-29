#pragma once

#include <string>
#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Text {
class Letter
{
public:
  Letter(const std::string& letter);
  Letter(char letter);
  
  void scale(double scaleFactor);
  void scale(double scaleFactor, const Maths::Vector& origin);
  void scaleIncludingOrigin(double scaleFactor);
  void translate(const Maths::Vector& translation);

  double xUpperBound();
  double xLowerBound();
  double yUpperBound();
  double yLowerBound();
  int noOfLines();

  Geometry::Line& operator [](int index);
  std::vector<Geometry::Line>::iterator begin();
  std::vector<Geometry::Line>::iterator end();
  std::vector<Geometry::Line>::const_iterator begin() const;
  std::vector<Geometry::Line>::const_iterator end() const;

private:
  Geometry::LineMesh templateMesh;
  Geometry::LineMesh transformedMesh;

  void loadLetterFromFile(const std::string& letter);
};}