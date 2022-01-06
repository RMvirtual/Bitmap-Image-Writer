#ifndef BITMAP_IMAGE_HEADERS_H
#define BITMAP_IMAGE_HEADERS_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

struct BitmapImageHeaders
{
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::PixelArray pixelArray;
};

#endif