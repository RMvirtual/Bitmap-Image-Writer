#include <gtest/gtest.h>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapReaderTests, ShouldReadFileHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::blueImagePath();

  BitmapReader::ImageReader reader {};
  BitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::FileHeader correctHeader = 
    BitmapSetUp::bluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctHeader, packet.fileHeader);
}

TEST(BitmapReaderTests, ShouldReadDibHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};
  BitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::DibHeader correctHeader = 
  BitmapSetUp::bluePixelDibHeader();
  
  BitmapImageComparison::compareBitmapDibHeaders(
    correctHeader, packet.dibHeader);
}

TEST(BitmapReaderTests, ShouldReadPixelArrayFromFile)
{
  std::string imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};
  auto packet = reader.readBitmapPacket(imagePath);
  auto correctPixelArray= BitmapSetUp::bluePixelArray();

  BitmapImageComparison::comparePixelArrays(
    correctPixelArray, packet.pixelArray);
}
