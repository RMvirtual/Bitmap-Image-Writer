#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/file_opener.h"

TEST(BitmapTests, ShouldGetPixelArray)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);
  std::vector<Pixel> correctPixels;
  Pixel bluePixel {100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    correctPixels.push_back(bluePixel);
  
  PixelArray correctPixelArray = PixelArray {
    correctPixels, 512, 512};

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++) {
    Pixel pixelToTest = pixelArray.pixels[pixelNo];
    Pixel correctPixel = correctPixelArray.pixels[pixelNo];

    EXPECT_EQ(correctPixel.getRed(), pixelToTest.getRed());
    EXPECT_EQ(correctPixel.getGreen(), pixelToTest.getGreen());
    EXPECT_EQ(correctPixel.getBlue(), pixelToTest.getBlue());
  }
}

TEST(BitmapTests, ShouldGetPixelSizeInBytes)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

  int correctSizeInBytes = 786432;
  int actualSizeInBytes = pixelArray.sizeInBytes();

  EXPECT_EQ(correctSizeInBytes, actualSizeInBytes);
}

TEST(BitmapTests, ShouldGetNumberOfPixels)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);

  int correctSizeInPixels = 512 * 512;
  int actualSizeInPixels = pixelArray.sizeInPixels();

  EXPECT_EQ(correctSizeInPixels, actualSizeInPixels);
}