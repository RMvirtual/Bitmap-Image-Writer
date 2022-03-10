#pragma once

#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"
#include "src/main/cpp/text/2d/letter/letter.h"
#include "src/main/cpp/text/2d/textbox/text.h"

class TextTest : public testing::Test
{
public:
  TextTest();
  ~TextTest();

protected:
  Text::Text2D text;
  std::vector<Text::Letter> correctLetters;

  void setupHahaText();
  std::shared_ptr<Bitmaps::Image> redImage();
  void compare(std::vector<Text::Letter> correctLetters, Text::Text2D text);
  void compare(Text::Letter correctLetter, Text::Letter letter);
  void compare(Geometry::Line correctLine, Geometry::Line line);
};