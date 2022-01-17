#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/rgb_bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"

namespace BitmapWriter {
class ImageWriter
{
public:
  ImageWriter();
  ByteArray convertToBytes(const RGBBitmapPacket& packet);
  ByteArray convertToBytes(const BitmapHeaders::FileHeader& header);
  ByteArray convertToBytes(const BitmapHeaders::DibHeader& header);
  ByteArray convertToBytes(const Pixels::RGBPixelArray& pixelArray);
  ByteArray convertToBytes(const Pixels::RGBPixel& pixel);
};}

#endif