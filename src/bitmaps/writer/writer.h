#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/bitmaps/formats/colours.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/containers/byte-array/byte_array.h"

namespace Bitmaps {
class ByteWriter
{
public:
  ByteWriter();
  ByteArray write(const Bitmaps::Packet& packet);
  ByteArray write(const Bitmaps::FileHeader& header);
  ByteArray write(const Bitmaps::DibHeader& header);
  ByteArray write(const Bitmaps::PixelArray& pixelArray);
  ByteArray write(const Bitmaps::Colours& pixelColours);
};}

#endif