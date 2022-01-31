#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/reader/pixel-array/config.h"
#include "src/graphics/bitmaps/reader/pixel-array/reader.h"
#include "src/graphics/bitmaps/packet/formats/format.h"

namespace BitmapReader {
class ImageReader
{
public:
  ImageReader();
  BitmapPacket readBitmapPacket(const std::string& filePath);

private:
  BitmapPacket packet;

  void processIntoPacket(const std::string& filePath);
  void processIntoPacket(const ByteArray& bytes);
  void processIntoFileHeader(const ByteArray& bytes);
  void processIntoDibHeader(const ByteArray& bytes);
  void processIntoPixelArray(const ByteArray& bytes);
  BitmapHeaders::Headers packetToHeaders();
  BitmapReader::PixelArrayConfig pixelArrayConfig();
  BitmapReader::PixelArrayReader pixelArrayReader();

};}

#endif