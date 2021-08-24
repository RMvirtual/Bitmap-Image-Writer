#include <algorithm>
#include <iostream>

#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
  this->numberOfBytes = 0;
  this->byteArray = new char[1];
}

ByteArrayBuilder::~ByteArrayBuilder()
{
  delete this->byteArray;
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
  char* arrayCopy = new char[this->numberOfBytes];

  char* startOfArray = this->byteArray;
  char* endOfArray = this->byteArray + this->numberOfBytes;

  std::copy(startOfArray, endOfArray, arrayCopy);

  return arrayCopy;
}

void ByteArrayBuilder::addValue(uint8_t value)
{
  if (this->numberOfBytes == 0) {
    this->byteArray[0] = value;
    this->numberOfBytes++;
  }

  else {
    char* newArray = new char[this->numberOfBytes + 1];

    std::copy(
      this->byteArray, this->byteArray + this->numberOfBytes, newArray);

    delete this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->numberOfBytes ++;
  }
}


void ByteArrayBuilder::addValue(uint16_t value)
{
  if (this->numberOfBytes == 0) {
    delete this->byteArray;
    this->byteArray = new char[2];

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += 2;
  }

  else {
    char* newArray = new char[this->numberOfBytes + 2];

    std::copy(
      this->byteArray, this->byteArray + this->numberOfBytes, newArray);

    delete this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;

    this->numberOfBytes += 2;
  }
}


void ByteArrayBuilder::addValue(uint32_t value)
{
  if (this->numberOfBytes == 0) {
    delete this->byteArray;
    this->byteArray = new char[4];

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += 4;
  }

  else {
    char* newArray = new char[this->numberOfBytes + 4];

    std::copy(
      this->byteArray, this->byteArray + this->numberOfBytes, newArray);

    delete this->byteArray;
    this->byteArray = newArray;

    this->byteArray[this->numberOfBytes] = value;
    this->byteArray[this->numberOfBytes + 1] = value >> 8;
    this->byteArray[this->numberOfBytes + 2] = value >> 16;
    this->byteArray[this->numberOfBytes + 3] = value >> 24;

    this->numberOfBytes += 4;
  }
}
