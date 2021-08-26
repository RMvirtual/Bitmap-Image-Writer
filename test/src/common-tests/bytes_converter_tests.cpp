#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/bytes_converter.h"

using namespace std;

TEST(BytesConverterTest, ShouldGetTwoBytesFromSubstring)
{
  BytesConverter bytesConverter;
  string stringToConvert = "crym3@river";

  uint32_t convertedValue 
    = bytesConverter.getTwoBytesFromSubstring(stringToConvert, 3);

  uint32_t correctValue = 13165;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldGetFourBytesFromSubstring)
{
  BytesConverter bytesConverter;
  string stringToConvert = "crym3@river";

  uint32_t convertedValue 
    = bytesConverter.getFourBytesFromSubstring(stringToConvert, 3);

  uint32_t correctValue = 1916810093;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldConvertFourCharactersTo32bitInteger)
{
  BytesConverter bytesConverter;
  string stringToConvert = "1234";

  uint32_t convertedValue 
    = bytesConverter.convertFourCharactersTo32bitInteger(stringToConvert);

  uint32_t correctValue = 875770417;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}

TEST(BytesConverterTest, ShouldConvertTwoCharactersTo32bitInteger)
{
  BytesConverter bytesConverter;
  string stringToConvert = "xo";

  uint16_t convertedValue 
    = bytesConverter.convertTwoCharactersTo16bitInteger(stringToConvert);

  uint16_t correctValue = 28536;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);
}