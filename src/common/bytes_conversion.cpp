#include "src/common/bytes_conversion.h"

uint32_t BytesConversion::getFourBytesFromSubstring(
  string stringToConvert, int startingByteIndex)
{
  string slicedString = stringToConvert.substr(startingByteIndex, 4);
  
  uint32_t extractedBytes = 
    BytesConversion::convertFourCharactersTo32bitInteger(slicedString);
  
  return extractedBytes;
}

uint16_t BytesConversion::getTwoBytesFromSubstring(
  string stringToConvert, int startingByteIndex)
{
  string slicedString = stringToConvert.substr(startingByteIndex, 2);

  uint16_t extractedBytes =
    BytesConversion::convertTwoCharactersTo16bitInteger(slicedString);
  
  return extractedBytes;
}

uint32_t BytesConversion::convertFourCharactersTo32bitInteger(
  string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8 |
    (uint8_t) stringToConvert[2] << 16 |
    (uint8_t) stringToConvert[3] << 24
  );
}

uint16_t BytesConversion::convertTwoCharactersTo16bitInteger(
  string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8
  );
}