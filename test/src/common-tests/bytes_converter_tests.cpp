#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/bytes_conversion.h"

using namespace std;

TEST(BytesConverterTest, ShouldGetTwoBytesFromSubstring)
{
  string stringToConvert = "crym3@river";

  uint32_t convertedValue 
    = BytesConversion::getTwoBytesFromSubstring(stringToConvert, 3);

  uint32_t correctValue = 13165;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldGetFourBytesFromSubstring)
{
  string stringToConvert = "crym3@river";

  uint32_t convertedValue 
    = BytesConversion::getFourBytesFromSubstring(stringToConvert, 3);

  uint32_t correctValue = 1916810093;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldConvertFourCharactersTo32bitInteger)
{
  string stringToConvert = "1234";

  uint32_t convertedValue 
    = BytesConversion::convertFourCharactersTo32bitInteger(stringToConvert);

  uint32_t correctValue = 875770417;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldConvertTwoCharactersTo32bitInteger)
{
  string stringToConvert = "xo";

  uint16_t convertedValue 
    = BytesConversion::convertTwoCharactersTo16bitInteger(stringToConvert);

  uint16_t correctValue = 28536;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);
}