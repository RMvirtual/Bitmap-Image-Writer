#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/common/byte-array/byte_array.h"

class BitmapReader
{
public:
  BitmapReader();
  BitmapPacket readBitmapPacket(std::string filePath);

private:
  BitmapPacket packet;

  void processIntoPacket(std::string filePath);
  void processIntoPacket(ByteArray& bytes);
  void processIntoFileHeader(ByteArray& bytes);
  void processIntoDibHeader(ByteArray& bytes);
  void processIntoPixelArray(ByteArray& bytes);  
};

#endif