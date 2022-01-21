#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/size-calculator/pixel_array_size_calculator.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

TEST(PixelArrayTests, ShouldCreateRGBPixelArray)
{
  Pixels::RGBPixelArrayValues values;

  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = BitmapSetUp::redColours();

  Pixels::PixelArray<> pixelArray {values};
  
  auto pixel1 = pixelArray.at(0);
  auto pixel2 = pixelArray.at(1);
  auto pixel3 = pixelArray.at(2);
  auto pixel4 = pixelArray.at(3);

  std::vector<Pixels::RGBPixel> pixelsToTest {
    pixel1, pixel2, pixel3, pixel4};

  for (auto pixel : pixelsToTest) {
    EXPECT_EQ(values.defaultPixel.colours().blue(), pixel.colours().blue());
    EXPECT_EQ(values.defaultPixel.colours().red(), pixel.colours().red());
    EXPECT_EQ(values.defaultPixel.colours().green(), pixel.colours().green());
  }
}

TEST(PixelArrayTests, ShouldSetPixelInPixelArray)
{
  Pixels::RGBPixelArray pixelArray = BitmapSetUp::redPixelArray();
  Pixels::RGBColours greenColours = BitmapSetUp::greenColours();
  Pixels::RGBPixel greenPixel {greenColours};
  
  for (int rowNo = 0; rowNo < 2; rowNo++)
    for (int columnNo = 0; columnNo < 2; columnNo++)
      BitmapImageComparison::isRedPixel(pixelArray.at(rowNo, columnNo));

  pixelArray.set(greenPixel, 1, 0);

  Pixels::RGBPixel modifiedPixel = pixelArray.at(1, 0);
  BitmapImageComparison::isGreenPixel(modifiedPixel);
}

TEST(PixelArrayTests, ShouldGetNumberOfPixelsInPixelArray)
{
  Pixels::RGBPixelArray pixelArray = BitmapSetUp::redPixelArray();

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