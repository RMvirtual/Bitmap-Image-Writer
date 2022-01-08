#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/common/byte_array.h"

class BitmapReader
{
public:
  BitmapReader();
  BitmapPacket readBitmapPacket(std::string filePath);

private:
  BitmapPacket packet;

  BitmapHeaders::FileHeader getBitmapFileHeader(ByteArray bytes);
  BitmapHeaders::DibHeader getBitmapDibHeader(ByteArray bytes);
};

#endif