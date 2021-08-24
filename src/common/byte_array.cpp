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
  if (this->numberOfBytes == 0) {
    this->byteArray[0] = value;
    this->numberOfBytes++;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + 1);

    delete[] this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->numberOfBytes++;
  }
}

void ByteArrayBuilder::addValue(uint16_t value)
{
  if (this->numberOfBytes == 0) {
    delete[] this->byteArray;
    this->byteArray = this->getEmptyArray(2);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += 2;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + 2);

    delete[] this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += 2;
  }
}


void ByteArrayBuilder::addValue(uint32_t value)
{
  if (this->numberOfBytes == 0) {
    delete[] this->byteArray;
    this->byteArray = this->getEmptyArray(4);

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += 4;
  }

  else {
    char* newArray = this->copyArray(this->numberOfBytes + 4);

    delete[] this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += 4;
  }
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

