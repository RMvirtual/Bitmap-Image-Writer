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
  std::string signatureBytes() const;
  uint32_t sizeOfBitmapFile() const;
  uint32_t reservedBytes() const;
  uint32_t pixelDataOffset() const;
  int pixelArraySizeInBytes() const;

private:
  char signatureBytesValue[2];
  uint32_t sizeOfBitmapFileInBytes;
  uint32_t reservedBytesValue;
  uint32_t pixelDataOffsetInBytes;

  void initialiseDefaultValues();
};}

#endif