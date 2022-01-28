#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

namespace BitmapWriter {
class ImageWriter
{
public:
  ImageWriter();
  ByteArray convertToBytes(const BitmapPacket& packet);
  ByteArray convertToBytes(const BitmapHeaders::FileHeader& header);
  ByteArray convertToBytes(const BitmapHeaders::DibHeader& header);
  ByteArray convertToBytes(const Pixels::Array& pixelArray);
  ByteArray convertToBytes(Pixels::Colours& pixelColours);
};}

#endif