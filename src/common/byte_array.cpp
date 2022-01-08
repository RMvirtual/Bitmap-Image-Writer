#include "src/common/byte_array.h"

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