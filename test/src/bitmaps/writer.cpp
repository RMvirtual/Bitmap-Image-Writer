#include <gtest/gtest.h>

#include "test/src/bitmaps/test-utilities/set_up.h"
#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"

class BitmapWriterTest : public ::testing::Test
{
public:
  BitmapWriterTest()
  {

  }

  ~BitmapWriterTest()
  {

  }

protected:
  Bitmaps::ImageWriter writer;

  void testFourBytesAgainstValue(uint32_t intValue, ByteArray bytes)
  {
    uint32_t bytesValue = ByteConversion::to32BitInt(bytes);
    EXPECT_EQ(intValue, bytesValue);
  }

  void testTwoBytesAgainstValue(uint16_t intValue, ByteArray bytes)
  {
    uint16_t bytesValue = ByteConversion::to16BitInt(bytes);
    EXPECT_EQ(intValue, bytesValue);
  }

  void testTwoBytesAgainstTwoChars(std::string chars, ByteArray bytes)
  {
    EXPECT_EQ(chars[0], bytes[0]);
    EXPECT_EQ(chars[1], bytes[1]);
  }
};

TEST_F(BitmapWriterTest, ShouldConvertFileHeaderToBytes)
{
  auto header = BitmapSetUp::bluePixelFileHeader();
  auto bytes = this->writer.convertToBytes(header);

  this->testTwoBytesAgainstTwoChars(header.signatureBytes(), bytes.slice(0,2));
  this->testFourBytesAgainstValue(header.fileSizeInBytes(), bytes.slice(2,6));  
  this->testFourBytesAgainstValue(header.reservedBytes(), bytes.slice(6,10));
  
  this->testFourBytesAgainstValue(
    header.pixelArrayOffsetInBytes(), bytes.slice(10,14));
}

TEST_F(BitmapWriterTest, ShouldConvertDibHeaderToBytes)
{
  auto header = BitmapSetUp::bluePixelDibHeader();
  auto bytes = this->writer.convertToBytes(header);

  this->testFourBytesAgainstValue(
    header.headerSizeInBytes(), bytes.slice(0,4));
  
  this->testFourBytesAgainstValue(
    header.widthInPixels(), bytes.slice(4,8));
  
  this->testFourBytesAgainstValue(
    header.heightInPixels(), bytes.slice(8,12));
  
  this->testTwoBytesAgainstValue(
    header.numberOfColorPlanes(), bytes.slice(12,14));
  
  this->testTwoBytesAgainstValue(
    header.bitsPerPixel(), bytes.slice(14,16));
  
  this->testFourBytesAgainstValue(
    header.compressionMethod(), bytes.slice(16,20));
  
  this->testFourBytesAgainstValue(
    header.sizeOfPixelArray(), bytes.slice(20,24));
  
  this->testFourBytesAgainstValue(
    header.horizontalResolution(), bytes.slice(24,28));
  
  this->testFourBytesAgainstValue(
    header.verticalResolution(), bytes.slice(28,32));
  
  this->testFourBytesAgainstValue(
    header.colorTableEntries(), bytes.slice(32,36));
 
  this->testFourBytesAgainstValue(
    header.importantColors(), bytes.slice(36,40));
}

TEST_F(BitmapWriterTest, ShouldConvertPixelArrayToBytes)
{
  auto pixelArray = BitmapSetUp::bluePixelArray(2, 2);
  auto bytes = this->writer.convertToBytes(pixelArray);

  EXPECT_TRUE(false);
}