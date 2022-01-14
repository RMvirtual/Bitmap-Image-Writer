#ifndef BITMAP_PACKET_H
#define BITMAP_PACKET_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"

struct BitmapPacket
{
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::PixelArray pixelArray;
};

#endif