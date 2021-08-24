#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
#include "src/graphics/bitmaps/header.h"

// 14 bytes total.
class BitmapFileHeader
: public BitmapHeader
{
public:
  BitmapFileHeader(
    int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels);

  char* toBytes();

private:
  char bitmapSignatureBytes[2];
  uint32_t sizeOfBitmapFile;
  uint32_t reservedBytes;
  uint32_t pixelDataOffset;
};

#endif