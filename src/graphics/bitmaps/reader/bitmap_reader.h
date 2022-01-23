#ifndef BITMAP_READER_H
#define BITMAP_READER_H

#include <string>

#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader_config.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"

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
  BitmapReader::PixelArrayReaderConfig pixelArrayConfig();
  BitmapReader::PixelArrayReader pixelArrayReader();  
};}

#endif