#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include <string>

#include "src/main/bitmaps/packet/packet.h"
#include "src/main/bitmaps/formats/format/format.h"
#include "src/main/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class Image
{
public:
  Image();
  Image(Format format);
  Image(Packet packet);
  ~Image();

  void fill(Colours colours);
  int widthInPixels() const;
  int heightInPixels() const;
  Colours defaultColours() const;
  FileHeader fileHeader() const;
  DibHeader dibHeader() const;
  PixelArray pixelArray() const;

private:
  Packet packet;
  Format format;
};}

#endif