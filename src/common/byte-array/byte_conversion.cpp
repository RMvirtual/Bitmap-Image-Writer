#include "src/common/byte-array/byte_conversion.h"
#include "src/common/byte-array/byte_array.h"

ByteArray ByteConversion::convertToBytes(unsigned int value, int lengthInBytes)
{
  ByteArray bytes {};

  for (int byteNo = 0; byteNo < lengthInBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    uint8_t newValue = (uint8_t) (value >> bitsToShift);

    Byte newByte = {newValue};    
    bytes.add(newByte);
  }

  return bytes;
}

uint16_t ByteConversion::convertTo16BitInt(const ByteArray& bytes)
{
  ByteConversion::ValueUnion values {};

  for (int byteNo = 0; byteNo < 2; byteNo++)
    values.byteValues[byteNo] = bytes[byteNo].value;

  return values.twoByteValue;
}

uint16_t ByteConversion::convertTo16BitInt(
  const ByteArray& bytes, int startingIndex)
{
  auto twoBytes = bytes.slice(startingIndex, startingIndex + 2);
  
  return ByteConversion::convertTo16BitInt(twoBytes);
}

uint32_t ByteConversion::convertTo32BitInt(const ByteArray& bytes)
{
  ByteConversion::ValueUnion values {};

  for (int byteNo = 0; byteNo < 4; byteNo++)
    values.byteValues[byteNo] = bytes[byteNo].value;

  return values.fourByteValue;
}

uint32_t ByteConversion::convertTo32BitInt(
  const ByteArray& bytes, int startingIndex)
{
  auto fourBytes = bytes.slice(startingIndex, startingIndex + 4);
   
  return ByteConversion::convertTo32BitInt(fourBytes);
}
