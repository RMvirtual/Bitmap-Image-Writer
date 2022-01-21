#ifndef RGB_BITMAP_PACKET_H
#define RGB_BITMAP_PACKET_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb_colours.h"

struct BitmapPacket
{
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::PixelArray<Pixels::Pixel<Pixels::RGBColours>> pixelArray;
};

#endif