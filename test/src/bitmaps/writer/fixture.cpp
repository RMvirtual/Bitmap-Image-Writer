#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "test/src/bitmaps/writer/fixture.h"

BitmapWriterTest::BitmapWriterTest()
{

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