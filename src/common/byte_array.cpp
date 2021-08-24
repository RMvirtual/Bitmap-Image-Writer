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
  delete[] this->byteArray;
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

  for (int byteNo = 0; byteNo < this->numberOfBytes; byteNo++)
    arrayCopy[byteNo] = this->byteArray[byteNo];

  return arrayCopy;
}

void ByteArrayBuilder::addFourByteValueToCharArray(uint32_t value)
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
