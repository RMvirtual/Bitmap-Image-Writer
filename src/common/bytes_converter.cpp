#include "src/common/bytes_converter.h"

uint32_t BytesConverter::convertFourCharactersTo32bitInteger(
  string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8 |
    (uint8_t) stringToConvert[2] << 16 |
    (uint8_t) stringToConvert[3] << 24
  );
}

uint16_t BytesConverter::convertTwoCharactersTo16bitInteger(
  string stringToConvert)
{
  return uint32_t (
    (uint8_t) stringToConvert[0] |
    (uint8_t) stringToConvert[1] << 8
  );
}