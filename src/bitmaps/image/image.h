#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include <string>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/formats/format.h"

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

private:
  Packet packet;
  Format format;
};}

#endif