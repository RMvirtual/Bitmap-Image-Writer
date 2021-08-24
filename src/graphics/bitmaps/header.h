#ifndef BITMAP_HEADER_H
#define BITMAP_HEADER_H

#include <cstdint>

class BitmapHeader
{
public:
  BitmapHeader(int sizeOfHeaderInBytes);
  virtual char* toBytes() = 0;
  int getSizeOfHeaderInBytes();

private:
  int sizeOfHeaderInBytes;
};

#endif