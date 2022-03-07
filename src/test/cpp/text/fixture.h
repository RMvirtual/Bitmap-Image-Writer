#pragma once

#include <memory>

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

class TextTest : public testing::Test
{
public:
  TextTest();
  ~TextTest();

protected:
  Rasterisation::Rasteriser rasteriser;
  std::vector<Geometry::LineMesh> correctLineMeshes;

  std::shared_ptr<Bitmaps::Image> redImage();
  void setupCorrectUnpaddedText();
  void compare(Text::Text2D text);
  void compare(Geometry::LineMesh correctMesh, Geometry::LineMesh mesh);
  void compare(Geometry::Line correctLine, Geometry::Line line);
};