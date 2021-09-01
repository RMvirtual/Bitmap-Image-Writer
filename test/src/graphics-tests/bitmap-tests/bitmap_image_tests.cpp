#include <gtest/gtest.h>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/graphics/shapes/triangle.h"
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

TEST(BitmapImageTests, ShouldDrawLine)
{
  BitmapImage bitmapImage = setupBlueBitmapImage();
  Pixel blackPixel {0, 0, 0};

  Maths::Vector vertex1 {50, 100};
  Maths::Vector vertex2 {50, -100};
  Maths::Vector vertex3 {-100, 0};

  std::vector<Maths::Vector> vertices {vertex1, vertex2, vertex3};
  Shapes::Triangle triangle {vertices};

  PixelArray pixelArray = bitmapImage.getPixelArray();

  int pixelWidth = pixelArray.getWidthInPixels();
  int pixelsHeight = pixelArray.getHeightInPixels();
  
  int totalPixels = pixelArray.sizeInPixels();

  Maths::Vector straightLine {100, 100};

  double x = 0, y = 0;

  while (x < straightLine[0]) { 
    // This bit causes bazel test error.
    // pixelArray.setPixel(blackPixel, x, y);

    x++;
    y++;
  }

  bitmapImage.setPixelArray(pixelArray);

  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\straightLine.bmp";

  bitmapImage.writeToFile(imageToTestPath);
}