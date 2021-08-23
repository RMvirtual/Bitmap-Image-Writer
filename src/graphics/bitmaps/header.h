#ifndef BITMAP_HEADER_H
#define BITMAP_HEADER_H

#include <cstdint>

class BitmapHeader
{
public:
  BitmapHeader(int sizeOfHeaderInBytes);
  virtual char* toBytes() = 0;
  int getSizeOfHeaderInBytes();

protected:
  void insertFourByteValueToCharArray(
    char* array, int from, int to, uint32_t value);

private:
  int sizeOfHeaderInBytes;
};

#endif