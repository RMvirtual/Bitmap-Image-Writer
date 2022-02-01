#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/containers/byte-array/byte_array.h"
#include "src/bitmaps/reader/pixel-array/reader.h"
#include "src/bitmaps/formats/format.h"

namespace Bitmaps {
class ImageReader
{
public:
  ImageReader();
  Bitmaps::Packet read(const std::string& filePath);

private:
  Bitmaps::Packet packet;

  void processIntoPacket(const std::string& filePath);
  void processIntoPacket(const ByteArray& bytes);
  void processIntoFileHeader(const ByteArray& bytes);
  void processIntoDibHeader(const ByteArray& bytes);
  void processIntoPixelArray(const ByteArray& bytes);
  Bitmaps::Headers headers();
  Bitmaps::Format pixelArrayFormat();
  Bitmaps::PixelArrayReader pixelArrayReader();
};}

#endif