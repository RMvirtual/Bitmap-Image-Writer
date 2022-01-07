#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapPacket BitmapReader::getBitmapPacket(std::string filePath)
{
  BitmapPacket bitmapHeaders;
  
  bitmapHeaders.fileHeader = BitmapReader::getBitmapFileHeader(filePath);
  bitmapHeaders.dibHeader = BitmapReader::getBitmapDibHeader(filePath);
  bitmapHeaders.pixelArray = BitmapReader::getPixelArray(filePath);

  return bitmapHeaders;
}