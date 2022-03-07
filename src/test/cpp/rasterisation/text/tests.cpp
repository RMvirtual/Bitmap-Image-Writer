#include <memory>

#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/text/fixture.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"
#include "src/main/cpp/rasterisation/text/alphabet.h"

TEST_F(TextRasterisationTest, ShouldDrawAlphabet)
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

  auto letterH = Rasterisation::letter("h");
  letterH.scale(10);
  letterH.translate({100,100});

  this->rasteriser.setWritableImage(image);
  this->rasteriser.draw(letterH);

  Bitmaps::ImageWriter writer;
  
  writer.writeToFile(
    *image,
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp"
  );
}