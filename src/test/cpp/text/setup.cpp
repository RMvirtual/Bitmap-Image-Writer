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
  // X max = 2
  Geometry::LineMesh letterH = {{
    {{0.0,0.0}, {0.0, 3}},
    {{0.0,3}, {0.0, 2}},
    {{0.0,2}, {2, 2}},
    {{2,2}, {2, 0.0}},
    {{2,0.0}, {2, 3}}
  }};

  // x max = 2
  Geometry::LineMesh letterA = {{
    {{0.0,0.0}, {1, 2}},
    {{1,2}, {2, 0.0}},
    {{2,0.0}, {0.5, 1}},
    {{0.5,1}, {1.5, 1}},
  }};

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