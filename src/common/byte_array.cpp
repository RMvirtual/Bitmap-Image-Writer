#include <algorithm>
#include <iostream>

#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->numberOfBytes = 0;
  this->byteVector = {};
}

void ByteArrayBuilder::addValue(uint8_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(uint8_t);
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::addValue(int8_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(int8_t);
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::addValue(uint16_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(uint16_t); 
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::addValue(int16_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(int16_t);
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::addValue(uint32_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(uint32_t);
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::addValue(int32_t value)
{
  this->appendValueToVector(value);

  int sizeInBytesToAdd = sizeof(int32_t);
  this->numberOfBytes += sizeInBytesToAdd;
}

void ByteArrayBuilder::appendValueToVector(uint8_t value)
{
  this->byteVector.push_back(value);
}

void ByteArrayBuilder::appendValueToVector(int8_t value)
{
  this->byteVector.push_back(value);
}

void ByteArrayBuilder::appendValueToVector(uint16_t value)
{
  int bytesToOverwrite = sizeof(uint16_t);

  this->byteVector.push_back(value);
  this->byteVector.push_back(value >> 8);
}

void ByteArrayBuilder::appendValueToVector(int16_t value)
{
  int bytesToOverwrite = sizeof(int16_t);

  this->byteVector.push_back(value);
  this->byteVector.push_back(value >> 8);
}

void ByteArrayBuilder::appendValueToVector(uint32_t value)
{
  int bytesToOverwrite = sizeof(uint32_t);

  this->byteVector.push_back(value);
  this->byteVector.push_back(value >> 8);
  this->byteVector.push_back(value >> 16);
  this->byteVector.push_back(value >> 24);
}

void ByteArrayBuilder::appendValueToVector(int32_t value)
{
  int bytesToOverwrite = sizeof(int32_t);

  this->byteVector.push_back(value);
  this->byteVector.push_back(value >> 8);
  this->byteVector.push_back(value >> 16);
  this->byteVector.push_back(value >> 24);
}

int ByteArrayBuilder::getNumberOfBytes()
{
  return this->numberOfBytes;
}

char* ByteArrayBuilder::toBytes()
{
  char* arrayCopy = this->copyArray();

  return arrayCopy;
}

char* ByteArrayBuilder::copyArray()
{
  char* arrayCopy = this->copyArray(this->numberOfBytes);

  return arrayCopy;
}

char* ByteArrayBuilder::copyArray(int newSizeInBytes)
{
  char* arrayCopy = this->getEmptyArray(newSizeInBytes);
  this->copyVectorToArray(arrayCopy);

  return arrayCopy;
}

void ByteArrayBuilder::copyVectorToArray(char* destinationArray)
{
  int i = 0;

  for (auto value : this->byteVector) {
    destinationArray[i] = value;
    i++;
  }
}

char* ByteArrayBuilder::getEmptyArray(int size)
{
  char* emptyArray = new char[size];

  for (int byteNo = 0; byteNo < size; byteNo++)
    emptyArray[byteNo] = 0;

  return emptyArray;
}
