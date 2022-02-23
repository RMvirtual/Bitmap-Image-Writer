#ifndef BYTE_CONVERTOR_H
#define BYTE_CONVERTOR_H

#include <cstdint>
#include "src/main/containers/byte-array/byte_array.h"

namespace ByteConversion
{
  ByteArray toBytes(unsigned int value, int lengthInBytes);
  uint32_t to32BitInt(const ByteArray& bytes, int startingIndex);
  uint16_t to16BitInt(const ByteArray& bytes, int startingIndex);
  uint32_t to32BitInt(const ByteArray& bytes);
  uint16_t to16BitInt(const ByteArray& bytes);
  
  union ValueUnion {
    uint32_t fourByteValue;
    uint16_t twoByteValue;
    uint8_t byteValues[4];
  };
};

#endif