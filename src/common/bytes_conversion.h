#ifndef BYTES_CONVERSION_H
#define BYTES_CONVERSION_H

#include <cstdint>
#include <string>

namespace BytesConversion
{
  uint32_t getFourBytesFromSubstring(std::string stringToIndex, int startingIndex);
  uint16_t getTwoBytesFromSubstring(std::string stringToIndex, int startingIndex);

  uint32_t convertFourCharactersTo32bitInteger(std::string stringToConvert);
  uint16_t convertTwoCharactersTo16bitInteger(std::string stringToConvert);
};

#endif