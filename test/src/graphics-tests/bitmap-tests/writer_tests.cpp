#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/filesystem.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/bitmap-tests/bitmap_image_comparators.hpp"

BitmapImage setupBlueBitmapImage()
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {widthInPixels, heightInPixels};
  BitmapDibHeader bmpInfoHeader {widthInPixels, heightInPixels};
  Pixel bluePixel {100, 255, 255};

  size_t numberOfPixels = widthInPixels * heightInPixels;
  std::vector<Pixel> pixelsToAdd;

  for (int i = 0; i < numberOfPixels; i++)
    pixelsToAdd.push_back(bluePixel);

  PixelArray pixelArray {pixelsToAdd, widthInPixels, heightInPixels};

  BitmapImage bitmapImage {bmpFileHeader, bmpInfoHeader, pixelArray};

  return bitmapImage;
}

void writeBitmapImage(BitmapImage bitmapImage, std::string filePath)
{
  char* bitmapImageBytes = bitmapImage.toBytes();
  int bitmapImageSize = bitmapImage.getSizeOfBytes();

  std::ofstream fout(filePath, std::ios::binary);
  fout.write(bitmapImageBytes, bitmapImageSize);  
  fout.close();

  delete[] bitmapImageBytes;
}

TEST(BitmapWriterTests, ShouldCreateBitmap)
{
  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  char* correctImagePath =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  BitmapImage bitmapImage = setupBlueBitmapImage();
  writeBitmapImage(bitmapImage, imageToTestPath);
  
  BitmapImage correctImage = BitmapImage::fromFile(correctImagePath);  
  BitmapImage imageToTest = BitmapImage::fromFile(imageToTestPath);

  compareBitmapImages(correctImage, imageToTest);
}