#pragma once

#include <string>
#include "src/main/cpp/text/2d/textbox/padding.h"
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/line/mesh.h"

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
  int size();

  Geometry::LineMesh operator [](int index);

  std::vector<Geometry::LineMesh>::iterator begin();
  std::vector<Geometry::LineMesh>::iterator end();
  std::vector<Geometry::LineMesh>::const_iterator begin() const;
  std::vector<Geometry::LineMesh>::const_iterator end() const;

  std::string text();
  Text::Padding padding();
  void renderLetters();
  void loadBaseLetters();

private:
  std::string _text;
  std::vector<Geometry::LineMesh> baseLetters;
  std::vector<Geometry::LineMesh> renderedLetters;
  Maths::Vector origin;

  Text::Padding _padding;
  double scaleFactor;  
};}