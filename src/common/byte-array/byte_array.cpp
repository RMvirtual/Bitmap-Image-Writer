#include "src/common/byte-array/byte_array.h"
#include "src/common/byte-array/byte_array_builder.h"

ByteArray::ByteArray()
{
  this->bytes = {};
}

void ByteArray::add(const std::vector<Byte>& bytes)
{
  for (Byte byte : bytes)
    this->bytes.push_back(byte);
}

Byte ByteArray::operator [](int index) const
{
  return this->bytes[index];
}

int ByteArray::size() const
{
  return this->bytes.size();
}

ByteArray ByteArray::slice(int startIndex, int endIndex) const
{
  ByteArrayBuilder byteArrayBuilder;

  for (int index = startIndex; index < endIndex; index++) 
    byteArrayBuilder.add(this->bytes[index].value);
 
  return byteArrayBuilder.toByteArray();
}