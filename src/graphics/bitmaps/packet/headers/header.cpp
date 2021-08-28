#include "src/graphics/bitmaps/packet/headers/header.h"

BitmapHeader::BitmapHeader()
{
  this->sizeOfHeaderInBytes = 0;
}

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