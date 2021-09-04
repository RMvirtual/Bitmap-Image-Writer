#include <cstdint>
#include <gtest/gtest.h>
#include <vector>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

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

TEST(BitmapPixelArrayTests, ShouldSetPixel)
{
  Pixels::Pixel redPixel = {255, 0, 0};
  std::vector<Pixels::Pixel> redPixels = {redPixel, redPixel, redPixel, redPixel};
  Pixels::PixelArray pixelArray {redPixels, 2, 2};

  Pixels::Pixel greenPixel = {0, 255, 0};
  pixelArray.setPixel(greenPixel, 1, 1);

  for (int pixelNo = 0; pixelNo < 3; pixelNo++) {
    Pixels::Pixel pixel = pixelArray.pixels[pixelNo];
    isRedPixel(pixel);
  }

  Pixels::Pixel modifiedPixel = pixelArray.pixels[3];
  isGreenPixel(modifiedPixel);
}


TEST(BitmapPixelArrayTests, ShouldGetPixelSizeInBytes)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  Pixels::PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

  int correctSizeInBytes = 786432;
  int actualSizeInBytes = pixelArray.sizeInBytes();

  EXPECT_EQ(correctSizeInBytes, actualSizeInBytes);
}

TEST(BitmapPixelArrayTests, ShouldGetNumberOfPixels)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  Pixels::PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

  int correctSizeInPixels = 512 * 512;
  int actualSizeInPixels = pixelArray.sizeInPixels();

  EXPECT_EQ(correctSizeInPixels, actualSizeInPixels);
}

TEST(BitmapPixelArrayTests, ShouldGetPixelArrayBytes)
{
  Pixels::Pixel pixel {255, 200, 150};
  std::vector<Pixels::Pixel> pixels = {pixel, pixel, pixel, pixel};

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

TEST(BitmapPixelArrayTests, ShouldCalculatePadding)
{
  int correctPadding = 2;
  int actualPadding = Pixels::calculateRowPadding(6);

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST(BitmapPixelTests, ShouldCalculatePixelArrayRowSizeInBytes)
{
  int correctSize = 20;
  int actualSize = Pixels::calculateRowSizeInBytes(6);
  
  EXPECT_EQ(correctSize, actualSize);
}

TEST(BitmapPixelArrayTests, ShouldGetPixelBytes)
{
  Pixels::Pixel pixel {255, 255, 255};

  char* bytes = pixel.toBytes();

  for (int byteNo = 0; byteNo < 3; byteNo++) {
    uint8_t currentByte = (uint8_t) *(bytes + byteNo);
    uint8_t correctValue = 255;

    EXPECT_EQ(currentByte, correctValue); 
  }
}