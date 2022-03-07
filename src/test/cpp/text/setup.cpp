#include "src/main/cpp/files/alphabet-2d/file.h"

#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/test/cpp/text/fixture.h"

std::shared_ptr<Bitmaps::Image> TextTest::redImage()
{
  auto format = Bitmaps::format("RGB24");
  format.setHeightInPixels(500);
  format.setWidthInPixels(500);

  auto redColours = format.colours();
  redColours["red"] = 255;
  redColours["green"] = 0;
  redColours["blue"] = 0;

  auto image = std::make_shared<Bitmaps::Image>(format);
  image->fill(redColours);

  return image;
}

void TextTest::setupCorrectUnpaddedText()
{
  Geometry::LineMesh letterH = Files::Alphabet2D::letter("h");
  Geometry::LineMesh letterA = Files::Alphabet2D::letter("a");

  Geometry::LineMesh letterH0 = letterH;
  Geometry::LineMesh letterA0 = letterA;
  Geometry::LineMesh letterH1 = letterH;
  Geometry::LineMesh letterA1 = letterA;

  letterA0.translate({2, 0.0});
  letterH1.translate({4, 0.0});
  letterA1.translate({6, 0.0});

  this->correctLineMeshes = {
    letterH0, letterA0, letterH1, letterA1
  };  
}

void TextTest::setupCorrectScaledUnpaddedText()
{
  // 2 x's each. Therefore 4x's when scaled.
  Geometry::LineMesh letterH = Files::Alphabet2D::letter("h");
  Geometry::LineMesh letterA = Files::Alphabet2D::letter("a");

  Geometry::LineMesh letterH0 = letterH;
  Geometry::LineMesh letterA0 = letterA;
  Geometry::LineMesh letterH1 = letterH;
  Geometry::LineMesh letterA1 = letterA;

  letterH0.scale(2);

  letterA0.translate({4, 0.0});
  letterA0.scale(2);

  letterH1.translate({8, 0.0});
  letterH1.scale(2);

  letterA1.translate({12, 0.0});
  letterA1.scale(2);

  this->correctLineMeshes = {
    letterH0, letterA0, letterH1, letterA1
  };
}