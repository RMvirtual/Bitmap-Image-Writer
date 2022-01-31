#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/size_calculator.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(PixelArray, ShouldCreatePixelArray)
{
  Pixels::Format format;
  format.name = "RGB";
  format.bitsPerPixel = 24;
  format.colourNames = {"red", "green", "blue"};
  format.widthInPixels = 4;
  format.heightInPixels = 1;

  Pixels::Array pixelArray {format};
  Pixels::Colours correctColours {format.colourNames};

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

TEST(PixelArray, ShouldCalculatePixelArrayRowPadding)
{
  int correctPadding = 2;
  int actualPadding = Pixels::calculateRowPadding(6);

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST(PixelArray, ShouldCalculatePixelArrayRowSizeInBytes)
{
  int correctSize = 20;
  int actualSize = Pixels::calculateRowSizeInBytes(6);
  
  EXPECT_EQ(correctSize, actualSize);
}