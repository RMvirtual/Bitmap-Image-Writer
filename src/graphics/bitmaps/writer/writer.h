#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

class BitmapWriter
{
public:
  BitmapWriter();
  ByteArray writeFileHeader(BitmapHeaders::FileHeader header);
  ByteArray writeDibHeader(BitmapHeaders::DibHeader header);
  ByteArray writePixelArray(Pixels::PixelArray pixelArray);
  ByteArray writePixel(Pixels::Pixel pixel);
};

#endif