#ifndef BITMAP_DIB_HEADER_READER_H
#define BITMAP_DIB_HEADER_READER_H

#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/common/byte-array/byte_array.h"

class DibHeaderReader
{
public:
  DibHeaderReader();
  BitmapHeaders::DibHeader convertBytes(ByteArray bytes);

private:
  BitmapHeaders::DibHeader header;
  
  void parseWidthInPixels(ByteArray bytes);
  void parseHeightInPixels(ByteArray bytes);
  void parseNumberOfColourPlanes(ByteArray bytes);
  void parseColourDepth(ByteArray bytes);
  void parseCompressionMethod(ByteArray bytes);
  void parseRawBitmapDataSize(ByteArray bytes);
  void parseHorizontalPixelsPerMetre(ByteArray bytes);
  void parseVerticalPixelsPerMetre(ByteArray bytes);
  void parseColourTableEntries(ByteArray bytes);
  void parseImportantColours(ByteArray bytes);
};

#endif