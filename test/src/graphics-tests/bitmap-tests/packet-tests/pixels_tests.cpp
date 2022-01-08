#include <cstdint>
#include <gtest/gtest.h>
#include <vector>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

void isGreenPixel(Pixels::Pixel pixel)
{
    EXPECT_EQ(pixel.getGreen(), 255);
    EXPECT_EQ(pixel.getBlue(), 0);
    EXPECT_EQ(pixel.getRed(), 0);
}

void isRedPixel(Pixels::Pixel pixel)
{
  EXPECT_EQ(pixel.getGreen(), 0);
  EXPECT_EQ(pixel.getBlue(), 0);
  EXPECT_EQ(pixel.getRed(), 255);
}

Pixels::PixelArray getRedPixelArray()
{
  Colours redColours;
  redColours.red = 255;
  redColours.green = 0;
  redColours.blue = 0;

  Pixels::Pixel redPixel {redColours};

  std::vector<Pixels::Pixel> redPixels {
    redPixel, redPixel, redPixel, redPixel};

  return {redPixels, 2, 2};
}

TEST(PixelArrayTests, ShouldSetPixelInPixelArray)
{
  Colours redColours = BitmapSetUp::getRedColours();
  Pixels::Pixel redPixel {redColours};

  std::vector<Pixels::Pixel> redPixels {
    redPixel, redPixel, redPixel, redPixel};

  Pixels::PixelArray pixelArray = getRedPixelArray();

  Colours greenColours = BitmapSetUp::getGreenColours();
  Pixels::PixelData greenPixelData;
  greenPixelData.colours = greenColours;  
  greenPixelData.rowNo = 1;
  greenPixelData.columnNo = 1;
  
  for (int pixelNo = 0; pixelNo < 4; pixelNo++)
    isRedPixel(pixelArray.pixels[pixelNo]);

  pixelArray.setPixel(greenPixelData);
  Pixels::Pixel modifiedPixel = pixelArray.pixels[3];
  isGreenPixel(modifiedPixel);
}

TEST(PixelArrayTests, ShouldGetNumberOfPixelsInPixelArray)
{
  Pixels::PixelArray pixelArray = getRedPixelArray();

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