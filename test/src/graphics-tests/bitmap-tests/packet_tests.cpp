#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/size-calculator/pixel_array_size_calculator.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"

Pixels::RGBColours getRedColours()
{
  Pixels::RGBColours colours;
  colours.setRed(255);
  colours.setGreen(0);
  colours.setBlue(0);

  return colours;
}

Pixels::RGBColours getGreenColours()
{
  Pixels::RGBColours colours;
  colours.setRed(0);
  colours.setGreen(255);
  colours.setBlue(0);

  return colours;
}

Pixels::RGBColours getWhiteColours()
{
  Pixels::RGBColours colours;
  colours.setRed(255);
  colours.setGreen(255);
  colours.setBlue(255);

  return colours;
}

void isGreenPixel(Pixels::RGBPixel pixel)
{
  Pixels::RGBColours colours = pixel.colours();

  EXPECT_EQ(colours.green(), 255);
  EXPECT_EQ(colours.blue(), 0);
  EXPECT_EQ(colours.red(), 0);
}

void isRedPixel(Pixels::RGBPixel pixel)
{
  Pixels::RGBColours colours = pixel.colours();

  EXPECT_EQ(colours.green(), 0);
  EXPECT_EQ(colours.blue(), 0);
  EXPECT_EQ(colours.red(), 255);
}

Pixels::RGBPixelArray getRedPixelArray()
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {getRedColours()};

  return {values};
}

TEST(PixelArrayTests, ShouldSetPixelInPixelArray)
{
  Pixels::RGBPixelArray pixelArray = getRedPixelArray();
  Pixels::RGBColours greenColours = getGreenColours();
  Pixels::RGBPixel greenPixel {greenColours};
  
  for (int rowNo = 0; rowNo < 2; rowNo++)
    for (int columnNo = 0; columnNo < 2; columnNo++)
      isRedPixel(pixelArray.at(rowNo, columnNo));

  pixelArray.set(greenPixel, 1, 0);

  Pixels::RGBPixel modifiedPixel = pixelArray.at(1, 0);
  isGreenPixel(modifiedPixel);
}

TEST(PixelArrayTests, ShouldGetNumberOfPixelsInPixelArray)
{
  Pixels::RGBPixelArray pixelArray = getRedPixelArray();

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