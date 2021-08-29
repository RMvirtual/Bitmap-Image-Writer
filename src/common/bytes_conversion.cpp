#include "src/common/bytes_conversion.h"

uint32_t BytesConversion::getFourBytesFromSubstring(
  std::string stringToConvert, int startingByteIndex)
{
  std::string slicedString = stringToConvert.substr(startingByteIndex, 4);
  
  uint32_t extractedBytes = 
    BytesConversion::convertFourCharactersTo32bitInteger(slicedString);
  
  return extractedBytes;
}

uint16_t BytesConversion::getTwoBytesFromSubstring(
  std::string stringToConvert, int startingByteIndex)
{
  std::string slicedString = stringToConvert.substr(startingByteIndex, 2);

  uint16_t extractedBytes =
    BytesConversion::convertTwoCharactersTo16bitInteger(slicedString);
  
  return extractedBytes;
}

uint32_t BytesConversion::convertFourCharactersTo32bitInteger(
  std::string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8 |
    (uint8_t) stringToConvert[2] << 16 |
    (uint8_t) stringToConvert[3] << 24
  );
}

uint16_t BytesConversion::convertTwoCharactersTo16bitInteger(
  std::string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8
  );
}