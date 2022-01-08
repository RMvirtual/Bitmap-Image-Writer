#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
#include <string>
#include "src/graphics/bitmaps/packet/headers/header.h"

namespace BitmapHeaders {
class FileHeader : public Header
{
public:
  FileHeader();
  FileHeader(int widthInPixels, int heightInPixels);

  void setSignatureBytes(std::string bytesSignature);
  void setSignatureBytes(char firstSignatureByte, char secondSignatureByte);
  void setSizeOfBitmapFile(uint32_t sizeOfBitmapFile);
  void setReservedBytes(uint32_t reservedBytes);
  void setPixelDataOffset(uint32_t pixelDataOffsetInBytes);
  std::string getSignatureBytes();
  uint32_t getSizeOfBitmapFile();
  uint32_t getReservedBytes();
  uint32_t getPixelDataOffset();
  int getPixelArraySizeInBytes();

private:
  char signatureBytes[2];
  uint32_t sizeOfBitmapFile;
  uint32_t reservedBytes;
  uint32_t pixelDataOffset;

  void initialiseDefaultValues();
};}

#endif