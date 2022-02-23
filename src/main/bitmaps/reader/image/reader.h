#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/main/bitmaps/formats/format/format.h"
#include "src/main/bitmaps/image/image.h"
#include "src/main/bitmaps/packet/packet.h"
#include "src/main/bitmaps/packet/headers/headers.h"
#include "src/main/bitmaps/reader/pixel-array/reader.h"
#include "src/main/containers/byte-array/byte_array.h"

namespace Bitmaps {
class ImageReader
{
public:
  ImageReader();
  Bitmaps::Image read(const std::string& filePath);

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