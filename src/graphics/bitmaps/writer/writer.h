#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"

namespace BitmapWriter {
class ImageWriter
{
public:
  ImageWriter();
  ByteArray convertToBytes(const BitmapPacket& packet);
  ByteArray convertToBytes(const BitmapHeaders::FileHeader& header);
  ByteArray convertToBytes(const BitmapHeaders::DibHeader& header);
  ByteArray convertToBytes(const Pixels::PixelArray& pixelArray);
  ByteArray convertToBytes(const Pixels::Pixel& pixel);
};}

#endif