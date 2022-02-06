#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include <string>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/formats/bitmap/format.h"
#include "src/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class Image
{
public:
  Image();
  Image(Format format);
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