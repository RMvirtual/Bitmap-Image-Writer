#include <gtest/gtest.h>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/bitmap-tests/bitmap_image_comparators.hpp"

PixelArray setUpBluePixelArray(int widthInPixels, int heightInPixels)
{
  Pixel bluePixel {100, 255, 255};
  size_t numberOfPixels = widthInPixels * heightInPixels;
  std::vector<Pixel> pixelsToAdd;

  for (int i = 0; i < numberOfPixels; i++)
    pixelsToAdd.push_back(bluePixel);

  PixelArray pixelArray {pixelsToAdd, widthInPixels, heightInPixels};

  return pixelArray;
}

BitmapImage setupBlueBitmapImage()
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {widthInPixels, heightInPixels};
  BitmapDibHeader bmpInfoHeader {widthInPixels, heightInPixels};
  PixelArray pixelArray = setUpBluePixelArray(widthInPixels, heightInPixels);

  BitmapImage bitmapImage {bmpFileHeader, bmpInfoHeader, pixelArray};

  return bitmapImage;
}

TEST(BitmapImageTests, ShouldWriteBitmap)
{
  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  char* correctImagePath =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  BitmapImage bitmapImage = setupBlueBitmapImage();
  bitmapImage.writeToFile(imageToTestPath);
  
  BitmapImage correctImage = BitmapImage::fromFile(correctImagePath);  
  BitmapImage imageToTest = BitmapImage::fromFile(imageToTestPath);

  compareBitmapImages(correctImage, imageToTest);
}

TEST(BitmapImageTests, ShouldDrawTriangle)
{
  BitmapImage bitmapImage = setupBlueBitmapImage();
  
}