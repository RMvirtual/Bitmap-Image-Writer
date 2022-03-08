#pragma once

#include <string>
#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/maths/vector/vector.h"

namespace Text {
class Letter
{
public:
  Letter(std::string letter);
  Letter(char letter);

  void scale(double scaleFactor);
  void translate(Maths::Vector translation);

  double xUpperBound();
  double xLowerBound();
  double yUpperBound();
  double yLowerBound();
  
  Geometry::Line& operator [](int index);
  std::vector<Geometry::Line>::iterator begin();
  std::vector<Geometry::Line>::iterator end();
  std::vector<Geometry::Line>::const_iterator begin() const;
  std::vector<Geometry::Line>::const_iterator end() const;

private:
  Geometry::LineMesh templateMesh;
  Geometry::LineMesh transformedMesh;
  double scaleFactor;
  Maths::Vector translationFromOrigin;

  void loadLetterFromFile(std::string letter);
  void transformMesh();
};}