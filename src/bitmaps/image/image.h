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

  void writeToFile(std::string filePath);
  void fill(Colours colours);
  Colours defaultColours();
  int widthInPixels();
  int heightInPixels();

private:
  Packet packet;
  Format format;
};}

#endif