#include "src/main/containers/byte-array/byte_conversion.h"
#include "src/main/containers/byte-array/byte_array.h"

ByteArray ByteConversion::toBytes(unsigned int value, int lengthInBytes)
{
  ByteArray bytes {};

  for (int byteNo = 0; byteNo < lengthInBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    uint8_t newByte = (uint8_t) (value >> bitsToShift);
    bytes.add(newByte);
  }

  return bytes;
}

uint16_t ByteConversion::to16BitInt(const ByteArray& bytes)
{
  ByteConversion::ValueUnion values {};

  for (int byteNo = 0; byteNo < 2; byteNo++)
    values.byteValues[byteNo] = bytes[byteNo];

  return values.twoByteValue;
}

uint16_t ByteConversion::to16BitInt(
  const ByteArray& bytes, int startingIndex)
{
  auto twoBytes = bytes.slice(startingIndex, startingIndex + 2);
  
  return ByteConversion::to16BitInt(twoBytes);
}

uint32_t ByteConversion::to32BitInt(const ByteArray& bytes)
{
  ByteConversion::ValueUnion valueConverter {};

  for (int byteNo = 0; byteNo < 4; byteNo++)
    valueConverter.byteValues[byteNo] = bytes[byteNo];

  return valueConverter.fourByteValue;
}

uint32_t ByteConversion::to32BitInt(const ByteArray& bytes, int startingIndex)
{
  auto fourBytes = bytes.slice(startingIndex, startingIndex + 4);
   
  return ByteConversion::to32BitInt(fourBytes);
}