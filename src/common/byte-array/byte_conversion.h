#ifndef BYTE_CONVERTOR_H
#define BYTE_CONVERTOR_H

#include <cstdint>
#include "src/common/byte-array/byte_array.h"

namespace ByteConversion
{
  ByteArray convertToBytes(unsigned int value, int lengthInBytes);
  uint32_t convertTo32BitInt(const ByteArray& bytes, int startingIndex);
  uint16_t convertTo16BitInt(const ByteArray& bytes, int startingIndex);
  uint32_t convertTo32BitInt(const ByteArray& bytes);
  uint16_t convertTo16BitInt(const ByteArray& bytes);
  
  union ValueUnion {
    uint32_t fourByteValue;
    uint16_t twoByteValue;
    uint8_t byteValues[4];
  };
};

#endif