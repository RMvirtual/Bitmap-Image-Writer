#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
#include <string>
#include "src/graphics/bitmaps/headers/header.h"

class BitmapFileHeader
: public BitmapHeader
{
public:
  BitmapFileHeader(int sizeOfHeaderInBytes);
  BitmapFileHeader(
    int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels);

  char* toBytes();

  void setSignatureBytes(std::string bytesSignature);

  char bitmapSignatureBytes[2];
  uint32_t sizeOfBitmapFile;
  uint32_t reservedBytes;
  uint32_t pixelDataOffset;
};

#endif