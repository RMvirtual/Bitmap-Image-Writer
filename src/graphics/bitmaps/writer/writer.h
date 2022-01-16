#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"

namespace BitmapWriter {
class ImageWriter
{
public:
  ImageWriter();
  ByteArray convertToBytes(BitmapPacket packet);
  ByteArray convertToBytes(BitmapHeaders::FileHeader header);
  ByteArray convertToBytes(BitmapHeaders::DibHeader header);
  ByteArray convertToBytes(Pixels::PixelArray pixelArray);
  ByteArray convertToBytes(Pixels::RGBPixel pixel);
};}

#endif