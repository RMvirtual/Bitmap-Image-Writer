#include "src/common/byte-array/byte_array.h"
#include "src/common/byte-array/byte_array_builder.h"

ByteArray::ByteArray()
{
  this->bytes = {};
}

void ByteArray::add(std::vector<Byte> bytes)
{
  for (Byte byte : bytes)
    this->bytes.push_back(byte);
}

Byte ByteArray::operator [](int index)
{
  return this->bytes[index];
}

int ByteArray::size()
{
  return this->bytes.size();
}

ByteArray ByteArray::slice(int startIndex, int endIndex)
{
  ByteArrayBuilder byteArrayBuilder;

  for (int index = startIndex; index <= endIndex; index++) 
    byteArrayBuilder.add(this->bytes[index].value);
 
  return byteArrayBuilder.toByteArray();
}