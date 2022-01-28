#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/size_calculator.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

TEST(PixelArrayTests, ShouldCreateRGBTemplatePixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();

  Pixels::Format format;
  format.name = "RGB";
  format.bitsPerPixel = 24;
  format.colourNames = {"red", "green", "blue"};

  Pixels::Colours correctColours {format.colourNames};

  for (int pixelNo = 0; pixelNo < 4; pixelNo++)
    BitmapImageComparison::compare(
      pixelArray.at(pixelNo), correctColours);
}

TEST(PixelArrayTests, ShouldSetPixelInRGBTemplatePixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();
  auto greenPixel = BitmapSetUp::greenColours();  
  pixelArray.set(greenPixel, 1, 0);

  BitmapImageComparison::compare(greenPixel, pixelArray.at(1, 0));
}

TEST(PixelArrayTests, ShouldGetNumberOfPixelsInPixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();

  int correctNumberOfPixels = 4;
  int actualNumberOfPixels = pixelArray.sizeInPixels();

  EXPECT_EQ(correctNumberOfPixels, actualNumberOfPixels);
}

TEST(PixelArrayTests, ShouldCalculatePixelArrayRowPadding)
{
  int correctPadding = 2;
  int actualPadding = Pixels::calculateRowPadding(6);

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST(PixelArrayTests, ShouldCalculatePixelArrayRowSizeInBytes)
{
  int correctSize = 20;
  int actualSize = Pixels::calculateRowSizeInBytes(6);
  
  EXPECT_EQ(correctSize, actualSize);
}