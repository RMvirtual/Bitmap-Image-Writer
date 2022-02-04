#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/containers/byte-array/byte_array.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/formats/colours.h"

namespace Bitmaps {
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