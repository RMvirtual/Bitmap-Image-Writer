#pragma once

#include <string>
#include "src/main/cpp/text/2d/padding.h"
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/mesh/line_mesh.h"

namespace Text {
class Text2D
{
public:
  Text2D();
  Text2D(std::string text);

  void setPadding(double x, double y);
  void setText(std::string text);
  void scale(double scaleFactor);
  void translate(Maths::Vector translation);

  Geometry::LineMesh operator [](int index);

  std::vector<Geometry::LineMesh>::iterator begin();
  std::vector<Geometry::LineMesh>::iterator end();
  std::vector<Geometry::LineMesh>::const_iterator begin() const;
  std::vector<Geometry::LineMesh>::const_iterator end() const;

  std::string text();
  Text::Padding padding();

private:
  std::string _text;
  std::vector<Geometry::LineMesh> letters;
  Text::Padding _padding;
};}