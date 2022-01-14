#include <fstream>

#include "src/common/byte-array/byte_array_builder.h"
#include "src/common/filesystem/filesystem.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapImage::BitmapImage()
{
  // Pass
}

BitmapImage BitmapImage::fromPacket(BitmapPacket packet)
{
  BitmapImage image;
  image.packet = packet;

  return image;
}

BitmapImage BitmapImage::fromFile(std::string filePath)
{
  BitmapReader reader {};
  BitmapPacket packet = reader.readBitmapPacket(filePath);
  
  return BitmapImage::fromPacket(packet);
}
