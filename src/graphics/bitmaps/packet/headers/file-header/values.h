#ifndef BITMAP_FILE_HEADER_VALUES_H
#define BITMAP_FILE_HEADER_VALUES_H

#include <string>

namespace Bitmaps {
struct FileHeaderValues
{
  std::string signatureBytes;
  int fileSize;
  int reservedBytes;
  int pixelDataOffsetInBytes;
};}

#endif