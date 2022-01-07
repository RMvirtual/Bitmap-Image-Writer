#ifndef BITMAP_PACKET_H
#define BITMAP_PACKET_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

struct BitmapPacket
{
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::PixelArray pixelArray;
};

#endif