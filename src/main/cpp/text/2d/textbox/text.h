#pragma once

#include <string>
#include "src/main/cpp/text/2d/textbox/padding.h"
#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/geometry/line/mesh.h"
#include "src/main/cpp/text/2d/letter/letter.h"

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

  Text::Letter operator [](int index);

  std::vector<Text::Letter>::iterator begin();
  std::vector<Text::Letter>::iterator end();
  std::vector<Text::Letter>::const_iterator begin() const;
  std::vector<Text::Letter>::const_iterator end() const;

  std::string text();

private:
  std::vector<Text::Letter> letters;
  std::string _text;
  Text::Padding _padding;
  Maths::Vector origin;

  void renderLetters();
  void loadBaseLetters();
  void addPadding();
  void removePadding();
  void recalculatePadding(double scaleFactor);
};}