#ifndef BITMAP_PACKET_H
#define BITMAP_PACKET_H

#include "src/main/bitmaps/packet/headers/file-header/header.h"
#include "src/main/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/bitmaps/packet/pixel-array/array.h"

namespace Bitmaps {
struct Packet
{
  FileHeader fileHeader;
  DibHeader dibHeader;
  PixelArray pixelArray;
};}

#endif