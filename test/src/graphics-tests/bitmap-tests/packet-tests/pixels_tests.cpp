#include <cstdint>
#include <gtest/gtest.h>
#include <vector>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
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

Colours getRedColours()
{
  Colours colours;
  colours.red = 255;
  colours.green = 0;
  colours.blue = 0;

  return colours;
}

Colours getGreenColours()
{
  Colours colours;
  colours.red = 0;
  colours.green = 255;
  colours.blue = 0;

  return colours;
}

Colours getWhiteColours()
{
  Colours colours;
  colours.red = 255;
  colours.green = 255;
  colours.blue = 255;

  return colours;
}

TEST(PixelTests, ShouldStreamPixelIntoBytes)
{
  Colours colours = getWhiteColours();

  Pixels::Pixel pixel {colours};
  char* bytes = pixel.toBytes();

  for (int byteNo = 0; byteNo < 3; byteNo++) {
    uint8_t currentByte = (uint8_t) *(bytes + byteNo);
    uint8_t correctValue = 255;

    EXPECT_EQ(currentByte, correctValue); 
  }
}

TEST(PixelArrayTests, ShouldSetPixelInPixelArray)
{
  Colours redColours = getRedColours();
  Pixels::Pixel redPixel {redColours};

  std::vector<Pixels::Pixel> redPixels {
    redPixel, redPixel, redPixel, redPixel};

  Pixels::PixelArray pixelArray = getRedPixelArray();

  Colours greenColours = getGreenColours();
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

TEST(PixelArrayTests, ShouldStreamPixelArrayIntoBytes)
{
  Colours colours;
  colours.red = 255;
  colours.green = 200;
  colours.blue = 150;

  Pixels::Pixel pixel {colours};
  std::vector<Pixels::Pixel> pixels {pixel, pixel, pixel, pixel};
  Pixels::PixelArray pixelArray {pixels, 2, 2};

  char* pixelArrayBytes = pixelArray.toBytes();

  uint8_t correctBytes[] = {
    150, 200, 255, 150, 200, 255, 0, 0,
    150, 200, 255, 150, 200, 255, 0, 0
  };

  for (int byteNo = 0; byteNo < pixelArray.sizeInBytes(); byteNo++) {
    uint8_t currentByte = (uint8_t) pixelArrayBytes[byteNo];
    uint8_t correctValue = correctBytes[byteNo];

    EXPECT_EQ(currentByte, correctValue);
  }
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