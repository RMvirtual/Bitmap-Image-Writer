#include "src/common/byte-array/bytes_conversion.h"
#include "src/common/byte-array/byte_array.h"

uint32_t BytesConversion::get32BitInteger(ByteArray bytes, int startingIndex)
{
  ByteArray fourBytes = bytes.slice(startingIndex, startingIndex + 4);
   
  return BytesConversion::convertTo32bitInteger(fourBytes);
}

uint16_t BytesConversion::get16BitInteger(ByteArray bytes, int startingIndex)
{
  ByteArray twoBytes = bytes.slice(startingIndex, startingIndex + 2);
  
  return BytesConversion::convertTo16bitInteger(twoBytes);
}

uint32_t BytesConversion::convertTo32bitInteger(ByteArray bytes)
{
  BytesConversion::ValueUnion values {};

  for (int byteNo = 0; byteNo < 4; byteNo++)
    values.byteValues[byteNo] = bytes[byteNo].value;

  return values.fourByteValue;
}

uint16_t BytesConversion::convertTo16bitInteger(ByteArray bytes)
{
  BytesConversion::ValueUnion values {};

  for (int byteNo = 0; byteNo < 2; byteNo++)
    values.byteValues[byteNo] = bytes[byteNo].value;

  return values.twoByteValue;
}