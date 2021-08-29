#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/bitmap-tests/bitmap_image_comparators.hpp"

BitmapFileHeader setUpBluePixelFileHeader()
{
  BitmapFileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setSizeOfBitmapFile(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelDataOffset(54);

  return fileHeader;
}

BitmapDibHeader setUpBluePixelDibHeader()
{
  BitmapDibHeader dibHeader = BitmapDibHeader();

  dibHeader.setSizeOfHeaderInBytes(40);
  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);

  return dibHeader;
}

PixelArray setUpBluePixelArray()
{
  std::vector<Pixel> pixels;
  Pixel bluePixel {100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(bluePixel);
  
  PixelArray pixelArray = PixelArray {pixels, imageWidth, imageHeight};

  return pixelArray;
}

BitmapImage setUpBluePixelBitmapImage()
{
  BitmapFileHeader fileHeader = setUpBluePixelFileHeader();
  BitmapDibHeader dibHeader = setUpBluePixelDibHeader();
  PixelArray pixelArray = setUpBluePixelArray();

  BitmapImage bitmapImage {fileHeader, dibHeader, pixelArray};

  return bitmapImage;
}

std::string getBlueImagePath()
{
  std::string imagePath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  return imagePath;
}

TEST(BitmapReaderTests, ShouldExtractFileHeaderFromFile)
{ 
  std::string imagePath = getBlueImagePath();

  BitmapFileHeader fileHeader = BitmapReader::getBitmapFileHeader(imagePath);
  BitmapFileHeader correctFileHeader = setUpBluePixelFileHeader();
  
  compareBitmapFileHeaders(correctFileHeader, fileHeader);
}

TEST(BitmapReaderTests, ShouldExtractDibHeaderFromFile)
{
  std::string imagePath = getBlueImagePath();

  BitmapDibHeader dibHeader = BitmapReader::getBitmapDibHeader(imagePath);
  BitmapDibHeader correctDibHeader = setUpBluePixelDibHeader();

  compareBitmapDibHeaders(correctDibHeader, dibHeader);
}

TEST(BitmapReaderTests, ShouldExtractPixelArrayFromFile)
{
  std::string imagePath = getBlueImagePath();

  PixelArray pixelArrayToTest = BitmapReader::getPixelArray(imagePath);
  PixelArray correctPixelArray = setUpBluePixelArray();

  comparePixelArrays(correctPixelArray, pixelArrayToTest);
}

TEST(BitmapReaderTests, ShouldExtractPixelArraySizeFromFile)
{
  std::string imagePath = getBlueImagePath();

  int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getPixelArraySizeInBytes(imagePath);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}

TEST(BitmapReaderTests, ShouldExtractBitmapImageObjectFromFile)
{
  std::string imagePath = getBlueImagePath();

  BitmapImage imageToTest = BitmapImage::fromFile(imagePath);
  BitmapImage correctImage = setUpBluePixelBitmapImage();

  compareBitmapImages(correctImage, imageToTest);
}