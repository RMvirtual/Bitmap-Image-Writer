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
    char* array, int startingIndex, uint32_t value);

  void insertTwoByteValueToCharArray(
    char* array, int startingIndex, uint16_t value);
  
  char* getEmptyByteArray();

private:
  int sizeOfHeaderInBytes;
};

#endif