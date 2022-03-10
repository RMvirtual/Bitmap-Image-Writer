#pragma once

#include <memory>
#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class FileHeaderReader
{
public:
  FileHeaderReader();
  std::shared_ptr<Bitmaps::FileHeader> convertBytes(const ByteArray& bytes);

private:
  std::shared_ptr<Bitmaps::FileHeader> fileHeader;
  
  void parseSignatureBytes(const ByteArray& bytes);
  void parseSizeOfBitmapFile(const ByteArray& bytes);
  void parseReservedBytes(const ByteArray& bytes);
  void parsePixelDataOffset(const ByteArray& bytes);
};}