#include <gtest/gtest.h>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapReaderTests, ShouldReadFileHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapReader::ImageReader reader {};
  RGBBitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::FileHeader correctHeader = 
    BitmapSetUp::setUpBluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctHeader, packet.fileHeader);
}

TEST(BitmapReaderTests, ShouldReadDibHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();
  BitmapReader::ImageReader reader {};
  RGBBitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::DibHeader correctHeader = 
  BitmapSetUp::setUpBluePixelDibHeader();
  
  BitmapImageComparison::compareBitmapDibHeaders(
    correctHeader, packet.dibHeader);
}

TEST(BitmapReaderTests, ShouldReadPixelArrayFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();
  BitmapReader::ImageReader reader {};
  RGBBitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  Pixels::RGBPixelArray correctPixelArray = BitmapSetUp::setUpBluePixelArray();

  BitmapImageComparison::comparePixelArrays(
    correctPixelArray, packet.pixelArray);
}
