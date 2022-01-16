#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file-header/file_header_values.h"

namespace BitmapHeaders {
class FileHeader
{
public:
  FileHeader();
  FileHeader(int widthInPixels, int heightInPixels);
  static FileHeader fromValues(FileHeaderValues values);

  void setSignatureBytes(std::string bytesSignature);
  void setSignatureBytes(char firstSignatureByte, char secondSignatureByte);
  void setSizeOfBitmapFile(uint32_t sizeOfBitmapFile);
  void setReservedBytes(uint32_t reservedBytes);
  void setPixelDataOffset(uint32_t pixelDataOffsetInBytes);
  std::string getSignatureBytes() const;
  uint32_t getSizeOfBitmapFile() const;
  uint32_t getReservedBytes() const;
  uint32_t getPixelDataOffset() const;
  int getPixelArraySizeInBytes() const;

private:
  char signatureBytes[2];
  uint32_t sizeOfBitmapFile;
  uint32_t reservedBytes;
  uint32_t pixelDataOffset;

  void initialiseDefaultValues();
};}

#endif