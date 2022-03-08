#pragma once

#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

class TextTest : public testing::Test
{
public:
  TextTest();
  ~TextTest();

protected:
  Rasterisation::Rasteriser rasteriser;

  std::shared_ptr<Bitmaps::Image> redImage();
  void compare(std::vector<Text::Letter> correctLetters, Text::Text2D text);
  void compare(Text::Letter correctLetter, Text::Letter letter);
  void compare(Geometry::Line correctLine, Geometry::Line line);
};