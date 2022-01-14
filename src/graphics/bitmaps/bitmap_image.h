#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"

class BitmapImage
{
public:
  BitmapImage();

  static BitmapImage fromPacket(BitmapPacket headers);
  static BitmapImage fromFile(std::string filePath);

private:
  BitmapPacket packet;
};

#endif