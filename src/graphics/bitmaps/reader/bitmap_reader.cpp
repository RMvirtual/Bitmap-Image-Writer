#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapPacket BitmapReader::getBitmapPacket(std::string filePath)
{
  BitmapHeaders::FileHeader fileHeader = BitmapReader::getBitmapFileHeader(
    filePath);
  
  BitmapHeaders::DibHeader dibHeader = BitmapReader::getBitmapDibHeader(
    filePath);
  
  Pixels::PixelArray pixelArray = BitmapReader::getPixelArray(filePath);

  BitmapPacket bitmapHeaders;
  
  bitmapHeaders.fileHeader = fileHeader;
  bitmapHeaders.dibHeader = dibHeader;
  bitmapHeaders.pixelArray = pixelArray;

  return bitmapHeaders;
}