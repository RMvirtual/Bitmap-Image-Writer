#pragma once

#include <cstdint>
#include <string>

#include "src/main/cpp/bitmaps/packet/headers/file-header/values.h"

namespace Bitmaps {
class FileHeader
{
public:
  FileHeader();
  FileHeader(int pixelArraySizeInBytes);
  static FileHeader fromValues(const Bitmaps::FileHeaderValues& values);

  void setSignatureBytes(const std::string& bytesSignature);
  void setSignatureBytes(char firstSignatureByte, char secondSignatureByte);
  void setFileSizeInBytes(uint32_t sizeOfBitmapFile);
  void setReservedBytes(uint32_t reservedBytes);
  void setPixelArrayOffsetInBytes(uint32_t pixelDataOffsetInBytes);
  std::string signatureBytes() const;
  uint32_t fileSizeInBytes() const;
  uint32_t reservedBytes() const;
  uint32_t pixelArrayOffsetInBytes() const;
  int pixelArraySizeInBytes() const;

private:
  char _signatureBytes[2];
  uint32_t _fileSizeInBytes;
  uint32_t _reservedBytes;
  uint32_t _pixelArrayOffsetInBytes;

  void initialiseDefaultValues();
};}