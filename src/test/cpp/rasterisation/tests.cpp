#include <memory>

#include "gtest/gtest.h"
#include "src/test/cpp/rasterisation/fixture.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"

TEST_F(RasterisationTest, ShouldDrawTriangle)
{
  Geometry::Triangle triangle;
  auto format = Bitmaps::format("RGB");
  format.setHeightInPixels(500);
  format.setWidthInPixels(500);

  auto image = std::make_shared<Bitmaps::Image>(format);
  
  auto redColours = format.colours();
  redColours["red"] = 255;
  redColours["green"] = 0;
  redColours["blue"] = 0;

  image->fill(redColours);
  this->rasteriser.setWritableImage(image);
  this->rasteriser.draw(triangle);

  EXPECT_TRUE(false);
}