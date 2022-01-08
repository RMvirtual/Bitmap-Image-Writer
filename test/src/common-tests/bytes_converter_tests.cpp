#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/bytes_conversion.h"
#include "src/common/byte_array_builder.h"
#include "src/common/byte_array.h"

TEST(BytesConverterTest, ShouldExtract16BitIntegerFromByteArray)
{
  ByteArrayBuilder byteArrayBuilder {};
  byteArrayBuilder.add("crym3@river");
  ByteArray byteArray = byteArrayBuilder.toByteArray();

  uint32_t value = BytesConversion::get16BitInteger(byteArray, 3);
  uint32_t correctValue = 13165;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}

TEST(BytesConverterTest, ShouldExtract32BitIntegerFromByteArray)
{
  ByteArrayBuilder byteArrayBuilder {};
  byteArrayBuilder.add("crym3@river");
  ByteArray byteArray = byteArrayBuilder.toByteArray();

  uint32_t value = BytesConversion::get32BitInteger(byteArray, 3);
  uint32_t correctValue = 1916810093;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}