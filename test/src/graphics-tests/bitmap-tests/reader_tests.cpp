#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapReaderTests, ShouldExtractFileHeaderFromFile)
{ 
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapHeaders::FileHeader fileHeader = 
    BitmapReader::getBitmapFileHeader(imagePath);
  
  BitmapHeaders::FileHeader correctFileHeader = 
    BitmapSetUp::setUpBluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctFileHeader, fileHeader);
}

TEST(BitmapReaderTests, ShouldExtractDibHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapHeaders::DibHeader dibHeader =
    BitmapReader::getBitmapDibHeader(imagePath);
  
  BitmapHeaders::DibHeader correctDibHeader = 
    BitmapSetUp::setUpBluePixelDibHeader();

  BitmapImageComparison::compareBitmapDibHeaders(correctDibHeader, dibHeader);
}

TEST(BitmapReaderTests, ShouldExtractPixelArrayFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  Pixels::PixelArray pixelArrayToTest = BitmapReader::getPixelArray(imagePath);
  Pixels::PixelArray correctPixelArray = BitmapSetUp::setUpBluePixelArray();

  BitmapImageComparison::comparePixelArrays(
    correctPixelArray, pixelArrayToTest);
}

TEST(BitmapReaderTests, ShouldExtractPixelArraySizeFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getPixelArraySizeInBytes(imagePath);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}

TEST(BitmapReaderTests, ShouldExtractBitmapImageObjectFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapImage imageToTest = BitmapImage::fromFile(imagePath);
  BitmapImage correctImage = BitmapSetUp::setUpBlueBitmapImage();

  BitmapImageComparison::compareBitmapImages(correctImage, imageToTest);
}