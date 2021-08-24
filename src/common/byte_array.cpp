#include <algorithm>
#include <iostream>

#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->numberOfBytes = 0;
  this->byteArray = new char[1] {0};
}

ByteArrayBuilder::~ByteArrayBuilder()
{
  delete[] this->byteArray;
}

void ByteArrayBuilder::addValue(uint8_t value)
{
  int sizeInBytesToAdd = sizeof(uint8_t);

  if (this->numberOfBytes == 0) {
    this->insertValue(0, value);
    this->numberOfBytes += sizeInBytesToAdd;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + sizeInBytesToAdd);

    this->replaceArray(newArray);
    this->byteArray[this->numberOfBytes] = value;
    this->numberOfBytes += sizeInBytesToAdd;
  }
}

void ByteArrayBuilder::addValue(uint16_t value)
{
  int sizeInBytesToAdd = sizeof(uint16_t);

  if (this->numberOfBytes == 0) {
    delete[] this->byteArray;
    this->byteArray = this->getEmptyArray(sizeInBytesToAdd);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += sizeInBytesToAdd;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + sizeInBytesToAdd);
    this->replaceArray(newArray);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += sizeInBytesToAdd;
  }
}

void ByteArrayBuilder::addValue(uint32_t value)
{
  int sizeInBytesToAdd = sizeof(uint32_t);

  if (this->numberOfBytes == 0) {
    delete[] this->byteArray;
    this->byteArray = this->getEmptyArray(sizeInBytesToAdd);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += sizeInBytesToAdd;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + sizeInBytesToAdd);

    this->replaceArray(newArray);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += sizeInBytesToAdd;
  }
}

void ByteArrayBuilder::insertValue(int byteIndex, uint8_t value)
{
  this->byteArray[byteIndex] = value;
}

void ByteArrayBuilder::insertValue(int byteIndex, uint16_t value)
{
  
}

void ByteArrayBuilder::insertValue(int byteIndex, uint32_t value)
{
  
}


int ByteArrayBuilder::getNumberOfBytes()
{
  return this->numberOfBytes;
}

char* ByteArrayBuilder::toArray()
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
  this->copyArrayContents(arrayCopy);

  return arrayCopy;
}

void ByteArrayBuilder::copyArrayContents(char* destinationArray)
{
  char* startOfArray = this->byteArray;
  char* endOfArray = this->byteArray + this->numberOfBytes;

  std::copy(startOfArray, endOfArray, destinationArray); 
}

char* ByteArrayBuilder::getEmptyArray(int size)
{
  char* newArray = new char[size];

  for (int byteNo = 0; byteNo < size; byteNo++)
    newArray[byteNo] = 0;

  return newArray;
}

void ByteArrayBuilder::replaceArray(char* newArray)
{
  delete[] this->byteArray;
  this->byteArray = newArray; 
}