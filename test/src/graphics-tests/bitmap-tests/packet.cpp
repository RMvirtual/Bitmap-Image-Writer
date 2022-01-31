#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(PixelArray, ShouldCreatePixelArray)
{
  Bitmaps::Format format;
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "green", "blue"});
  format.setWidthInPixels(4);
  format.setHeightInPixels(1);

  Bitmaps::PixelArray pixelArray {format};
  Bitmaps::Colours correctColours {format.colourNames()};

  for (int pixelNo = 0; pixelNo < 4; pixelNo++)
    BitmapImageComparison::compare(correctColours, pixelArray.at(pixelNo));
}

TEST(PixelArray, ShouldSetPixelInPixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();
  auto greenColours = BitmapSetUp::greenColours();
  pixelArray.set(greenColours, 1, 0);

  BitmapImageComparison::compare(greenColours, pixelArray.at(1, 0));
}

TEST(PixelArray, ShouldGetNumberOfPixelsInPixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();

  int correctNumberOfPixels = 4;
  int actualNumberOfPixels = pixelArray.sizeInPixels();

  EXPECT_EQ(correctNumberOfPixels, actualNumberOfPixels);
}