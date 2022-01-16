#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/byte-array/bytes_conversion.h"
#include "src/common/byte-array/byte_array_builder.h"
#include "src/common/byte-array/byte_array.h"

TEST(BytesConverterTest, ShouldExtract16BitIntegerFromByteArray)
{
  ByteArrayBuilder byteArrayBuilder {};
  byteArrayBuilder.add(std::string {"crym3@river"});
  ByteArray byteArray = byteArrayBuilder.toByteArray();

  uint16_t value = BytesConversion::get16BitInteger(byteArray, 3);
  uint16_t correctValue = 13165;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}

TEST(BytesConverterTest, ShouldExtract32BitIntegerFromByteArray)
{
  ByteArrayBuilder byteArrayBuilder {};
  byteArrayBuilder.add(std::string {"crym3@river"});
  ByteArray byteArray = byteArrayBuilder.toByteArray();

  uint32_t value = BytesConversion::get32BitInteger(byteArray, 3);
  uint32_t correctValue = 1916810093;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}