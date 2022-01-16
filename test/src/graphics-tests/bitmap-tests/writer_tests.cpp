#include <gtest/gtest.h>

#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte-array/byte_conversion.h"

void testFourBytesAgainstValue(uint32_t intValue, ByteArray bytes)
{
  uint32_t bytesValue = ByteConversion::convertTo32BitInt(bytes);
  EXPECT_EQ(intValue, bytesValue);
}

void testTwoBytesAgainstValue(uint16_t intValue, ByteArray bytes)
{
  uint16_t bytesValue = ByteConversion::convertTo16BitInt(bytes);
  EXPECT_EQ(intValue, bytesValue);
}

void testTwoBytesAgainstTwoChars(std::string chars, ByteArray bytes)
{
  EXPECT_EQ(chars[0], bytes[0].value);
  EXPECT_EQ(chars[1], bytes[1].value);
}

TEST(BitmapWriterTests, ShouldConvertFileHeaderToBytes)
{
  BitmapWriter::ImageWriter writer {};
  auto header = BitmapSetUp::setUpBluePixelFileHeader();
  auto bytes = writer.convertToBytes(header);

  testTwoBytesAgainstTwoChars(header.signatureBytes(), bytes.slice(0,2));
  testFourBytesAgainstValue(header.fileSizeInBytes(), bytes.slice(2,6));  
  testFourBytesAgainstValue(header.reservedBytes(), bytes.slice(6,10));
  testFourBytesAgainstValue(header.pixelArrayOffsetInBytes(), bytes.slice(10,14));
}

TEST(BitmapWriterTests, ShouldConvertDibHeaderToBytes)
{
  BitmapWriter::ImageWriter writer {};
  auto header = BitmapSetUp::setUpBluePixelDibHeader();
  auto bytes = writer.convertToBytes(header);

  testFourBytesAgainstValue(header.headerSizeInBytes(), bytes.slice(0,4));
  testFourBytesAgainstValue(header.widthInPixels(), bytes.slice(4,8));
  testFourBytesAgainstValue(header.heightInPixels(), bytes.slice(8,12));
  testTwoBytesAgainstValue(header.numberOfColorPlanes(), bytes.slice(12,14));
  testTwoBytesAgainstValue(header.colorDepth(), bytes.slice(14,16));
  testFourBytesAgainstValue(header.compressionMethod(), bytes.slice(16,20));
  testFourBytesAgainstValue(header.rawBitmapDataSize(), bytes.slice(20,24));
  testFourBytesAgainstValue(header.horizontalResolution(), bytes.slice(24,28));
  testFourBytesAgainstValue(header.verticalResolution(), bytes.slice(28,32));
  testFourBytesAgainstValue(header.colorTableEntries(), bytes.slice(32,36));
  testFourBytesAgainstValue(header.importantColors(), bytes.slice(36,40));
}

TEST(BitmapWriterTests, ShouldConvertPixelArrayToBytes)
{
  BitmapWriter::ImageWriter writer {};
  auto pixelArray = BitmapSetUp::setUpBluePixelArray();
  auto bytes = writer.convertToBytes(pixelArray);

  EXPECT_TRUE(false);
}