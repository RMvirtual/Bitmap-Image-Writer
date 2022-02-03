#include <gtest/gtest.h>

#include "test/src/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldConvertFileHeaderToBytes)
{
  auto header = this->bluePixelFileHeader();
  auto bytes = this->writer.convertToBytes(header);

  this->compare(header.signatureBytes(), bytes.slice(0,2));
  this->compare(header.fileSizeInBytes(), bytes.slice(2,6));  
  this->compare(header.reservedBytes(), bytes.slice(6,10));
  this->compare(header.pixelArrayOffsetInBytes(), bytes.slice(10,14));
}

TEST_F(BitmapWriterTest, ShouldConvertDibHeaderToBytes)
{
  auto header = this->bluePixelDibHeader();
  auto bytes = this->writer.convertToBytes(header);

  this->compare((uint32_t) header.headerSizeInBytes(), bytes.slice(0,4));
  this->compare((uint32_t) header.widthInPixels(), bytes.slice(4,8));
  this->compare((uint32_t) header.heightInPixels(), bytes.slice(8,12));
  this->compare(header.numberOfColorPlanes(), bytes.slice(12,14));
  this->compare(header.bitsPerPixel(), bytes.slice(14,16));
  this->compare(header.compressionMethod(), bytes.slice(16,20));
  this->compare(header.sizeOfPixelArray(), bytes.slice(20,24));
  this->compare((uint32_t) header.horizontalResolution(), bytes.slice(24,28));
  this->compare((uint32_t) header.verticalResolution(), bytes.slice(28,32));
  this->compare(header.colorTableEntries(), bytes.slice(32,36));
  this->compare(header.importantColors(), bytes.slice(36,40));
}

TEST_F(BitmapWriterTest, ShouldConvertPixelArrayToBytes)
{
  auto pixelArray = this->bluePixelArray(2, 2);
  auto bytes = this->writer.convertToBytes(pixelArray);

  EXPECT_TRUE(false);
}