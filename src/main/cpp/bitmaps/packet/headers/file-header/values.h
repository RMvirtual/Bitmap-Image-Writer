#pragma once

#include <string>

namespace Bitmaps {
struct FileHeaderValues
{
  std::string signatureBytes;
  int fileSize;
  int reservedBytes;
  int pixelDataOffsetInBytes;
};}