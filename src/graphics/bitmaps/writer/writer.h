#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/containers/byte-array/byte_array.h"
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
  ByteArray convertToBytes(const Bitmaps::Packet& packet);
  ByteArray convertToBytes(const Bitmaps::FileHeader& header);
  ByteArray convertToBytes(const Bitmaps::DibHeader& header);
  ByteArray convertToBytes(const Bitmaps::PixelArray& pixelArray);
  ByteArray convertToBytes(const Bitmaps::Colours& pixelColours);

private:

};}

#endif