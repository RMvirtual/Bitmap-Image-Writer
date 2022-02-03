#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "test/src/bitmaps/writer/fixture.h"

BitmapWriterTest::BitmapWriterTest()
{
  this->loadBluePixelFileHeader();
  this->loadBluePixelDibHeader();
  this->loadBluePixelArray();
}

BitmapWriterTest::~BitmapWriterTest()
{

}

void BitmapWriterTest::compare(std::string twoChars, ByteArray bytes)
{
  EXPECT_EQ(twoChars[0], bytes[0]);
  EXPECT_EQ(twoChars[1], bytes[1]);
}

void BitmapWriterTest::compare(uint16_t integer, ByteArray bytes)
{
  uint16_t bytesValue = ByteConversion::to16BitInt(bytes);
  EXPECT_EQ(integer, bytesValue);
}

void BitmapWriterTest::compare(uint32_t integer, ByteArray bytes)
{
  uint32_t bytesValue = ByteConversion::to32BitInt(bytes);
  EXPECT_EQ(integer, bytesValue);
}

void BitmapWriterTest::loadBluePixelFileHeader()
{
  this->fileHeader.setSignatureBytes("BM");
  this->fileHeader.setFileSizeInBytes(786486);
  this->fileHeader.setReservedBytes(0);
  this->fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapWriterTest::loadBluePixelDibHeader()
{
  this->dibHeader.setWidthInPixels(512);
  this->dibHeader.setHeightInPixels(512);
  this->dibHeader.setNumberOfColourPlanes(1);
  this->dibHeader.setBitsPerPixel(24);
}

void BitmapWriterTest::loadBluePixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->pixelArray = {format};
  this->loadBlueColours();
}