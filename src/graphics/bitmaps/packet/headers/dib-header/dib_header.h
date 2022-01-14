#ifndef BITMAP_INFO_HEADER_H
#define BITMAP_INFO_HEADER_H

#include <cstdint>
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header_values.h"

namespace BitmapHeaders {
class DibHeader
{
public:
  DibHeader();
  DibHeader(int widthInPixels, int heightInPixels);
  static DibHeader fromValues(DibHeaderValues values);

  void setWidthInPixels(int32_t widthInPixels);
  void setHeightInPixels(int32_t heightInPixels);
  void setNumberOfColourPlanes(uint16_t numberOfColorPlanes);
  void setColorDepth(uint16_t colorDepth);
  void setCompressionMethod(uint32_t compressionMethod);
  void setRawBitmapDataSize(uint32_t rawBitmapDataSize);
  void setHorizontalPixelsPerMetre(int32_t horizontalPixelsPerMetre);
  void setVerticalPixelsPerMetre(int32_t horizontalPixelsPerMetre);
  void setColorTableEntries(uint32_t colorTableEntries);
  void setImportantColours(uint32_t importantColors);
  int getHeaderSizeInBytes();
  int32_t getWidthInPixels();
  int32_t getHeightInPixels();
  uint16_t getNumberOfColorPlanes();
  uint16_t getColorDepth();
  uint32_t getCompressionMethod();
  uint32_t getRawBitmapDataSize();
  int32_t getHorizontalPixelsPerMetre();
  int32_t getVerticalPixelsPerMetre();
  uint32_t getColorTableEntries();
  uint32_t getImportantColors();

private:
  int32_t widthInPixels;
  int32_t heightInPixels;
  uint16_t numberOfColorPlanes;
  uint16_t colorDepth;
  uint32_t compressionMethod;
  uint32_t rawBitmapDataSize; 
  int32_t horizontalPixelsPerMetre;
  int32_t verticalPixelsPerMetre;
  uint32_t colorTableEntries;
  uint32_t importantColors;

  void initialiseDefaultValues();
};}

#endif