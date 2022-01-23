#include <gtest/gtest.h>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapReaderTests, ShouldReadFileHeaderFromFile)
{
  auto imagePath = BitmapSetUp::blueImagePath();

  BitmapReader::ImageReader reader {};
  auto packet = reader.readBitmapPacket(imagePath);
  auto correctHeader = BitmapSetUp::bluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctHeader, packet.fileHeader);
}

TEST(BitmapReaderTests, ShouldReadDibHeaderFromFile)
{
  auto imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};
  auto packet = reader.readBitmapPacket(imagePath);
  
  auto correctHeader = BitmapSetUp::bluePixelDibHeader();
  
  BitmapImageComparison::compareBitmapDibHeaders(
    correctHeader, packet.dibHeader);
}

TEST(BitmapReaderTests, ShouldReadPixelArrayFromFile)
{
  auto imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};
  auto packet = reader.readBitmapPacket(imagePath);
  auto correctPixelArray= BitmapSetUp::bluePixelArray();

  BitmapImageComparison::comparePixelArrays(
    correctPixelArray, packet.pixelArray);
}
