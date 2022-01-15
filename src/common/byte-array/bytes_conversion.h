#ifndef BYTES_CONVERSION_H
#define BYTES_CONVERSION_H

#include <cstdint>
#include <string>

#include "src/common/byte-array/byte_array.h"

namespace BytesConversion
{
  uint32_t get32BitInteger(ByteArray& bytes, int startingIndex);
  uint16_t get16BitInteger(ByteArray& bytes, int startingIndex);
  uint32_t convertTo32bitInteger(ByteArray& bytes);
  uint16_t convertTo16bitInteger(ByteArray& bytes);

  union ValueUnion {
    uint32_t fourByteValue;
    uint16_t twoByteValue;
    uint8_t byteValues[4];
  };
};

#endif