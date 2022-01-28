#ifndef BITMAP_FILE_HEADER_READER_H
#define BITMAP_FILE_HEADER_READER_H

#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/common/byte-array/byte_array.h"

namespace BitmapReader {
class FileHeaderReader
{
public:
  FileHeaderReader();
  BitmapHeaders::FileHeader convertBytes(const ByteArray& bytes);

private:
  BitmapHeaders::FileHeader fileHeader;
  
  void parseSignatureBytes(const ByteArray& bytes);
  void parseSizeOfBitmapFile(const ByteArray& bytes);
  void parseReservedBytes(const ByteArray& bytes);
  void parsePixelDataOffset(const ByteArray& bytes);
};}

#endif