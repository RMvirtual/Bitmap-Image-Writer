#include <cstdint>
#include <gtest/gtest.h>
#include <vector>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

void isGreenPixel(Pixel pixel)
{
    EXPECT_EQ(pixel.getGreen(), 255);
    EXPECT_EQ(pixel.getBlue(), 0);
    EXPECT_EQ(pixel.getRed(), 0);
}

void isRedPixel(Pixel pixel)
{
  EXPECT_EQ(pixel.getGreen(), 0);
  EXPECT_EQ(pixel.getBlue(), 0);
  EXPECT_EQ(pixel.getRed(), 255);
}

TEST(BitmapPixelArrayTests, ShouldSetPixel)
{
  Pixel redPixel = {255, 0, 0};
  std::vector<Pixel> redPixels = {redPixel, redPixel, redPixel, redPixel};
  PixelArray pixelArray {redPixels, 2, 2};

  Pixel greenPixel = {0, 255, 0};
  pixelArray.setPixel(greenPixel, 1, 1);

  for (int pixelNo = 0; pixelNo < 3; pixelNo++) {
    Pixel pixel = pixelArray.pixels[pixelNo];
    isRedPixel(pixel);
  }

  Pixel modifiedPixel = pixelArray.pixels[3];
  isGreenPixel(modifiedPixel);
}


TEST(BitmapPixelArrayTests, ShouldGetPixelSizeInBytes)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

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

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

  int correctSizeInPixels = 512 * 512;
  int actualSizeInPixels = pixelArray.sizeInPixels();

  EXPECT_EQ(correctSizeInPixels, actualSizeInPixels);
}

TEST(BitmapPixelArrayTests, ShouldGetPixelArrayBytes)
{
  Pixel pixel {255, 255, 255};
  std::vector<Pixel> pixels = {pixel, pixel, pixel, pixel};

  PixelArray pixelArray {pixels, 2, 2};

  char* pixelArrayBytes = pixelArray.toBytes();

  for (int byteNo = 0; byteNo < pixelArray.sizeInBytes(); byteNo++) {
    uint8_t currentByte = (uint8_t) pixelArrayBytes[byteNo];
    uint8_t correctValue = 255;

    EXPECT_EQ(currentByte, correctValue);
  }
}

TEST(BitmapPixelArrayTests, ShouldGetPixelBytes)
{
  Pixel pixel {255, 255, 255};

  char* bytes = pixel.toBytes();

  for (int byteNo = 0; byteNo < 3; byteNo++) {
    uint8_t currentByte = (uint8_t) *(bytes + byteNo);
    uint8_t correctValue = 255;

    EXPECT_EQ(currentByte, correctValue); 
  }
}