#ifndef BITMAP_FILE_HEADER_READER_H
#define BITMAP_FILE_HEADER_READER_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/common/byte-array/byte_array.h"

class FileHeaderReader
{
public:
  FileHeaderReader();
  BitmapHeaders::FileHeader convertBytes(ByteArray bytes);

private:
  BitmapHeaders::FileHeader fileHeader;
  
  void parseSignatureBytes(ByteArray bytes);
  void parseSizeOfBitmapFile(ByteArray bytes);
  void parseReservedBytes(ByteArray bytes);
  void parsePixelDataOffset(ByteArray bytes);
};

#endif