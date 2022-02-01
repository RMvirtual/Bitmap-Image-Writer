#ifndef BITMAP_DIB_HEADER_VALUES_H
#define BITMAP_DIB_HEADER_VALUES_H

namespace Bitmaps {
struct DibHeaderValues
{
  int headerSizeInBytes;
  int widthInPixels;
  int heightInPixels;
  int numberOfColorPlanes;
  int bitsPerPixel;
  int compressionMethod;
  int pixelArraySizeInBytes;
  int horizontalResolution;
  int verticalResolution;
  int colorTableEntries;
  int importantColors;
};}

#endif