#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

BitmapPacket getBitmapPacket()
{
  auto imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};

  return reader.readBitmapPacket(imagePath);
}

TEST(BitmapReader, ShouldReadFileHeader)
{
  auto header = getBitmapPacket().fileHeader;
  auto correctHeader = BitmapSetUp::bluePixelFileHeader();
  
  BitmapImageComparison::compare(correctHeader, header);
}

TEST(BitmapReader, ShouldReadDibHeader)
{
  auto header = getBitmapPacket().dibHeader;
  auto correctHeader = BitmapSetUp::bluePixelDibHeader();

  BitmapImageComparison::compare(correctHeader, header);
}

TEST(BitmapReader, ShouldReadPixelArray)
{
  auto pixelArray = getBitmapPacket().pixelArray;
  auto correctPixelArray = BitmapSetUp::bluePixelArray();

  BitmapImageComparison::compare(correctPixelArray, pixelArray);
}