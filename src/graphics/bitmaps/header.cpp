#include "src/graphics/bitmaps/header.h"
#include <cstdint>

BitmapHeader::BitmapHeader(int sizeOfHeaderInBytes)
{
  this->sizeOfHeaderInBytes = sizeOfHeaderInBytes;
}

int BitmapHeader::getSizeOfHeaderInBytes()
{
  return this->sizeOfHeaderInBytes;
}

void BitmapHeader::insertFourByteValueToCharArray(
  char* array, int startingIndex, uint32_t value)
{
  array[startingIndex] = value;
  array[startingIndex + 1] = value >> 8;
  array[startingIndex + 2] = value >> 16;
  array[startingIndex + 3] = value >> 24;
}

void BitmapHeader::insertTwoByteValueToCharArray(
  char* array, int startingIndex, uint16_t value)
{
  array[startingIndex] = value;
  array[startingIndex + 1] = value >> 8;
}

char* BitmapHeader::getEmptyByteArray()
{
  int size = this->getSizeOfHeaderInBytes();
  char* byteArray = new char[size];

  /* Initialise empty values in array instead of random uninitialised
  values. */
  for (int i = 0; i < size; i++)
    byteArray[i] = 0;

  return byteArray;
}