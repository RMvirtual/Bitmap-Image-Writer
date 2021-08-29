#include <gtest/gtest.h>
#include <vector>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

TEST(BitmapPixelArrayTests, ShouldGetPixelSizeInBytes)
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

TEST(BitmapPixelArrayTests, ShouldGetNumberOfPixels)
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

