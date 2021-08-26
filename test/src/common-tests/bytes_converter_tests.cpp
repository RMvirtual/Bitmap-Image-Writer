#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/bytes_converter.h"

using namespace std;

TEST(BytesConverterTest, ShouldConvertFourCharacterTo32bitInteger)
{
  BytesConverter bytesConverter;
  string stringToConvert = "1234";

  uint32_t convertedValue 
    = bytesConverter.convertFourCharactersTo32bitInteger(stringToConvert);

  uint32_t correctValue = 875770417;

  EXPECT_DOUBLE_EQ(correctValue, convertedValue);  
}
