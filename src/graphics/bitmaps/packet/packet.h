#ifndef BITMAP_PACKET_H
#define BITMAP_PACKET_H

#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"

struct BitmapPacket
{
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::Array pixelArray;
};

#endif