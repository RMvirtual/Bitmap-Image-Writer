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
  char* array, int from, int to, uint32_t value)
{
  array[from] = value;
  array[from + 1] = value >> 8;
  array[from + 2] = value >> 16;
  array[from + 3] = value >> 24;
}