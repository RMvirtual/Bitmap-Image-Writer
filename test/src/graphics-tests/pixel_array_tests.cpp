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

TEST(GraphicsTests, ShouldGetPixelArray)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);
  std::vector<Pixel> correctPixels;

  for (int i = 0; i < 512 * 512; i++) {
    correctPixels.push_back(Pixel {100, 255, 255});
  }
  
  PixelArray correctPixelArray = PixelArray {
    correctPixels, 512, 512};

  for (int pixelNo = 0; pixelNo < 512 * 512; pixelNo++) {
    Pixel pixelToTest = pixelArray.pixels[pixelNo];
    Pixel correctPixel = correctPixelArray.pixels[pixelNo];

    EXPECT_EQ(correctPixel.getRed(), pixelToTest.getRed());
    EXPECT_EQ(correctPixel.getGreen(), pixelToTest.getGreen());
    EXPECT_EQ(correctPixel.getBlue(), pixelToTest.getBlue());
  }
}

TEST(GraphicsTests, ShouldGetPixelSizeInBytes)
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

TEST(GraphicsTests, ShouldGetNumberOfPixels)
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