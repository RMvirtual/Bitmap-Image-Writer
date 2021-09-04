#include "src/graphics/bitmaps/packet/headers/header.h"

BitmapHeaders::Header::Header()
{
  this->sizeOfHeaderInBytes = 0;
}

BitmapHeaders::Header::Header(int sizeOfHeaderInBytes)
{
  this->sizeOfHeaderInBytes = sizeOfHeaderInBytes;
}

int BitmapHeaders::Header::getSizeOfHeaderInBytes()
{
  return this->sizeOfHeaderInBytes;
}

void BitmapHeaders::Header::setSizeOfHeaderInBytes(int size)
{
  this->sizeOfHeaderInBytes = size;
}