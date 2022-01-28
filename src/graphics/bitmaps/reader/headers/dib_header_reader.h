#ifndef BITMAP_DIB_HEADER_READER_H
#define BITMAP_DIB_HEADER_READER_H

#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/common/byte-array/byte_array.h"

namespace BitmapReader {
class DibHeaderReader
{
public:
  DibHeaderReader();
  BitmapHeaders::DibHeader convertBytes(const ByteArray& bytes);

private:
  BitmapHeaders::DibHeader header;
  
  void parseWidthInPixels(const ByteArray& bytes);
  void parseHeightInPixels(const ByteArray& bytes);
  void parseNumberOfColourPlanes(const ByteArray& bytes);
  void parseColourDepth(const ByteArray& bytes);
  void parseCompressionMethod(const ByteArray& bytes);
  void parseRawBitmapDataSize(const ByteArray& bytes);
  void parseHorizontalResolution(const ByteArray& bytes);
  void parseVerticalResolution(const ByteArray& bytes);
  void parseColourTableEntries(const ByteArray& bytes);
  void parseImportantColours(const ByteArray& bytes);
};}

#endif