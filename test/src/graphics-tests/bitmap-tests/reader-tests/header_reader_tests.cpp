#include <gtest/gtest.h>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapHeaderReaderTests, ShouldExtractFileHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapReader reader {};
  BitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::FileHeader correctHeader = 
    BitmapSetUp::setUpBluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctHeader, packet.fileHeader);
}

TEST(BitmapHeaderReaderTests, ShouldExtractDibHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapReader reader {};
  BitmapPacket packet = reader.readBitmapPacket(imagePath);
  
  BitmapHeaders::DibHeader correctHeader = 
    BitmapSetUp::setUpBluePixelDibHeader();
  
  BitmapImageComparison::compareBitmapDibHeaders(
    correctHeader, packet.dibHeader);
}