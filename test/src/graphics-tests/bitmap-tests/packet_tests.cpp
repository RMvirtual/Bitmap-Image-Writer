#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/size-calculator/pixel_array_size_calculator.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb_colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"

TEST(PixelArrayTests, ShouldCreateRGBTemplatePixelArray)
{
  Pixels::PixelArrayValues<Pixels::Pixel<Pixels::RGBColours>> values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {BitmapSetUp::redColours()};

  Pixels::PixelArray<Pixels::Pixel<Pixels::RGBColours>> pixelArray {values};
  
  for (int pixelNo = 0; pixelNo < 4; pixelNo++)
    BitmapImageComparison::comparePixels(
      pixelArray.at(pixelNo), values.defaultPixel);
}

TEST(PixelArrayTests, ShouldSetPixelInRGBTemplatePixelArray)
{
  auto pixelArray = BitmapSetUp::redPixelArray();
  auto greenPixel = BitmapSetUp::greenRGBPixel();  
  pixelArray.set(greenPixel, 1, 0);

  BitmapImageComparison::comparePixels(greenPixel, pixelArray.at(1, 0));
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