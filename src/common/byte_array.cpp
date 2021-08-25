#include <cstdint>
#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->numberOfBytes = 0;
  this->byteVector = {};
}

void ByteArrayBuilder::addValue(char value)
{
  int lengthInBytes = sizeof(uint8_t);
  this->processNewValue((uint8_t) value, lengthInBytes);
}

void ByteArrayBuilder::addValue(uint8_t value)
{
  int lengthInBytes = sizeof(uint8_t);
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::addValue(int8_t value)
{
  int lengthInBytes = sizeof(int8_t);
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::addValue(uint16_t value)
{
  int lengthInBytes = sizeof(uint16_t); 
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::addValue(int16_t value)
{
  int lengthInBytes = sizeof(int16_t);
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::addValue(uint32_t value)
{
  int lengthInBytes = sizeof(uint32_t);
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::addValue(int32_t value)
{
  int lengthInBytes = sizeof(int32_t);
  this->processNewValue(value, lengthInBytes);
}

void ByteArrayBuilder::processNewValue(int value, int lengthInBytes)
{
  this->convertValueToBytes(value, lengthInBytes);
  this->numberOfBytes += lengthInBytes;
}

void ByteArrayBuilder::convertValueToBytes(int value, int lengthInBytes)
{
  for (int byteNo = 0; byteNo < lengthInBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    uint8_t valueToAdd = value >> bitsToShift;
    
    this->byteVector.push_back(valueToAdd);
  }
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