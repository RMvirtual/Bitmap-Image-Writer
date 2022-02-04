#include <gtest/gtest.h>

#include "src/containers/byte-array/byte_array.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "test/src/bitmaps/writer/fixture.h"

void BitmapWriterTest::compare(std::string chars, ByteArray bytes)
{
  int noOfCharacters = chars.size();
  int noOfBytes = bytes.size();

  ASSERT_EQ(noOfCharacters, noOfBytes);

  for (int i = 0; i < noOfCharacters; i++)
    EXPECT_EQ(chars[i], bytes[i]);
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

ByteArray BitmapWriterTest::writeBlueFile()
{ 
  return this->writer.convertToBytes(this->packet);
}