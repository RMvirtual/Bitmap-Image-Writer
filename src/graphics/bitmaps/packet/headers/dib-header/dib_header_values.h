#ifndef BITMAP_DIB_HEADER_VALUES_H
#define BITMAP_DIB_HEADER_VALUES_H

namespace BitmapHeaders {
struct DibHeaderValues
{
  int headerSizeInBytes;
  int widthInPixels;
  int heightInPixels;
  int numberOfColorPlanes;
  int colorDepth;
  int compressionMethod;
  int rawBitmapDataSize;
  int horizontalPixelsPerMetre;
  int verticalPixelsPerMetre;
  int colorTableEntries;
  int importantColors;
};}

#endif