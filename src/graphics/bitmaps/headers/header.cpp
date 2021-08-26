#include "src/graphics/bitmaps/headers/header.h"

BitmapHeader::BitmapHeader(int sizeOfHeaderInBytes)
{
  this->sizeOfHeaderInBytes = sizeOfHeaderInBytes;
}

int BitmapHeader::getSizeOfHeaderInBytes()
{
  return this->sizeOfHeaderInBytes;
}

void BitmapHeader::setSizeOfHeaderInBytes(int size)
{
  this->sizeOfHeaderInBytes = size;
}