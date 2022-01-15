#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"

class BitmapWriter
{
public:
  BitmapWriter();
  ByteArray writeFileHeader(BitmapHeaders::FileHeader header);
  ByteArray writeDibHeader(BitmapHeaders::DibHeader header);
  ByteArray writePixelArray(Pixels::PixelArray pixelArray);
  ByteArray writePixel(Pixels::RGBPixel pixel);
};

#endif