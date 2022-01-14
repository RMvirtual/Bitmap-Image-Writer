#include <cstdint>
#include <string>

#include "src/common/byte-array/byte.h"
#include "src/common/byte-array/byte_array_builder.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->bytes = {};
}

void ByteArrayBuilder::add(char value)
{
  this->processNewValue(value, 1);
}

void ByteArrayBuilder::add(unsigned char value)
{
  this->processNewValue(value, 1);
}

void ByteArrayBuilder::add(unsigned char* values, int numberOfBytes)
{
  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    this->add(values[byteNo]);
}

void ByteArrayBuilder::add(int8_t value)
{
  this->processNewValue(value, 1);
}

void ByteArrayBuilder::add(uint16_t value)
{ 
  this->processNewValue(value, 2);
}

void ByteArrayBuilder::add(int16_t value)
{
  this->processNewValue(value, 2);
}

void ByteArrayBuilder::add(uint32_t value)
{
  this->processNewValue(value, 4);
}

void ByteArrayBuilder::add(int32_t value)
{
  this->processNewValue(value, 4);
}

void ByteArrayBuilder::add(std::string values)
{
  int numberOfValues = values.length();
  const char* valuesAsChars {values.c_str()};

  for (int byteNo = 0; byteNo < numberOfValues; byteNo++)
    this->add(valuesAsChars[byteNo]);
}

void ByteArrayBuilder::add(ByteArray byteArray)
{
  int numberOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    this->bytes.push_back(byteArray[byteNo]);
}

void ByteArrayBuilder::processNewValue(int value, int lengthInBytes)
{
  this->convertValueToBytes(value, lengthInBytes);
}

void ByteArrayBuilder::convertValueToBytes(
  unsigned int value, int lengthInBytes)
{
  for (int byteNo = 0; byteNo < lengthInBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    Byte valueToAdd = {value >> bitsToShift};
    
    this->bytes.push_back(valueToAdd);
  }
}

ByteArray ByteArrayBuilder::toByteArray()
{
  ByteArray byteArray {};
  byteArray.add(this->bytes);

  return byteArray;
}

unsigned char* ByteArrayBuilder::toBytes()
{
  return this->copyArray();
}

unsigned char* ByteArrayBuilder::copyArray()
{
  unsigned char* arrayCopy = this->getEmptyArray();
  int numberOfBytes = this->bytes.size();

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++) {
    Byte byte = this->bytes[byteNo];
    arrayCopy[byteNo] = byte.value;
  }

  return arrayCopy;
}

unsigned char* ByteArrayBuilder::getEmptyArray()
{
  int sizeOfArray = this->bytes.size();
  unsigned char* emptyArray = new unsigned char[sizeOfArray];

  for (int byteNo = 0; byteNo < sizeOfArray; byteNo++)
    emptyArray[byteNo] = 0;

  return emptyArray;
}

int ByteArrayBuilder::getNumberOfBytes()
{
  return this->bytes.size();
}