#include <algorithm>
#include <iostream>

#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->numberOfBytes = 0;
  this->byteVector = {};
}

void ByteArrayBuilder::addValue(char value)
{
  this->appendValueToVector((uint8_t) value);

  int sizeInBytesToAdd = sizeof(uint8_t);
  this->numberOfBytes += sizeInBytesToAdd;
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
  this->byteVector.push_back(value >> 0);
}

void ByteArrayBuilder::appendValueToVector(int8_t value)
{
  this->byteVector.push_back(value >> 0);
}

void ByteArrayBuilder::appendValueToVector(uint16_t value)
{
  int bytesToOverwrite = sizeof(uint16_t);

  for (int byteNo = 0; byteNo < bytesToOverwrite; byteNo++) {
    uint8_t valueToAdd = value >> byteNo * 8;
    this->byteVector.push_back(valueToAdd);
  }

  /*
  this->byteVector.push_back(value >> 0);
  this->byteVector.push_back(this->rightBitShiftValue(value, 8));
  */
}

void ByteArrayBuilder::appendValueToVector(int16_t value)
{
  int bytesToOverwrite = sizeof(int16_t);

  for (int byteNo = 0; byteNo < bytesToOverwrite; byteNo++) {
    uint8_t valueToAdd = value >> byteNo * 8;
    this->byteVector.push_back(valueToAdd);
  }

  /*
  this->byteVector.push_back(value >> 0);
  this->byteVector.push_back(this->rightBitShiftValue(value, 8));
  */
}

void ByteArrayBuilder::appendValueToVector(uint32_t value)
{
  int bytesToOverwrite = sizeof(uint32_t);

  for (int byteNo = 0; byteNo < bytesToOverwrite; byteNo++) {
    uint8_t valueToAdd = value >> byteNo * 8;
    this->byteVector.push_back(valueToAdd);
  }

  /*
  this->byteVector.push_back(value >> 0);
  this->byteVector.push_back(this->rightBitShiftValue(value, 8));
  this->byteVector.push_back(this->rightBitShiftValue(value, 16));
  this->byteVector.push_back(this->rightBitShiftValue(value, 24));
  */
}

void ByteArrayBuilder::appendValueToVector(int32_t value)
{
  int bytesToOverwrite = sizeof(int32_t);

  for (int byteNo = 0; byteNo < bytesToOverwrite; byteNo++) {
    uint8_t valueToAdd = value >> byteNo * 8;
    this->byteVector.push_back(valueToAdd);
  }

  /*
  this->byteVector.push_back(value >> 0);
  this->byteVector.push_back(this->rightBitShiftValue(value, 8));
  this->byteVector.push_back(this->rightBitShiftValue(value, 16));
  this->byteVector.push_back(this->rightBitShiftValue(value, 24));
  */
}

char* ByteArrayBuilder::toBytes()
{
  char* arrayCopy = this->copyArray();

  return arrayCopy;
}

char* ByteArrayBuilder::copyArray()
{
  char* arrayCopy = this->getEmptyArray(this->numberOfBytes);
  this->copyVectorToArray(arrayCopy);

  return arrayCopy;
}

void ByteArrayBuilder::copyVectorToArray(char* destinationArray)
{
  for (int byteNo = 0; byteNo < this->numberOfBytes; byteNo++) {
    char value = this->byteVector[byteNo];
    destinationArray[byteNo] = value;
  }
}

char* ByteArrayBuilder::getEmptyArray(int size)
{
  char* emptyArray = new char[size];

  for (int byteNo = 0; byteNo < size; byteNo++)
    emptyArray[byteNo] = 0;

  return emptyArray;
}

int ByteArrayBuilder::getNumberOfBytes()
{
  return this->numberOfBytes;
}

int ByteArrayBuilder::rightBitShiftValue(int value, int numberOfBits)
{
  return value >> numberOfBits;
}
