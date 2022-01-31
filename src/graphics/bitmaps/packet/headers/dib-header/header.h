#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include <cstdint>
#include "src/graphics/bitmaps/packet/headers/dib-header/values.h"

namespace Bitmaps {
class DibHeader
{
public:
  DibHeader();
  DibHeader(int widthInPixels, int heightInPixels);
  static DibHeader fromValues(const DibHeaderValues& values);

  void setWidthInPixels(int32_t widthInPixels);
  void setHeightInPixels(int32_t heightInPixels);
  void setNumberOfColourPlanes(uint16_t numberOfColorPlanes);
  void setBitsPerPixel(uint16_t colorDepth);
  void setCompressionMethod(uint32_t compressionMethod);
  void setSizeOfPixelArray(uint32_t rawBitmapDataSize);
  void setHorizontalResolution(int32_t pixelsPerMetre);
  void setVerticalResolution(int32_t pixelsPerMetre);
  void setColorTableEntries(uint32_t colorTableEntries);
  void setImportantColours(uint32_t importantColors);
  int headerSizeInBytes() const;
  int32_t widthInPixels() const;
  int32_t heightInPixels() const;
  uint16_t numberOfColorPlanes() const;
  uint16_t bitsPerPixel() const;
  uint32_t compressionMethod() const;
  uint32_t sizeOfPixelArray() const;
  int32_t horizontalResolution() const;
  int32_t verticalResolution() const;
  uint32_t colorTableEntries() const;
  uint32_t importantColors() const;

private:
  int32_t _widthInPixels;
  int32_t _heightInPixels;
  uint16_t _numberOfColorPlanes;
  uint16_t _bitsPerPixel;
  uint32_t _compressionMethod;
  uint32_t _sizeOfPixelArray; 
  int32_t _horizontalResolution;
  int32_t _verticalResolution;
  uint32_t _colorTableEntries;
  uint32_t _importantColors;

  void initialiseDefaultValues();
};}

#endif