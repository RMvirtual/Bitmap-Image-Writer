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
  this->rasteriser.setWritableImage(image);

  EXPECT_TRUE(false);
}