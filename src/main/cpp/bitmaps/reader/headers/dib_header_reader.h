#pragma once

#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class DibHeaderReader
{
public:
  DibHeaderReader();
  Bitmaps::DibHeader convertBytes(const ByteArray& bytes);

private:
  Bitmaps::DibHeader header;
  
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