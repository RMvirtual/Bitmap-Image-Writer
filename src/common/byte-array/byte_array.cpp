#include "src/common/byte-array/byte_array.h"
#include "src/common/byte-array/byte_conversion.h"

ByteArray::ByteArray()
{
  this->bytes = {};
}

void ByteArray::add(char value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 1);
  this->add(newBytes);
}

void ByteArray::add(unsigned char value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 1);
  this->add(newBytes);
}

void ByteArray::add(const unsigned char* values, int numberOfBytes)
{
  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    this->add(values[byteNo]);
}

void ByteArray::add(int8_t value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 1);
  this->add(newBytes);
}

void ByteArray::add(uint16_t value)
{ 
  auto newBytes = ByteConversion::convertToBytes(value, 2);
  this->add(newBytes);
}

void ByteArray::add(int16_t value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 2);
  this->add(newBytes);
}

void ByteArray::add(uint32_t value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 4);
  this->add(newBytes);
}

void ByteArray::add(int32_t value)
{
  auto newBytes = ByteConversion::convertToBytes(value, 4);
  this->add(newBytes);
}

void ByteArray::add(const Byte& byte)
{
  this->bytes.push_back(byte);
}

void ByteArray::add(const std::string& values)
{
  int numberOfValues = values.length();
  const char* valuesAsChars {values.c_str()};

  for (int byteNo = 0; byteNo < numberOfValues; byteNo++)
    this->add(valuesAsChars[byteNo]);
}

void ByteArray::add(const ByteArray& byteArray)
{
  int numberOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    this->bytes.push_back(byteArray[byteNo]);
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
  ByteArray bytesSubset {};

  for (int index = startIndex; index < endIndex; index++) 
    bytesSubset.add(this->bytes[index]);
 
  return bytesSubset;
}