#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
#include <string>
#include "src/graphics/bitmaps/headers/header.h"

class BitmapFileHeader
: public BitmapHeader
{
public:
  BitmapFileHeader();
  BitmapFileHeader(int sizeOfHeaderInBytes);
  BitmapFileHeader(
    int sizeOfHeaderInBytes, int widthInPixels, int heightInPixels);

  char* toBytes();

  void setSignatureBytes(std::string bytesSignature);
  void setSignatureBytes(char firstSignatureByte, char secondSignatureByte);
  void setSizeOfBitmapFile(uint32_t sizeOfBitmapFile);
  void setReservedBytes(uint32_t reservedBytes);
  void setPixelDataOffset(uint32_t pixelDataOffsetInBytes);

  std::string getSignatureBytes();
  uint32_t getSizeOfBitmapFile();
  uint32_t getReservedBytes();
  uint32_t getPixelDataOffset();

private:
  char signatureBytes[2];
  uint32_t sizeOfBitmapFile;
  uint32_t reservedBytes;
  uint32_t pixelDataOffset;

  void initialiseDefaultValues();
  int calculateSizeOfPixelArray(int widthInPixels, int heightInPixels);
};

#endif