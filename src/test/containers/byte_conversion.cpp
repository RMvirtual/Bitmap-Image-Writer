#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/main/containers/byte-array/byte_conversion.h"
#include "src/main/containers/byte-array/byte_array.h"

TEST(ByteConversion, ShouldConvertByteArrayTo16BitInt)
{
  ByteArray byteArray {};
  byteArray.add(std::string {"crym3@river"});

  uint16_t value = ByteConversion::to16BitInt(byteArray, 3);
  uint16_t correctValue = 13165;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}

TEST(ByteConversion, ShouldConvertByteArrayTo32BitInt)
{
  ByteArray byteArray {};
  byteArray.add(std::string {"crym3@river"});

  uint32_t value = ByteConversion::to32BitInt(byteArray, 3);
  uint32_t correctValue = 1916810093;

  EXPECT_DOUBLE_EQ(correctValue, value);  
}