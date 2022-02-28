#pragma once

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