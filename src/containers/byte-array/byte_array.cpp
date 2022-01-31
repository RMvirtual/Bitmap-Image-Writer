#include <cstdint>

#include "src/containers/byte-array/byte_array.h"
#include "src/containers/byte-array/byte_conversion.h"

ByteArray::ByteArray()
{
  // pass.
}

void ByteArray::add(unsigned char value)
{
  this->bytes.push_back(value);
}

void ByteArray::add(const unsigned char* values, int numberOfBytes)
{
  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    this->add(values[byteNo]);
}

void ByteArray::add(uint16_t value)
{ 
  auto newBytes = ByteConversion::toBytes(value, 2);
  this->add(newBytes);
}

void ByteArray::add(uint32_t value)
{
  auto newBytes = ByteConversion::toBytes(value, 4);
  this->add(newBytes);
}

void ByteArray::add(char value)
{
  auto newBytes = ByteConversion::toBytes(value, 1);
  this->add(newBytes);
}

void ByteArray::add(int8_t value)
{
  auto newBytes = ByteConversion::toBytes(value, 1);
  this->add(newBytes);
}

void ByteArray::add(int16_t value)
{
  auto newBytes = ByteConversion::toBytes(value, 2);
  this->add(newBytes);
}

void ByteArray::add(int32_t value)
{
  auto newBytes = ByteConversion::toBytes(value, 4);
  this->add(newBytes);
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

void ByteArray::add(const std::vector<uint8_t>& bytes)
{
  for (uint8_t byte : bytes)
    this->bytes.push_back(byte);
}

uint8_t& ByteArray::operator [] (int index)
{
  return this->bytes[index];
}

uint8_t ByteArray::operator [] (int index) const
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